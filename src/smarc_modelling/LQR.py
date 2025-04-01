import scipy.linalg 
import numpy as np
import casadi as ca


# Add the LQR below
class LQR:
    def __init__(self, dynamics, Ts):
        self.P = 0
        self.Ts = Ts
        self.dynamics = dynamics


    def create_linearized_dynamics(self, nx: int, nu: int):
        """
        Method to obtain the system jacobians.

        Parameters:
        nx: rows of x vector
        nu: rows of u vector
        
        Returns:
        A (ca.function): State Jacobian
        B (ca.Function): Control Jacobian
        """
        x_sym = ca.MX.sym('x', nx, 1)
        u_sym = ca.MX.sym('u', nu, 1)
        
        # Create Casadi functions to calculate jacobian
        # self.dfdx = ca.Function('dfdx', [x_sym, u_sym], [ca.jacobian(self.dynamics(x_sym, u_sym), x_sym)])
        # self.dfdu = ca.Function('dfdu', [x_sym, u_sym], [ca.jacobian(self.dynamics(x_sym, u_sym), u_sym)])
        # print(self.dfdx)
        # A_d_sym, Bd_sym = self.continuous_to_discrete(self.Ac_sym, self.Bc_sym, dt = 0.01)

        self.A = ca.Function('Ac', [x_sym, u_sym], [ca.jacobian(self.dynamics(x_sym, u_sym), x_sym)])
        self.B = ca.Function('Bc', [x_sym, u_sym], [ca.jacobian(self.dynamics(x_sym, u_sym), u_sym)])
        
    def continuous_dynamics(self, x_lin, u_lin):
        """
        Method to obtain the continuous-time linearized dynamics.

        Parameters:
        x_lin (np.array): State to linearize around
        u_lin (np.array): Control to linearize around
        
        Returns:
        Ac (ca.function): Continuous-time state matrix
        Bc (ca.Function): Continuous-time control matrix
        """
        self.Ac = self.A(x_lin, u_lin)
        self.Bc = self.B(x_lin, u_lin)
       
    def continuous_to_discrete(self, dt):
        """
        Convert continuous-time system matrices (A, B) to discrete-time (A_d, B_d) using zero-order hold.
        
        Parameters:
        A (ca.MX): Continuous-time state matrix
        B (ca.MX): Continuous-time input matrix
        dt (float): Sampling time
        
        Returns:
        A_d (ca.MX): Discrete-time state matrix
        B_d (ca.MX): Discrete-time input matrix
        """
        # Convert to numpy matrices (Problem with casadi plugin)
        A = np.array(self.Ac)
        B = np.array(self.Bc)

        #print(scipy.linalg.det(A))
        # Discretize the A matrix (A_d = exp(A * dt))
        self.Ad = scipy.linalg.expm(A * dt)

        I = np.eye(A.shape[0])  # Identity matrix of the same size as A

        # Discretize B using the trapezoidal rule (more accurate than Euler method)
        #B_d = scipy.integrate.quad_vec(lambda x: scipy.linalg.expm(A * x) @ B, 0, self.Ts)
        #B_d = scipy.integrate.quad(A_d @ B, dx=dt)
        Ad_inv = np.linalg.inv(self.Ad)
        #B_d = np.dot(Ad_inv * (A_d + I), B)
        self.Bd = np.dot(np.linalg.norm(Ad_inv) * (self.Ad + I), B)
        print(np.linalg.norm(Ad_inv))
    
    def continuous_to_discrete_appr(self, A, B, dt):
        """
        Approximate continuous-time system matrices (A, B) to discrete-time (A_d, B_d).
        
        Parameters:
        A (ca.MX): Continuous-time state matrix
        B (ca.MX): Continuous-time input matrix
        dt (float): Sampling time
        
        Returns:
        A_d (ca.MX): Discrete-time state matrix
        B_d (ca.MX): Discrete-time input matrix
        """
        # Convert to numpy matrices (Problem with casadi plugin)
        A = np.array(A)
        B = np.array(B)

        #print(scipy.linalg.det(A))
        # Discretize the A matrix (A_d = exp(A * dt))
        A_d = scipy.linalg.expm(A * dt)

        # Trapezoidal rule for B_d: B_d = dt * (exp(A*dt) + I) / 2 * B
        I = np.eye(A.shape[0])  # Identity matrix of the same size as A

        # Discretize B approximization
        B_d = dt*B

        return A_d, B_d

    def compute_lqr_gain(self):
        # State weight matrix
        Q_diag = np.ones(12)
        Q_diag[ 0:3 ] = 1
        Q_diag[ 3:6 ] = 1
        Q_diag[ 6:9] = 1
        Q_diag[9:] = 1
        Q = np.diag(Q_diag)


        # Control rate of change weight matrix - control inputs as [x_vbs, x_lcg, delta_s, delta_r, rpm1, rpm2]
        R_diag = np.ones(6)
        R_diag[ :2] = 1e-2
        R_diag[2:4] = 1/50
        R_diag[4: ] = 1e-6
        R = np.diag(R_diag)

        
        P = scipy.linalg.solve_discrete_are(self.Ad, self.Bd, Q, R)
        L = np.linalg.inv(R + self.Bd.T @ P @ self.Bd) @ self.Bd.T @ P @ self.Ad

        return L

    def solve(self, x, x_lin, u_lin):
        self.create_linearized_dynamics(x_lin.shape[0], u_lin.shape[0])    # Get the symbolic Jacobians that describe the A and B matrices
        self.continuous_dynamics(x_lin, u_lin)   # Create matrix A and B in continuous time
        self.continuous_to_discrete(self.Ts)          # Discretize the continuous time matrices
        L = self.compute_lqr_gain()              # Calculate the feedback gain
        u = -L @ x

        x_next = self.Ad @ x + self.Bd @ u
        #x = Ad @ (x-x_ref[i,:]) + Bd @ (u-u_ref[i,:]) + np.array(dynamics_function(x_ref[i,:], u_ref[i,:])).flatten()

        return x_next, u
    
    def x_error(self, x, ref):
        """
        Calculates the state error.
        
        :param x: State vector
        :param ref: Reference vector
        :return: error vector
        """
        # Extract the reference quaternion
        q_ref1 = ref[3]
        q_ref2 = ref[4]
        q_ref3 = ref[5]
        q_ref0 = ca.sqrt(1 - q_ref1**2 - q_ref2**2 - q_ref3**2)

        q_ref = ca.vertcat(q_ref0, q_ref1, q_ref2, q_ref3)

        # Extract current quaternion
        q1 = x[3]
        q2 = x[4]
        q3 = x[5]
        q0 = ca.sqrt(1 - q1**2 - q2**2 - q3**2)

        q = ca.vertcat(q0, q1, q2, q3)

        # Since unit quaternion, quaternion inverse is equal to its conjugate
        q_conj = ca.vertcat(q[0], -q[1], -q[2], -q[3])
        q = q_conj/ca.norm_2(q)
        
        # q_error = q_ref @ q^-1
        q_w = q_ref[0] * q[0] - q_ref[1] * q[1] - q_ref[2] * q[2] - q_ref[3] * q[3]
        q_x = q_ref[0] * q[1] + q_ref[1] * q[0] + q_ref[2] * q[3] - q_ref[3] * q[2]
        q_y = q_ref[0] * q[2] - q_ref[1] * q[3] + q_ref[2] * q[0] + q_ref[3] * q[1]
        q_z = q_ref[0] * q[3] + q_ref[1] * q[2] - q_ref[2] * q[1] + q_ref[3] * q[0]

        q_error = ca.vertcat(q_w, q_x, q_y, q_z)

        pos_error = x[:3] - ref[:3] #+ np.array([(np.random.random()-0.5)/5,(np.random.random()-0.5)/5, (np.random.random()-0.5)/5])
        vel_error = x[7:13] - ref[7:13]
        u_error   = x[13:19] - ref[13:19]
        
        x_error = ca.vertcat(pos_error, q_error, vel_error, u_error)


        return x_error

