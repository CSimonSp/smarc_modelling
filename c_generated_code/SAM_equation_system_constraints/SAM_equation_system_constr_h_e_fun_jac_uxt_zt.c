/* This file was automatically generated by CasADi 3.6.7.
 *  It consists of: 
 *   1) content generated by CasADi runtime: not copyrighted
 *   2) template code copied from CasADi source: permissively licensed (MIT-0)
 *   3) user code: owned by the user
 *
 */
#ifdef __cplusplus
extern "C" {
#endif

/* How to prefix internal symbols */
#ifdef CASADI_CODEGEN_PREFIX
  #define CASADI_NAMESPACE_CONCAT(NS, ID) _CASADI_NAMESPACE_CONCAT(NS, ID)
  #define _CASADI_NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) CASADI_NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else
  #define CASADI_PREFIX(ID) SAM_equation_system_constr_h_e_fun_jac_uxt_zt_ ## ID
#endif

#include <math.h>

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int int
#endif

/* Add prefix to internal symbols */
#define casadi_c0 CASADI_PREFIX(c0)
#define casadi_clear CASADI_PREFIX(clear)
#define casadi_copy CASADI_PREFIX(copy)
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_fill CASADI_PREFIX(fill)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_s2 CASADI_PREFIX(s2)
#define casadi_s3 CASADI_PREFIX(s3)
#define casadi_s4 CASADI_PREFIX(s4)
#define casadi_s5 CASADI_PREFIX(s5)
#define casadi_sq CASADI_PREFIX(sq)

/* Symbol visibility in DLLs */
#ifndef CASADI_SYMBOL_EXPORT
  #if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
    #if defined(STATIC_LINKED)
      #define CASADI_SYMBOL_EXPORT
    #else
      #define CASADI_SYMBOL_EXPORT __declspec(dllexport)
    #endif
  #elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
    #define CASADI_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define CASADI_SYMBOL_EXPORT
  #endif
#endif

void casadi_copy(const casadi_real* x, casadi_int n, casadi_real* y) {
  casadi_int i;
  if (y) {
    if (x) {
      for (i=0; i<n; ++i) *y++ = *x++;
    } else {
      for (i=0; i<n; ++i) *y++ = 0.;
    }
  }
}

void casadi_clear(casadi_real* x, casadi_int n) {
  casadi_int i;
  if (x) {
    for (i=0; i<n; ++i) *x++ = 0;
  }
}

casadi_real casadi_sq(casadi_real x) { return x*x;}

void casadi_fill(casadi_real* x, casadi_int n, casadi_real alpha) {
  casadi_int i;
  if (x) {
    for (i=0; i<n; ++i) *x++ = alpha;
  }
}

static const casadi_int casadi_s0[6] = {0, 1, 2, 3, 8, 13};
static const casadi_int casadi_s1[23] = {19, 1, 0, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
static const casadi_int casadi_s2[3] = {0, 0, 0};
static const casadi_int casadi_s3[10] = {6, 1, 0, 6, 0, 1, 2, 3, 4, 5};
static const casadi_int casadi_s4[27] = {19, 6, 0, 1, 2, 3, 8, 13, 18, 0, 1, 2, 0, 3, 4, 5, 6, 1, 3, 4, 5, 6, 2, 3, 4, 5, 6};
static const casadi_int casadi_s5[3] = {6, 0, 0};

static const casadi_real casadi_c0[3] = {1., 0., 0.};

/* SAM_equation_system_constr_h_e_fun_jac_uxt_zt:(i0[19],i1[],i2[],i3[])->(o0[6],o1[19x6,18nz],o2[6x0]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_int i, j, k;
  casadi_real *rr, *ss, *tt;
  const casadi_int *cii;
  const casadi_real *cr, *cs;
  casadi_real *w0=w+3, w1, w2, w3, *w4=w+25, *w5=w+28, w6, w7, w8, w9, w10, w11, w12, w13, w14, w15, w16, w17, w18, w19, w20, w21, w22, *w23=w+48, *w24=w+51, *w25=w+54, *w26=w+57, *w27=w+66, *w28=w+75, *w29=w+93, w31, w32, w33, w34, w35, w36, w37, w38, w39, w40, w41, w42, w43, *w44=w+112, w45;
  /* #0: @0 = input[0][0] */
  casadi_copy(arg[0], 19, w0);
  /* #1: @1 = @0[0] */
  for (rr=(&w1), ss=w0+0; ss!=w0+1; ss+=1) *rr++ = *ss;
  /* #2: output[0][0] = @1 */
  if (res[0]) res[0][0] = w1;
  /* #3: @2 = @0[1] */
  for (rr=(&w2), ss=w0+1; ss!=w0+2; ss+=1) *rr++ = *ss;
  /* #4: output[0][1] = @2 */
  if (res[0]) res[0][1] = w2;
  /* #5: @3 = @0[2] */
  for (rr=(&w3), ss=w0+2; ss!=w0+3; ss+=1) *rr++ = *ss;
  /* #6: output[0][2] = @3 */
  if (res[0]) res[0][2] = w3;
  /* #7: @4 = vertcat(@1, @2, @3) */
  rr=w4;
  *rr++ = w1;
  *rr++ = w2;
  *rr++ = w3;
  /* #8: @1 = 0.655 */
  w1 = 6.5500000000000003e-01;
  /* #9: @5 = zeros(3x1) */
  casadi_clear(w5, 3);
  /* #10: @2 = 1 */
  w2 = 1.;
  /* #11: @3 = @0[5] */
  for (rr=(&w3), ss=w0+5; ss!=w0+6; ss+=1) *rr++ = *ss;
  /* #12: @6 = @0[3] */
  for (rr=(&w6), ss=w0+3; ss!=w0+4; ss+=1) *rr++ = *ss;
  /* #13: @7 = sq(@6) */
  w7 = casadi_sq( w6 );
  /* #14: @8 = @0[4] */
  for (rr=(&w8), ss=w0+4; ss!=w0+5; ss+=1) *rr++ = *ss;
  /* #15: @9 = sq(@8) */
  w9 = casadi_sq( w8 );
  /* #16: @7 = (@7+@9) */
  w7 += w9;
  /* #17: @9 = sq(@3) */
  w9 = casadi_sq( w3 );
  /* #18: @7 = (@7+@9) */
  w7 += w9;
  /* #19: @9 = @0[6] */
  for (rr=(&w9), ss=w0+6; ss!=w0+7; ss+=1) *rr++ = *ss;
  /* #20: @10 = sq(@9) */
  w10 = casadi_sq( w9 );
  /* #21: @7 = (@7+@10) */
  w7 += w10;
  /* #22: @7 = sqrt(@7) */
  w7 = sqrt( w7 );
  /* #23: @10 = (@3/@7) */
  w10  = (w3/w7);
  /* #24: @11 = sq(@10) */
  w11 = casadi_sq( w10 );
  /* #25: @12 = (@9/@7) */
  w12  = (w9/w7);
  /* #26: @13 = sq(@12) */
  w13 = casadi_sq( w12 );
  /* #27: @14 = (@11+@13) */
  w14  = (w11+w13);
  /* #28: @14 = (2.*@14) */
  w14 = (2.* w14 );
  /* #29: @14 = (@2-@14) */
  w14  = (w2-w14);
  /* #30: @15 = (@8/@7) */
  w15  = (w8/w7);
  /* #31: @16 = (@15*@10) */
  w16  = (w15*w10);
  /* #32: @17 = (@6/@7) */
  w17  = (w6/w7);
  /* #33: @18 = (@17*@12) */
  w18  = (w17*w12);
  /* #34: @19 = (@16-@18) */
  w19  = (w16-w18);
  /* #35: @19 = (2.*@19) */
  w19 = (2.* w19 );
  /* #36: @20 = (@15*@12) */
  w20  = (w15*w12);
  /* #37: @21 = (@17*@10) */
  w21  = (w17*w10);
  /* #38: @22 = (@20+@21) */
  w22  = (w20+w21);
  /* #39: @22 = (2.*@22) */
  w22 = (2.* w22 );
  /* #40: @23 = horzcat(@14, @19, @22) */
  rr=w23;
  *rr++ = w14;
  *rr++ = w19;
  *rr++ = w22;
  /* #41: @23 = @23' */
  /* #42: @16 = (@16+@18) */
  w16 += w18;
  /* #43: @16 = (2.*@16) */
  w16 = (2.* w16 );
  /* #44: @18 = sq(@15) */
  w18 = casadi_sq( w15 );
  /* #45: @13 = (@18+@13) */
  w13  = (w18+w13);
  /* #46: @13 = (2.*@13) */
  w13 = (2.* w13 );
  /* #47: @13 = (@2-@13) */
  w13  = (w2-w13);
  /* #48: @14 = (@10*@12) */
  w14  = (w10*w12);
  /* #49: @19 = (@17*@15) */
  w19  = (w17*w15);
  /* #50: @22 = (@14-@19) */
  w22  = (w14-w19);
  /* #51: @22 = (2.*@22) */
  w22 = (2.* w22 );
  /* #52: @24 = horzcat(@16, @13, @22) */
  rr=w24;
  *rr++ = w16;
  *rr++ = w13;
  *rr++ = w22;
  /* #53: @24 = @24' */
  /* #54: @20 = (@20-@21) */
  w20 -= w21;
  /* #55: @20 = (2.*@20) */
  w20 = (2.* w20 );
  /* #56: @14 = (@14+@19) */
  w14 += w19;
  /* #57: @14 = (2.*@14) */
  w14 = (2.* w14 );
  /* #58: @18 = (@18+@11) */
  w18 += w11;
  /* #59: @18 = (2.*@18) */
  w18 = (2.* w18 );
  /* #60: @2 = (@2-@18) */
  w2 -= w18;
  /* #61: @25 = horzcat(@20, @14, @2) */
  rr=w25;
  *rr++ = w20;
  *rr++ = w14;
  *rr++ = w2;
  /* #62: @25 = @25' */
  /* #63: @26 = horzcat(@23, @24, @25) */
  rr=w26;
  for (i=0, cs=w23; i<3; ++i) *rr++ = *cs++;
  for (i=0, cs=w24; i<3; ++i) *rr++ = *cs++;
  for (i=0, cs=w25; i<3; ++i) *rr++ = *cs++;
  /* #64: @27 = @26' */
  for (i=0, rr=w27, cs=w26; i<3; ++i) for (j=0; j<3; ++j) rr[i+j*3] = *cs++;
  /* #65: @23 = [1, 0, 0] */
  casadi_copy(casadi_c0, 3, w23);
  /* #66: @24 = mac(@27,@23,@5) */
  casadi_copy(w5, 3, w24);
  for (i=0, rr=w24; i<1; ++i) for (j=0; j<3; ++j, ++rr) for (k=0, ss=w27+j, tt=w23+i*3; k<3; ++k) *rr += ss[k*3]**tt++;
  /* #67: @20 = @24[0] */
  for (rr=(&w20), ss=w24+0; ss!=w24+1; ss+=1) *rr++ = *ss;
  /* #68: @14 = sq(@20) */
  w14 = casadi_sq( w20 );
  /* #69: @2 = @24[1] */
  for (rr=(&w2), ss=w24+1; ss!=w24+2; ss+=1) *rr++ = *ss;
  /* #70: @18 = sq(@2) */
  w18 = casadi_sq( w2 );
  /* #71: @14 = (@14+@18) */
  w14 += w18;
  /* #72: @18 = @24[2] */
  for (rr=(&w18), ss=w24+2; ss!=w24+3; ss+=1) *rr++ = *ss;
  /* #73: @11 = sq(@18) */
  w11 = casadi_sq( w18 );
  /* #74: @14 = (@14+@11) */
  w14 += w11;
  /* #75: @14 = sqrt(@14) */
  w14 = sqrt( w14 );
  /* #76: @24 = (@24/@14) */
  for (i=0, rr=w24; i<3; ++i) (*rr++) /= w14;
  /* #77: @25 = (@1*@24) */
  for (i=0, rr=w25, cs=w24; i<3; ++i) (*rr++)  = (w1*(*cs++));
  /* #78: @4 = (@4+@25) */
  for (i=0, rr=w4, cs=w25; i<3; ++i) (*rr++) += (*cs++);
  /* #79: @11 = @4[0] */
  for (rr=(&w11), ss=w4+0; ss!=w4+1; ss+=1) *rr++ = *ss;
  /* #80: output[0][3] = @11 */
  if (res[0]) res[0][3] = w11;
  /* #81: @11 = @4[1] */
  for (rr=(&w11), ss=w4+1; ss!=w4+2; ss+=1) *rr++ = *ss;
  /* #82: output[0][4] = @11 */
  if (res[0]) res[0][4] = w11;
  /* #83: @11 = @4[2] */
  for (rr=(&w11), ss=w4+2; ss!=w4+3; ss+=1) *rr++ = *ss;
  /* #84: output[0][5] = @11 */
  if (res[0]) res[0][5] = w11;
  /* #85: @28 = zeros(19x6,18nz) */
  casadi_clear(w28, 18);
  /* #86: @29 = ones(6x1) */
  casadi_fill(w29, 6, 1.);
  /* #87: (@28[0, 1, 2, 3, 8, 13] = @29) */
  for (cii=casadi_s0, rr=w28, ss=w29; cii!=casadi_s0+6; ++cii, ++ss) rr[*cii] = *ss;
  /* #88: @30 = 00 */
  /* #89: @11 = (2.*@12) */
  w11 = (2.* w12 );
  /* #90: @19 = (@12/@7) */
  w19  = (w12/w7);
  /* #91: @6 = (2.*@6) */
  w6 = (2.* w6 );
  /* #92: @21 = (2.*@7) */
  w21 = (2.* w7 );
  /* #93: @6 = (@6/@21) */
  w6 /= w21;
  /* #94: @16 = (@19*@6) */
  w16  = (w19*w6);
  /* #95: @13 = (@11*@16) */
  w13  = (w11*w16);
  /* #96: @13 = (-@13) */
  w13 = (- w13 );
  /* #97: @22 = (2.*@10) */
  w22 = (2.* w10 );
  /* #98: @31 = (@10/@7) */
  w31  = (w10/w7);
  /* #99: @32 = (@31*@6) */
  w32  = (w31*w6);
  /* #100: @33 = (@22*@32) */
  w33  = (w22*w32);
  /* #101: @34 = (@13-@33) */
  w34  = (w13-w33);
  /* #102: @34 = (2.*@34) */
  w34 = (2.* w34 );
  /* #103: @34 = (-@34) */
  w34 = (- w34 );
  /* #104: @35 = (@15*@32) */
  w35  = (w15*w32);
  /* #105: @35 = (-@35) */
  w35 = (- w35 );
  /* #106: @36 = (@15/@7) */
  w36  = (w15/w7);
  /* #107: @37 = (@36*@6) */
  w37  = (w36*w6);
  /* #108: @38 = (@10*@37) */
  w38  = (w10*w37);
  /* #109: @35 = (@35-@38) */
  w35 -= w38;
  /* #110: @38 = (1./@7) */
  w38 = (1./ w7 );
  /* #111: @7 = (@17/@7) */
  w7  = (w17/w7);
  /* #112: @6 = (@7*@6) */
  w6  = (w7*w6);
  /* #113: @6 = (@38-@6) */
  w6  = (w38-w6);
  /* #114: @39 = (@12*@6) */
  w39  = (w12*w6);
  /* #115: @40 = (@17*@16) */
  w40  = (w17*w16);
  /* #116: @39 = (@39-@40) */
  w39 -= w40;
  /* #117: @40 = (@35-@39) */
  w40  = (w35-w39);
  /* #118: @40 = (2.*@40) */
  w40 = (2.* w40 );
  /* #119: @41 = (@15*@16) */
  w41  = (w15*w16);
  /* #120: @41 = (-@41) */
  w41 = (- w41 );
  /* #121: @42 = (@12*@37) */
  w42  = (w12*w37);
  /* #122: @41 = (@41-@42) */
  w41 -= w42;
  /* #123: @42 = (@10*@6) */
  w42  = (w10*w6);
  /* #124: @43 = (@17*@32) */
  w43  = (w17*w32);
  /* #125: @42 = (@42-@43) */
  w42 -= w43;
  /* #126: @43 = (@41+@42) */
  w43  = (w41+w42);
  /* #127: @43 = (2.*@43) */
  w43 = (2.* w43 );
  /* #128: @4 = horzcat(@34, @40, @43) */
  rr=w4;
  *rr++ = w34;
  *rr++ = w40;
  *rr++ = w43;
  /* #129: @4 = @4' */
  /* #130: @35 = (@35+@39) */
  w35 += w39;
  /* #131: @35 = (2.*@35) */
  w35 = (2.* w35 );
  /* #132: @39 = (2.*@15) */
  w39 = (2.* w15 );
  /* #133: @34 = (@39*@37) */
  w34  = (w39*w37);
  /* #134: @13 = (@13-@34) */
  w13 -= w34;
  /* #135: @13 = (2.*@13) */
  w13 = (2.* w13 );
  /* #136: @13 = (-@13) */
  w13 = (- w13 );
  /* #137: @16 = (@10*@16) */
  w16  = (w10*w16);
  /* #138: @16 = (-@16) */
  w16 = (- w16 );
  /* #139: @32 = (@12*@32) */
  w32  = (w12*w32);
  /* #140: @16 = (@16-@32) */
  w16 -= w32;
  /* #141: @6 = (@15*@6) */
  w6  = (w15*w6);
  /* #142: @37 = (@17*@37) */
  w37  = (w17*w37);
  /* #143: @6 = (@6-@37) */
  w6 -= w37;
  /* #144: @37 = (@16-@6) */
  w37  = (w16-w6);
  /* #145: @37 = (2.*@37) */
  w37 = (2.* w37 );
  /* #146: @25 = horzcat(@35, @13, @37) */
  rr=w25;
  *rr++ = w35;
  *rr++ = w13;
  *rr++ = w37;
  /* #147: @25 = @25' */
  /* #148: @41 = (@41-@42) */
  w41 -= w42;
  /* #149: @41 = (2.*@41) */
  w41 = (2.* w41 );
  /* #150: @16 = (@16+@6) */
  w16 += w6;
  /* #151: @16 = (2.*@16) */
  w16 = (2.* w16 );
  /* #152: @33 = (-@33) */
  w33 = (- w33 );
  /* #153: @33 = (@33-@34) */
  w33 -= w34;
  /* #154: @33 = (2.*@33) */
  w33 = (2.* w33 );
  /* #155: @33 = (-@33) */
  w33 = (- w33 );
  /* #156: @44 = horzcat(@41, @16, @33) */
  rr=w44;
  *rr++ = w41;
  *rr++ = w16;
  *rr++ = w33;
  /* #157: @44 = @44' */
  /* #158: @27 = horzcat(@4, @25, @44) */
  rr=w27;
  for (i=0, cs=w4; i<3; ++i) *rr++ = *cs++;
  for (i=0, cs=w25; i<3; ++i) *rr++ = *cs++;
  for (i=0, cs=w44; i<3; ++i) *rr++ = *cs++;
  /* #159: @26 = @27' */
  for (i=0, rr=w26, cs=w27; i<3; ++i) for (j=0; j<3; ++j) rr[i+j*3] = *cs++;
  /* #160: @4 = mac(@26,@23,@5) */
  casadi_copy(w5, 3, w4);
  for (i=0, rr=w4; i<1; ++i) for (j=0; j<3; ++j, ++rr) for (k=0, ss=w26+j, tt=w23+i*3; k<3; ++k) *rr += ss[k*3]**tt++;
  /* #161: @25 = (@4/@14) */
  for (i=0, rr=w25, cr=w4; i<3; ++i) (*rr++)  = ((*cr++)/w14);
  /* #162: @24 = (@24/@14) */
  for (i=0, rr=w24; i<3; ++i) (*rr++) /= w14;
  /* #163: @20 = (2.*@20) */
  w20 = (2.* w20 );
  /* #164: @41 = @4[0] */
  for (rr=(&w41), ss=w4+0; ss!=w4+1; ss+=1) *rr++ = *ss;
  /* #165: @41 = (@20*@41) */
  w41  = (w20*w41);
  /* #166: @2 = (2.*@2) */
  w2 = (2.* w2 );
  /* #167: @16 = @4[1] */
  for (rr=(&w16), ss=w4+1; ss!=w4+2; ss+=1) *rr++ = *ss;
  /* #168: @16 = (@2*@16) */
  w16  = (w2*w16);
  /* #169: @41 = (@41+@16) */
  w41 += w16;
  /* #170: @18 = (2.*@18) */
  w18 = (2.* w18 );
  /* #171: @16 = @4[2] */
  for (rr=(&w16), ss=w4+2; ss!=w4+3; ss+=1) *rr++ = *ss;
  /* #172: @16 = (@18*@16) */
  w16  = (w18*w16);
  /* #173: @41 = (@41+@16) */
  w41 += w16;
  /* #174: @16 = (2.*@14) */
  w16 = (2.* w14 );
  /* #175: @41 = (@41/@16) */
  w41 /= w16;
  /* #176: @4 = (@24*@41) */
  for (i=0, rr=w4, cr=w24; i<3; ++i) (*rr++)  = ((*cr++)*w41);
  /* #177: @25 = (@25-@4) */
  for (i=0, rr=w25, cs=w4; i<3; ++i) (*rr++) -= (*cs++);
  /* #178: @25 = (@1*@25) */
  for (i=0, rr=w25, cs=w25; i<3; ++i) (*rr++)  = (w1*(*cs++));
  /* #179: @41 = @25[0] */
  for (rr=(&w41), ss=w25+0; ss!=w25+1; ss+=1) *rr++ = *ss;
  /* #180: @33 = @25[1] */
  for (rr=(&w33), ss=w25+1; ss!=w25+2; ss+=1) *rr++ = *ss;
  /* #181: @34 = @25[2] */
  for (rr=(&w34), ss=w25+2; ss!=w25+3; ss+=1) *rr++ = *ss;
  /* #182: @25 = vertcat(@30, @30, @30, @41, @33, @34) */
  rr=w25;
  *rr++ = w41;
  *rr++ = w33;
  *rr++ = w34;
  /* #183: @4 = @25[:3] */
  for (rr=w4, ss=w25+0; ss!=w25+3; ss+=1) *rr++ = *ss;
  /* #184: (@28[4:19:5] = @4) */
  for (rr=w28+4, ss=w4; rr!=w28+19; rr+=5) *rr = *ss++;
  /* #185: @8 = (2.*@8) */
  w8 = (2.* w8 );
  /* #186: @8 = (@8/@21) */
  w8 /= w21;
  /* #187: @41 = (@19*@8) */
  w41  = (w19*w8);
  /* #188: @33 = (@11*@41) */
  w33  = (w11*w41);
  /* #189: @34 = (-@33) */
  w34 = (- w33 );
  /* #190: @6 = (@31*@8) */
  w6  = (w31*w8);
  /* #191: @42 = (@22*@6) */
  w42  = (w22*w6);
  /* #192: @34 = (@34-@42) */
  w34 -= w42;
  /* #193: @34 = (2.*@34) */
  w34 = (2.* w34 );
  /* #194: @34 = (-@34) */
  w34 = (- w34 );
  /* #195: @35 = (@36*@8) */
  w35  = (w36*w8);
  /* #196: @35 = (@38-@35) */
  w35  = (w38-w35);
  /* #197: @13 = (@10*@35) */
  w13  = (w10*w35);
  /* #198: @37 = (@15*@6) */
  w37  = (w15*w6);
  /* #199: @13 = (@13-@37) */
  w13 -= w37;
  /* #200: @37 = (@17*@41) */
  w37  = (w17*w41);
  /* #201: @37 = (-@37) */
  w37 = (- w37 );
  /* #202: @8 = (@7*@8) */
  w8  = (w7*w8);
  /* #203: @32 = (@12*@8) */
  w32  = (w12*w8);
  /* #204: @37 = (@37-@32) */
  w37 -= w32;
  /* #205: @32 = (@13-@37) */
  w32  = (w13-w37);
  /* #206: @32 = (2.*@32) */
  w32 = (2.* w32 );
  /* #207: @40 = (@12*@35) */
  w40  = (w12*w35);
  /* #208: @43 = (@15*@41) */
  w43  = (w15*w41);
  /* #209: @40 = (@40-@43) */
  w40 -= w43;
  /* #210: @43 = (@17*@6) */
  w43  = (w17*w6);
  /* #211: @43 = (-@43) */
  w43 = (- w43 );
  /* #212: @45 = (@10*@8) */
  w45  = (w10*w8);
  /* #213: @43 = (@43-@45) */
  w43 -= w45;
  /* #214: @45 = (@40+@43) */
  w45  = (w40+w43);
  /* #215: @45 = (2.*@45) */
  w45 = (2.* w45 );
  /* #216: @4 = horzcat(@34, @32, @45) */
  rr=w4;
  *rr++ = w34;
  *rr++ = w32;
  *rr++ = w45;
  /* #217: @4 = @4' */
  /* #218: @13 = (@13+@37) */
  w13 += w37;
  /* #219: @13 = (2.*@13) */
  w13 = (2.* w13 );
  /* #220: @37 = (@39*@35) */
  w37  = (w39*w35);
  /* #221: @33 = (@37-@33) */
  w33  = (w37-w33);
  /* #222: @33 = (2.*@33) */
  w33 = (2.* w33 );
  /* #223: @33 = (-@33) */
  w33 = (- w33 );
  /* #224: @41 = (@10*@41) */
  w41  = (w10*w41);
  /* #225: @41 = (-@41) */
  w41 = (- w41 );
  /* #226: @6 = (@12*@6) */
  w6  = (w12*w6);
  /* #227: @41 = (@41-@6) */
  w41 -= w6;
  /* #228: @35 = (@17*@35) */
  w35  = (w17*w35);
  /* #229: @8 = (@15*@8) */
  w8  = (w15*w8);
  /* #230: @35 = (@35-@8) */
  w35 -= w8;
  /* #231: @8 = (@41-@35) */
  w8  = (w41-w35);
  /* #232: @8 = (2.*@8) */
  w8 = (2.* w8 );
  /* #233: @25 = horzcat(@13, @33, @8) */
  rr=w25;
  *rr++ = w13;
  *rr++ = w33;
  *rr++ = w8;
  /* #234: @25 = @25' */
  /* #235: @40 = (@40-@43) */
  w40 -= w43;
  /* #236: @40 = (2.*@40) */
  w40 = (2.* w40 );
  /* #237: @41 = (@41+@35) */
  w41 += w35;
  /* #238: @41 = (2.*@41) */
  w41 = (2.* w41 );
  /* #239: @37 = (@37-@42) */
  w37 -= w42;
  /* #240: @37 = (2.*@37) */
  w37 = (2.* w37 );
  /* #241: @37 = (-@37) */
  w37 = (- w37 );
  /* #242: @44 = horzcat(@40, @41, @37) */
  rr=w44;
  *rr++ = w40;
  *rr++ = w41;
  *rr++ = w37;
  /* #243: @44 = @44' */
  /* #244: @26 = horzcat(@4, @25, @44) */
  rr=w26;
  for (i=0, cs=w4; i<3; ++i) *rr++ = *cs++;
  for (i=0, cs=w25; i<3; ++i) *rr++ = *cs++;
  for (i=0, cs=w44; i<3; ++i) *rr++ = *cs++;
  /* #245: @27 = @26' */
  for (i=0, rr=w27, cs=w26; i<3; ++i) for (j=0; j<3; ++j) rr[i+j*3] = *cs++;
  /* #246: @4 = mac(@27,@23,@5) */
  casadi_copy(w5, 3, w4);
  for (i=0, rr=w4; i<1; ++i) for (j=0; j<3; ++j, ++rr) for (k=0, ss=w27+j, tt=w23+i*3; k<3; ++k) *rr += ss[k*3]**tt++;
  /* #247: @25 = (@4/@14) */
  for (i=0, rr=w25, cr=w4; i<3; ++i) (*rr++)  = ((*cr++)/w14);
  /* #248: @40 = @4[0] */
  for (rr=(&w40), ss=w4+0; ss!=w4+1; ss+=1) *rr++ = *ss;
  /* #249: @40 = (@20*@40) */
  w40  = (w20*w40);
  /* #250: @41 = @4[1] */
  for (rr=(&w41), ss=w4+1; ss!=w4+2; ss+=1) *rr++ = *ss;
  /* #251: @41 = (@2*@41) */
  w41  = (w2*w41);
  /* #252: @40 = (@40+@41) */
  w40 += w41;
  /* #253: @41 = @4[2] */
  for (rr=(&w41), ss=w4+2; ss!=w4+3; ss+=1) *rr++ = *ss;
  /* #254: @41 = (@18*@41) */
  w41  = (w18*w41);
  /* #255: @40 = (@40+@41) */
  w40 += w41;
  /* #256: @40 = (@40/@16) */
  w40 /= w16;
  /* #257: @4 = (@24*@40) */
  for (i=0, rr=w4, cr=w24; i<3; ++i) (*rr++)  = ((*cr++)*w40);
  /* #258: @25 = (@25-@4) */
  for (i=0, rr=w25, cs=w4; i<3; ++i) (*rr++) -= (*cs++);
  /* #259: @25 = (@1*@25) */
  for (i=0, rr=w25, cs=w25; i<3; ++i) (*rr++)  = (w1*(*cs++));
  /* #260: @40 = @25[0] */
  for (rr=(&w40), ss=w25+0; ss!=w25+1; ss+=1) *rr++ = *ss;
  /* #261: @41 = @25[1] */
  for (rr=(&w41), ss=w25+1; ss!=w25+2; ss+=1) *rr++ = *ss;
  /* #262: @37 = @25[2] */
  for (rr=(&w37), ss=w25+2; ss!=w25+3; ss+=1) *rr++ = *ss;
  /* #263: @25 = vertcat(@30, @30, @30, @40, @41, @37) */
  rr=w25;
  *rr++ = w40;
  *rr++ = w41;
  *rr++ = w37;
  /* #264: @4 = @25[:3] */
  for (rr=w4, ss=w25+0; ss!=w25+3; ss+=1) *rr++ = *ss;
  /* #265: (@28[5:20:5] = @4) */
  for (rr=w28+5, ss=w4; rr!=w28+20; rr+=5) *rr = *ss++;
  /* #266: @3 = (2.*@3) */
  w3 = (2.* w3 );
  /* #267: @3 = (@3/@21) */
  w3 /= w21;
  /* #268: @40 = (@31*@3) */
  w40  = (w31*w3);
  /* #269: @40 = (@38-@40) */
  w40  = (w38-w40);
  /* #270: @41 = (@22*@40) */
  w41  = (w22*w40);
  /* #271: @37 = (@19*@3) */
  w37  = (w19*w3);
  /* #272: @42 = (@11*@37) */
  w42  = (w11*w37);
  /* #273: @35 = (@41-@42) */
  w35  = (w41-w42);
  /* #274: @35 = (2.*@35) */
  w35 = (2.* w35 );
  /* #275: @35 = (-@35) */
  w35 = (- w35 );
  /* #276: @43 = (@15*@40) */
  w43  = (w15*w40);
  /* #277: @13 = (@36*@3) */
  w13  = (w36*w3);
  /* #278: @33 = (@10*@13) */
  w33  = (w10*w13);
  /* #279: @43 = (@43-@33) */
  w43 -= w33;
  /* #280: @33 = (@17*@37) */
  w33  = (w17*w37);
  /* #281: @33 = (-@33) */
  w33 = (- w33 );
  /* #282: @3 = (@7*@3) */
  w3  = (w7*w3);
  /* #283: @8 = (@12*@3) */
  w8  = (w12*w3);
  /* #284: @33 = (@33-@8) */
  w33 -= w8;
  /* #285: @8 = (@43-@33) */
  w8  = (w43-w33);
  /* #286: @8 = (2.*@8) */
  w8 = (2.* w8 );
  /* #287: @6 = (@15*@37) */
  w6  = (w15*w37);
  /* #288: @6 = (-@6) */
  w6 = (- w6 );
  /* #289: @34 = (@12*@13) */
  w34  = (w12*w13);
  /* #290: @6 = (@6-@34) */
  w6 -= w34;
  /* #291: @34 = (@17*@40) */
  w34  = (w17*w40);
  /* #292: @32 = (@10*@3) */
  w32  = (w10*w3);
  /* #293: @34 = (@34-@32) */
  w34 -= w32;
  /* #294: @32 = (@6+@34) */
  w32  = (w6+w34);
  /* #295: @32 = (2.*@32) */
  w32 = (2.* w32 );
  /* #296: @4 = horzcat(@35, @8, @32) */
  rr=w4;
  *rr++ = w35;
  *rr++ = w8;
  *rr++ = w32;
  /* #297: @4 = @4' */
  /* #298: @43 = (@43+@33) */
  w43 += w33;
  /* #299: @43 = (2.*@43) */
  w43 = (2.* w43 );
  /* #300: @42 = (-@42) */
  w42 = (- w42 );
  /* #301: @33 = (@39*@13) */
  w33  = (w39*w13);
  /* #302: @42 = (@42-@33) */
  w42 -= w33;
  /* #303: @42 = (2.*@42) */
  w42 = (2.* w42 );
  /* #304: @42 = (-@42) */
  w42 = (- w42 );
  /* #305: @40 = (@12*@40) */
  w40  = (w12*w40);
  /* #306: @37 = (@10*@37) */
  w37  = (w10*w37);
  /* #307: @40 = (@40-@37) */
  w40 -= w37;
  /* #308: @13 = (@17*@13) */
  w13  = (w17*w13);
  /* #309: @13 = (-@13) */
  w13 = (- w13 );
  /* #310: @3 = (@15*@3) */
  w3  = (w15*w3);
  /* #311: @13 = (@13-@3) */
  w13 -= w3;
  /* #312: @3 = (@40-@13) */
  w3  = (w40-w13);
  /* #313: @3 = (2.*@3) */
  w3 = (2.* w3 );
  /* #314: @25 = horzcat(@43, @42, @3) */
  rr=w25;
  *rr++ = w43;
  *rr++ = w42;
  *rr++ = w3;
  /* #315: @25 = @25' */
  /* #316: @6 = (@6-@34) */
  w6 -= w34;
  /* #317: @6 = (2.*@6) */
  w6 = (2.* w6 );
  /* #318: @40 = (@40+@13) */
  w40 += w13;
  /* #319: @40 = (2.*@40) */
  w40 = (2.* w40 );
  /* #320: @41 = (@41-@33) */
  w41 -= w33;
  /* #321: @41 = (2.*@41) */
  w41 = (2.* w41 );
  /* #322: @41 = (-@41) */
  w41 = (- w41 );
  /* #323: @44 = horzcat(@6, @40, @41) */
  rr=w44;
  *rr++ = w6;
  *rr++ = w40;
  *rr++ = w41;
  /* #324: @44 = @44' */
  /* #325: @27 = horzcat(@4, @25, @44) */
  rr=w27;
  for (i=0, cs=w4; i<3; ++i) *rr++ = *cs++;
  for (i=0, cs=w25; i<3; ++i) *rr++ = *cs++;
  for (i=0, cs=w44; i<3; ++i) *rr++ = *cs++;
  /* #326: @26 = @27' */
  for (i=0, rr=w26, cs=w27; i<3; ++i) for (j=0; j<3; ++j) rr[i+j*3] = *cs++;
  /* #327: @4 = mac(@26,@23,@5) */
  casadi_copy(w5, 3, w4);
  for (i=0, rr=w4; i<1; ++i) for (j=0; j<3; ++j, ++rr) for (k=0, ss=w26+j, tt=w23+i*3; k<3; ++k) *rr += ss[k*3]**tt++;
  /* #328: @25 = (@4/@14) */
  for (i=0, rr=w25, cr=w4; i<3; ++i) (*rr++)  = ((*cr++)/w14);
  /* #329: @6 = @4[0] */
  for (rr=(&w6), ss=w4+0; ss!=w4+1; ss+=1) *rr++ = *ss;
  /* #330: @6 = (@20*@6) */
  w6  = (w20*w6);
  /* #331: @40 = @4[1] */
  for (rr=(&w40), ss=w4+1; ss!=w4+2; ss+=1) *rr++ = *ss;
  /* #332: @40 = (@2*@40) */
  w40  = (w2*w40);
  /* #333: @6 = (@6+@40) */
  w6 += w40;
  /* #334: @40 = @4[2] */
  for (rr=(&w40), ss=w4+2; ss!=w4+3; ss+=1) *rr++ = *ss;
  /* #335: @40 = (@18*@40) */
  w40  = (w18*w40);
  /* #336: @6 = (@6+@40) */
  w6 += w40;
  /* #337: @6 = (@6/@16) */
  w6 /= w16;
  /* #338: @4 = (@24*@6) */
  for (i=0, rr=w4, cr=w24; i<3; ++i) (*rr++)  = ((*cr++)*w6);
  /* #339: @25 = (@25-@4) */
  for (i=0, rr=w25, cs=w4; i<3; ++i) (*rr++) -= (*cs++);
  /* #340: @25 = (@1*@25) */
  for (i=0, rr=w25, cs=w25; i<3; ++i) (*rr++)  = (w1*(*cs++));
  /* #341: @6 = @25[0] */
  for (rr=(&w6), ss=w25+0; ss!=w25+1; ss+=1) *rr++ = *ss;
  /* #342: @40 = @25[1] */
  for (rr=(&w40), ss=w25+1; ss!=w25+2; ss+=1) *rr++ = *ss;
  /* #343: @41 = @25[2] */
  for (rr=(&w41), ss=w25+2; ss!=w25+3; ss+=1) *rr++ = *ss;
  /* #344: @25 = vertcat(@30, @30, @30, @6, @40, @41) */
  rr=w25;
  *rr++ = w6;
  *rr++ = w40;
  *rr++ = w41;
  /* #345: @4 = @25[:3] */
  for (rr=w4, ss=w25+0; ss!=w25+3; ss+=1) *rr++ = *ss;
  /* #346: (@28[6:21:5] = @4) */
  for (rr=w28+6, ss=w4; rr!=w28+21; rr+=5) *rr = *ss++;
  /* #347: @9 = (2.*@9) */
  w9 = (2.* w9 );
  /* #348: @9 = (@9/@21) */
  w9 /= w21;
  /* #349: @19 = (@19*@9) */
  w19 *= w9;
  /* #350: @38 = (@38-@19) */
  w38 -= w19;
  /* #351: @11 = (@11*@38) */
  w11 *= w38;
  /* #352: @31 = (@31*@9) */
  w31 *= w9;
  /* #353: @22 = (@22*@31) */
  w22 *= w31;
  /* #354: @19 = (@11-@22) */
  w19  = (w11-w22);
  /* #355: @19 = (2.*@19) */
  w19 = (2.* w19 );
  /* #356: @19 = (-@19) */
  w19 = (- w19 );
  /* #357: @21 = (@15*@31) */
  w21  = (w15*w31);
  /* #358: @21 = (-@21) */
  w21 = (- w21 );
  /* #359: @36 = (@36*@9) */
  w36 *= w9;
  /* #360: @6 = (@10*@36) */
  w6  = (w10*w36);
  /* #361: @21 = (@21-@6) */
  w21 -= w6;
  /* #362: @6 = (@17*@38) */
  w6  = (w17*w38);
  /* #363: @7 = (@7*@9) */
  w7 *= w9;
  /* #364: @9 = (@12*@7) */
  w9  = (w12*w7);
  /* #365: @6 = (@6-@9) */
  w6 -= w9;
  /* #366: @9 = (@21-@6) */
  w9  = (w21-w6);
  /* #367: @9 = (2.*@9) */
  w9 = (2.* w9 );
  /* #368: @40 = (@15*@38) */
  w40  = (w15*w38);
  /* #369: @41 = (@12*@36) */
  w41  = (w12*w36);
  /* #370: @40 = (@40-@41) */
  w40 -= w41;
  /* #371: @41 = (@17*@31) */
  w41  = (w17*w31);
  /* #372: @41 = (-@41) */
  w41 = (- w41 );
  /* #373: @33 = (@10*@7) */
  w33  = (w10*w7);
  /* #374: @41 = (@41-@33) */
  w41 -= w33;
  /* #375: @33 = (@40+@41) */
  w33  = (w40+w41);
  /* #376: @33 = (2.*@33) */
  w33 = (2.* w33 );
  /* #377: @4 = horzcat(@19, @9, @33) */
  rr=w4;
  *rr++ = w19;
  *rr++ = w9;
  *rr++ = w33;
  /* #378: @4 = @4' */
  /* #379: @21 = (@21+@6) */
  w21 += w6;
  /* #380: @21 = (2.*@21) */
  w21 = (2.* w21 );
  /* #381: @39 = (@39*@36) */
  w39 *= w36;
  /* #382: @11 = (@11-@39) */
  w11 -= w39;
  /* #383: @11 = (2.*@11) */
  w11 = (2.* w11 );
  /* #384: @11 = (-@11) */
  w11 = (- w11 );
  /* #385: @10 = (@10*@38) */
  w10 *= w38;
  /* #386: @12 = (@12*@31) */
  w12 *= w31;
  /* #387: @10 = (@10-@12) */
  w10 -= w12;
  /* #388: @17 = (@17*@36) */
  w17 *= w36;
  /* #389: @17 = (-@17) */
  w17 = (- w17 );
  /* #390: @15 = (@15*@7) */
  w15 *= w7;
  /* #391: @17 = (@17-@15) */
  w17 -= w15;
  /* #392: @15 = (@10-@17) */
  w15  = (w10-w17);
  /* #393: @15 = (2.*@15) */
  w15 = (2.* w15 );
  /* #394: @25 = horzcat(@21, @11, @15) */
  rr=w25;
  *rr++ = w21;
  *rr++ = w11;
  *rr++ = w15;
  /* #395: @25 = @25' */
  /* #396: @40 = (@40-@41) */
  w40 -= w41;
  /* #397: @40 = (2.*@40) */
  w40 = (2.* w40 );
  /* #398: @10 = (@10+@17) */
  w10 += w17;
  /* #399: @10 = (2.*@10) */
  w10 = (2.* w10 );
  /* #400: @22 = (-@22) */
  w22 = (- w22 );
  /* #401: @22 = (@22-@39) */
  w22 -= w39;
  /* #402: @22 = (2.*@22) */
  w22 = (2.* w22 );
  /* #403: @22 = (-@22) */
  w22 = (- w22 );
  /* #404: @44 = horzcat(@40, @10, @22) */
  rr=w44;
  *rr++ = w40;
  *rr++ = w10;
  *rr++ = w22;
  /* #405: @44 = @44' */
  /* #406: @26 = horzcat(@4, @25, @44) */
  rr=w26;
  for (i=0, cs=w4; i<3; ++i) *rr++ = *cs++;
  for (i=0, cs=w25; i<3; ++i) *rr++ = *cs++;
  for (i=0, cs=w44; i<3; ++i) *rr++ = *cs++;
  /* #407: @27 = @26' */
  for (i=0, rr=w27, cs=w26; i<3; ++i) for (j=0; j<3; ++j) rr[i+j*3] = *cs++;
  /* #408: @5 = mac(@27,@23,@5) */
  for (i=0, rr=w5; i<1; ++i) for (j=0; j<3; ++j, ++rr) for (k=0, ss=w27+j, tt=w23+i*3; k<3; ++k) *rr += ss[k*3]**tt++;
  /* #409: @23 = (@5/@14) */
  for (i=0, rr=w23, cr=w5; i<3; ++i) (*rr++)  = ((*cr++)/w14);
  /* #410: @14 = @5[0] */
  for (rr=(&w14), ss=w5+0; ss!=w5+1; ss+=1) *rr++ = *ss;
  /* #411: @20 = (@20*@14) */
  w20 *= w14;
  /* #412: @14 = @5[1] */
  for (rr=(&w14), ss=w5+1; ss!=w5+2; ss+=1) *rr++ = *ss;
  /* #413: @2 = (@2*@14) */
  w2 *= w14;
  /* #414: @20 = (@20+@2) */
  w20 += w2;
  /* #415: @2 = @5[2] */
  for (rr=(&w2), ss=w5+2; ss!=w5+3; ss+=1) *rr++ = *ss;
  /* #416: @18 = (@18*@2) */
  w18 *= w2;
  /* #417: @20 = (@20+@18) */
  w20 += w18;
  /* #418: @20 = (@20/@16) */
  w20 /= w16;
  /* #419: @24 = (@24*@20) */
  for (i=0, rr=w24; i<3; ++i) (*rr++) *= w20;
  /* #420: @23 = (@23-@24) */
  for (i=0, rr=w23, cs=w24; i<3; ++i) (*rr++) -= (*cs++);
  /* #421: @23 = (@1*@23) */
  for (i=0, rr=w23, cs=w23; i<3; ++i) (*rr++)  = (w1*(*cs++));
  /* #422: @1 = @23[0] */
  for (rr=(&w1), ss=w23+0; ss!=w23+1; ss+=1) *rr++ = *ss;
  /* #423: @20 = @23[1] */
  for (rr=(&w20), ss=w23+1; ss!=w23+2; ss+=1) *rr++ = *ss;
  /* #424: @16 = @23[2] */
  for (rr=(&w16), ss=w23+2; ss!=w23+3; ss+=1) *rr++ = *ss;
  /* #425: @23 = vertcat(@30, @30, @30, @1, @20, @16) */
  rr=w23;
  *rr++ = w1;
  *rr++ = w20;
  *rr++ = w16;
  /* #426: @24 = @23[:3] */
  for (rr=w24, ss=w23+0; ss!=w23+3; ss+=1) *rr++ = *ss;
  /* #427: (@28[7:22:5] = @24) */
  for (rr=w28+7, ss=w24; rr!=w28+22; rr+=5) *rr = *ss++;
  /* #428: output[1][0] = @28 */
  casadi_copy(w28, 18, res[1]);
  return 0;
}

CASADI_SYMBOL_EXPORT int SAM_equation_system_constr_h_e_fun_jac_uxt_zt(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int SAM_equation_system_constr_h_e_fun_jac_uxt_zt_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int SAM_equation_system_constr_h_e_fun_jac_uxt_zt_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void SAM_equation_system_constr_h_e_fun_jac_uxt_zt_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int SAM_equation_system_constr_h_e_fun_jac_uxt_zt_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void SAM_equation_system_constr_h_e_fun_jac_uxt_zt_release(int mem) {
}

CASADI_SYMBOL_EXPORT void SAM_equation_system_constr_h_e_fun_jac_uxt_zt_incref(void) {
}

CASADI_SYMBOL_EXPORT void SAM_equation_system_constr_h_e_fun_jac_uxt_zt_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int SAM_equation_system_constr_h_e_fun_jac_uxt_zt_n_in(void) { return 4;}

CASADI_SYMBOL_EXPORT casadi_int SAM_equation_system_constr_h_e_fun_jac_uxt_zt_n_out(void) { return 3;}

CASADI_SYMBOL_EXPORT casadi_real SAM_equation_system_constr_h_e_fun_jac_uxt_zt_default_in(casadi_int i) {
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* SAM_equation_system_constr_h_e_fun_jac_uxt_zt_name_in(casadi_int i) {
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    case 3: return "i3";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* SAM_equation_system_constr_h_e_fun_jac_uxt_zt_name_out(casadi_int i) {
  switch (i) {
    case 0: return "o0";
    case 1: return "o1";
    case 2: return "o2";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* SAM_equation_system_constr_h_e_fun_jac_uxt_zt_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s1;
    case 1: return casadi_s2;
    case 2: return casadi_s2;
    case 3: return casadi_s2;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* SAM_equation_system_constr_h_e_fun_jac_uxt_zt_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s3;
    case 1: return casadi_s4;
    case 2: return casadi_s5;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int SAM_equation_system_constr_h_e_fun_jac_uxt_zt_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 10;
  if (sz_res) *sz_res = 4;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 116;
  return 0;
}

CASADI_SYMBOL_EXPORT int SAM_equation_system_constr_h_e_fun_jac_uxt_zt_work_bytes(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 10*sizeof(const casadi_real*);
  if (sz_res) *sz_res = 4*sizeof(casadi_real*);
  if (sz_iw) *sz_iw = 0*sizeof(casadi_int);
  if (sz_w) *sz_w = 116*sizeof(casadi_real);
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif
