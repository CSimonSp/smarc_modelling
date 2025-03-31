import scipy.linalg 
import numpy as np
import casadi as ca


# Add the LQR below
class LQR:
    def __init__(self, dynamics, Ts):
        self.P = 0
        self.Ts = Ts
        self.dynamics = dynamics


    def create_linearized_dynamics(self, x_lin, u_lin):
        """
        Function to create continuous-time linearized dynamics.
        """
        nx = np.size(x_lin, 0)
        nu = np.size(u_lin, 0)    
        x_sym = ca.MX.sym('x', nx, 1)
        u_sym = ca.MX.sym('u', nu, 1)
        
        # Create Casadi functions to calculate jacobian
        # self.dfdx = ca.Function('dfdx', [x_sym, u_sym], [ca.jacobian(self.dynamics(x_sym, u_sym), x_sym)])
        # self.dfdu = ca.Function('dfdu', [x_sym, u_sym], [ca.jacobian(self.dynamics(x_sym, u_sym), u_sym)])
        # print(self.dfdx)
        # A_d_sym, Bd_sym = self.continuous_to_discrete(self.Ac_sym, self.Bc_sym, dt = 0.01)

        self.Ac = ca.Function('Ac', [x_sym, u_sym], [ca.jacobian(self.dynamics(x_sym, u_sym), x_sym)])
        self.Bc = ca.Function('Bc', [x_sym, u_sym], [ca.jacobian(self.dynamics(x_sym, u_sym), u_sym)])

        return self.Ac, self.Bc
        

    def continuous_to_discrete(self, A, B, dt):
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
        A = np.array(A)
        B = np.array(B)

        #print(scipy.linalg.det(A))
        # Discretize the A matrix (A_d = exp(A * dt))
        A_d = scipy.linalg.expm(A * dt)

        # Trapezoidal rule for B_d: B_d = dt * (exp(A*dt) + I) / 2 * B
        I = np.eye(A.shape[0])  # Identity matrix of the same size as A

        # Discretize B using the trapezoidal rule (more accurate than Euler method)
        #B_d = scipy.integrate.quad_vec(lambda x: scipy.linalg.expm(A * x) @ B, 0, self.Ts)
        #B_d = scipy.integrate.quad(A_d @ B, dx=dt)
        Ad_inv = np.linalg.inv(A_d)
        #B_d2 = np.dot(Ad_inv * (A_d + I), B)
        B_d2 = np.dot(0.5 * (A_d + I), B)
        
        return A_d, B_d2
    
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

    def compute_lqr_gain(self, A, B):
        # State weight matrix
        Q_diag = np.ones(12)
        Q_diag[ 0:3 ] = 100
        Q_diag[ 3:6 ] = 10
        Q_diag[ 6:9] = 1
        Q_diag[9:] = 1
        Q = np.diag(Q_diag)


        # Control rate of change weight matrix - control inputs as [x_vbs, x_lcg, delta_s, delta_r, rpm1, rpm2]
        R_diag = np.ones(6)
        R_diag[ :2] = 1e-2
        R_diag[2:4] = 1/50
        R_diag[4: ] = 1e-6
        R = np.diag(R_diag)

        P = scipy.linalg.solve_discrete_are(A, B, Q, R)
        self.L = np.linalg.inv(R + B.T @ P @ B) @ B.T @ P @ A
        return self.L

    def solve(self, x):
        Q = np.eye(19)
        R = np.eye(6)
        A, B = self.create_linearized_dynamics(x, u)
        self.compute_lqr_gain(A, B, Q, R)
        u = -self.L @ x

        x_dot = A @ x + B @ u
        x += x_dot * self.Ts  # Update the state (Euler method)

        return u
    
