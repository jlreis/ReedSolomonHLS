/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;

/* External Global Variable Declarations */
extern unsigned char gf_poly;
extern signed short DECMAT_BA[4];
extern signed short F_tbl[64];
extern  char DECMAT_ROM[3868][48];

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void rs_erasure( char *llvm_cbe_c,  char *llvm_cbe_d, signed short llvm_cbe_survival_pattern,  char llvm_cbe_codeidx);


/* Global Variable Definitions and Initialization */
unsigned char gf_poly = ((unsigned char )29);
signed short DECMAT_BA[4] = { ((unsigned short )0), ((unsigned short )256), ((unsigned short )1024), ((unsigned short )2048) };
signed short F_tbl[64] = { ((unsigned short )1), ((unsigned short )1), ((unsigned short )1), ((unsigned short )1), ((unsigned short )1), ((unsigned short )1), ((unsigned short )1), ((unsigned short )1), ((unsigned short )1), ((unsigned short )1), ((unsigned short )1), ((unsigned short )1), ((unsigned short )1), ((unsigned short )1), ((unsigned short )1), ((unsigned short )1), ((unsigned short )0), ((unsigned short )1), ((unsigned short )2), ((unsigned short )3), ((unsigned short )4), ((unsigned short )5), ((unsigned short )6), ((unsigned short )7), ((unsigned short )8), ((unsigned short )9), ((unsigned short )10), ((unsigned short )11), ((unsigned short )12), ((unsigned short )13), ((unsigned short )14), ((unsigned short )15), ((unsigned short )0), ((unsigned short )0), ((unsigned short )1), ((unsigned short )3), ((unsigned short )6), ((unsigned short )10), ((unsigned short )15), ((unsigned short )21), ((unsigned short )28), ((unsigned short )36), ((unsigned short )45), ((unsigned short )55), ((unsigned short )66), ((unsigned short )78), ((unsigned short )91), ((unsigned short )105), ((unsigned short )0), ((unsigned short )0), ((unsigned short )0), ((unsigned short )1), ((unsigned short )4), ((unsigned short )10), ((unsigned short )20), ((unsigned short )35), ((unsigned short )56), ((unsigned short )84), ((unsigned short )120), ((unsigned short )165), ((unsigned short )220), ((unsigned short )286), ((unsigned short )364), ((unsigned short )455) };


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

void rs_erasure( char *llvm_cbe_c,  char *llvm_cbe_d, signed short llvm_cbe_survival_pattern,  char llvm_cbe_codeidx) {
  static  unsigned long long aesl_llvm_cbe_r_count = 0;
   char llvm_cbe_r[48];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  unsigned long long llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  signed short *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  unsigned short llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  unsigned short llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  unsigned char llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  unsigned char llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  unsigned char llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  unsigned short llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  unsigned short llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned char llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  unsigned long long llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge15_count = 0;
  unsigned char llvm_cbe_storemerge15;
  unsigned char llvm_cbe_storemerge15__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  unsigned short llvm_cbe_tmp__19;
  unsigned short llvm_cbe_tmp__19__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  unsigned short llvm_cbe_tmp__20;
  unsigned short llvm_cbe_tmp__20__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  unsigned char llvm_cbe_tmp__21;
  unsigned char llvm_cbe_tmp__21__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  unsigned char llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  unsigned short llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  unsigned char llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  unsigned char llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  unsigned long long llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  signed short *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  unsigned short llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  unsigned short llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  unsigned char llvm_cbe_tmp__36;
  unsigned char llvm_cbe_tmp__36__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned short llvm_cbe_tmp__37;
  unsigned short llvm_cbe_tmp__37__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  unsigned short llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  unsigned char llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond19_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
   char *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge114_count = 0;
  unsigned char llvm_cbe_storemerge114;
  unsigned char llvm_cbe_storemerge114__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  unsigned long long llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
   char *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  unsigned char llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
   char *llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  unsigned char llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond18_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge310_count = 0;
  unsigned char llvm_cbe_storemerge310;
  unsigned char llvm_cbe_storemerge310__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge48_count = 0;
  unsigned char llvm_cbe_storemerge48;
  unsigned char llvm_cbe_storemerge48__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  unsigned long long llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
   char *llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
   char *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  unsigned char llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  unsigned char llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  unsigned char llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  unsigned int llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  unsigned char llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  unsigned char llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  unsigned char llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  unsigned char llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  unsigned char llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  unsigned char llvm_cbe_tmp__61;
  unsigned char llvm_cbe_tmp__61__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  unsigned char llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  unsigned long long llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
   char *llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  unsigned char llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
   char *llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  unsigned char llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  unsigned char llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  unsigned int llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  unsigned int llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  unsigned char llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  unsigned char llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  unsigned char llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond16_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  unsigned char llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  unsigned char llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  unsigned char llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  unsigned char llvm_cbe_tmp__77;
  unsigned char llvm_cbe_tmp__77__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  unsigned char llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  unsigned long long llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
   char *llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  unsigned char llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
   char *llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  unsigned char llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  unsigned char llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  unsigned int llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  unsigned int llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  unsigned char llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  unsigned char llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  unsigned char llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  unsigned char llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  unsigned char llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  unsigned char llvm_cbe_tmp__92;
  unsigned char llvm_cbe_tmp__92__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  unsigned char llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  unsigned long long llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
   char *llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  unsigned char llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
   char *llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  unsigned char llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  unsigned char llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  unsigned int llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  unsigned int llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  unsigned char llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  unsigned char llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  unsigned char llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  unsigned char llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  unsigned char llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  unsigned char llvm_cbe_tmp__107;
  unsigned char llvm_cbe_tmp__107__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  unsigned char llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @rs_erasure\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = zext i8 %%codeidx to i32, !dbg !5 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_13_count);
  llvm_cbe_tmp__1 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_codeidx&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = and i32 %%1, 3, !dbg !5 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_14_count);
  llvm_cbe_tmp__2 = (unsigned int )llvm_cbe_tmp__1 & 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !5 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__3 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__2&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [4 x i16]* @DECMAT_BA, i64 0, i64 %%3, !dbg !5 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_16_count);
  llvm_cbe_tmp__4 = (signed short *)(&DECMAT_BA[(((signed long long )llvm_cbe_tmp__3))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__3));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__3) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'DECMAT_BA' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i16* %%4, align 2, !dbg !5 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__5 = (unsigned short )*llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = xor i16 %%survival_pattern, -1, !dbg !5 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_21_count);
  llvm_cbe_tmp__6 = (unsigned short )((unsigned short )(llvm_cbe_survival_pattern ^ ((unsigned short )-1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = shl i8 %%codeidx, 1, !dbg !5 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_24_count);
  llvm_cbe_tmp__7 = (unsigned char )((unsigned char )(llvm_cbe_codeidx << ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = and i8 %%7, 6, !dbg !5 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__8 = (unsigned char )((unsigned char )(llvm_cbe_tmp__7 & ((unsigned char )6)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = xor i8 %%8, 6, !dbg !5 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_26_count);
  llvm_cbe_tmp__9 = (unsigned char )((unsigned char )(llvm_cbe_tmp__8 ^ ((unsigned char )6)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = zext i8 %%9 to i32, !dbg !7 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__10 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__9&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = shl i32 1, %%10, !dbg !7 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__11 = (unsigned int )1u << llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add nsw i32 %%11, -1, !dbg !7 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__12 = (unsigned int )((unsigned int )(llvm_cbe_tmp__11&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__12&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sub nsw i32 16, %%10, !dbg !7 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__13 = (unsigned int )((unsigned int )(16u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__10&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__13&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = shl i32 %%12, %%13, !dbg !7 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__14 = (unsigned int )llvm_cbe_tmp__12 << llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = trunc i32 %%14 to i16, !dbg !7 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__15 = (unsigned short )((unsigned short )llvm_cbe_tmp__14&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = or i16 %%15, %%6, !dbg !7 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__16 = (unsigned short )((unsigned short )(llvm_cbe_tmp__15 | llvm_cbe_tmp__6));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add i8 %%9, 3, !dbg !7 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__17 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_tmp__9&255ull)) + ((unsigned char )(((unsigned char )3)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__17&255ull)));
  llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
  llvm_cbe_tmp__19__PHI_TEMPORARY = (unsigned short )llvm_cbe_tmp__5;   /* for PHI node */
  llvm_cbe_tmp__20__PHI_TEMPORARY = (unsigned short )llvm_cbe_tmp__16;   /* for PHI node */
  llvm_cbe_tmp__21__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__17;   /* for PHI node */
  goto llvm_cbe_tmp__109;

llvm_cbe__2e_preheader13:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = zext i16 %%44 to i64, !dbg !6 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__18 = (unsigned long long )((unsigned long long )(unsigned short )llvm_cbe_tmp__37&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__18);
  llvm_cbe_storemerge114__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
  goto llvm_cbe_tmp__110;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__109:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15 = phi i8 [ 0, %%0 ], [ %%46, %%42  for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_storemerge15_count);
  llvm_cbe_storemerge15 = (unsigned char )llvm_cbe_storemerge15__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%X",llvm_cbe_storemerge15);
printf("\n = 0x%X",((unsigned char )0));
printf("\n = 0x%X",llvm_cbe_tmp__39);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = phi i16 [ %%5, %%0 ], [ %%44, %%42  for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__19 = (unsigned short )llvm_cbe_tmp__19__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__19);
printf("\n = 0x%X",llvm_cbe_tmp__5);
printf("\n = 0x%X",llvm_cbe_tmp__37);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = phi i16 [ %%16, %%0 ], [ %%45, %%42  for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__20 = (unsigned short )llvm_cbe_tmp__20__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__20);
printf("\n = 0x%X",llvm_cbe_tmp__16);
printf("\n = 0x%X",llvm_cbe_tmp__38);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = phi i8 [ %%17, %%0 ], [ %%43, %%42  for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__21 = (unsigned char )llvm_cbe_tmp__21__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__21);
printf("\n = 0x%X",llvm_cbe_tmp__17);
printf("\n = 0x%X",llvm_cbe_tmp__36);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = xor i8 %%storemerge15, 15, !dbg !8 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__22 = (unsigned char )((unsigned char )(llvm_cbe_storemerge15 ^ ((unsigned char )15)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = lshr i16 %%21, 15, !dbg !7 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__23 = (unsigned short )((unsigned short )(((unsigned short )(((unsigned short )(llvm_cbe_tmp__20&65535ull)) >> ((unsigned short )(((unsigned short )15)&65535ull))))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__23&65535ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = trunc i16 %%24 to i8, !dbg !7 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_89_count);
  llvm_cbe_tmp__24 = (unsigned char )((unsigned char )llvm_cbe_tmp__23&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__24);
  if (((llvm_cbe_tmp__24&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe_tmp__111;
  } else {
    goto llvm_cbe_tmp__112;
  }

llvm_cbe_tmp__113:
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = phi i8 [ %%28, %%27 ], [ %%22, %%31 ], [ %%22, %%29  for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__36 = (unsigned char )llvm_cbe_tmp__36__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__36);
printf("\n = 0x%X",llvm_cbe_tmp__25);
printf("\n = 0x%X",llvm_cbe_tmp__21);
printf("\n = 0x%X",llvm_cbe_tmp__21);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = phi i16 [ %%20, %%27 ], [ %%41, %%31 ], [ %%20, %%29  for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__37 = (unsigned short )llvm_cbe_tmp__37__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__37);
printf("\n = 0x%X",llvm_cbe_tmp__19);
printf("\n = 0x%X",llvm_cbe_tmp__35);
printf("\n = 0x%X",llvm_cbe_tmp__19);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = shl i16 %%21, 1, !dbg !7 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__38 = (unsigned short )((unsigned short )(llvm_cbe_tmp__20 << ((unsigned short )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = add i8 %%storemerge15, 1, !dbg !8 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__39 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_storemerge15&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__39&255ull)));
  if (((llvm_cbe_tmp__39&255U) == (((unsigned char )16)&255U))) {
    goto llvm_cbe__2e_preheader13;
  } else {
    llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__39;   /* for PHI node */
    llvm_cbe_tmp__19__PHI_TEMPORARY = (unsigned short )llvm_cbe_tmp__37;   /* for PHI node */
    llvm_cbe_tmp__20__PHI_TEMPORARY = (unsigned short )llvm_cbe_tmp__38;   /* for PHI node */
    llvm_cbe_tmp__21__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__36;   /* for PHI node */
    goto llvm_cbe_tmp__109;
  }

llvm_cbe_tmp__112:
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add i8 %%22, -1, !dbg !8 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_94_count);
  llvm_cbe_tmp__25 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_tmp__21&255ull)) + ((unsigned char )(((unsigned char )-1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__25&255ull)));
  llvm_cbe_tmp__36__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__25;   /* for PHI node */
  llvm_cbe_tmp__37__PHI_TEMPORARY = (unsigned short )llvm_cbe_tmp__19;   /* for PHI node */
  goto llvm_cbe_tmp__113;

llvm_cbe_tmp__111:
  if (((( char )llvm_cbe_tmp__21) > (( char )((unsigned char )-1)))) {
    goto llvm_cbe_tmp__114;
  } else {
    llvm_cbe_tmp__36__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__21;   /* for PHI node */
    llvm_cbe_tmp__37__PHI_TEMPORARY = (unsigned short )llvm_cbe_tmp__19;   /* for PHI node */
    goto llvm_cbe_tmp__113;
  }

llvm_cbe_tmp__114:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = zext i8 %%22 to i32, !dbg !6 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__26 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__21&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = shl nuw nsw i32 %%32, 4, !dbg !6 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_103_count);
  llvm_cbe_tmp__27 = (unsigned int )llvm_cbe_tmp__26 << 4u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = and i32 %%33, 48, !dbg !6 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__28 = (unsigned int )llvm_cbe_tmp__27 & 48u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = zext i8 %%23 to i32, !dbg !6 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_105_count);
  llvm_cbe_tmp__29 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__22&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = and i32 %%35, 15, !dbg !6 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__30 = (unsigned int )llvm_cbe_tmp__29 & 15u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = or i32 %%36, %%34, !dbg !6 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_107_count);
  llvm_cbe_tmp__31 = (unsigned int )llvm_cbe_tmp__30 | llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = zext i32 %%37 to i64, !dbg !6 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__32 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__31&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds [64 x i16]* @F_tbl, i64 0, i64 %%38, !dbg !6 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__33 = (signed short *)(&F_tbl[(((signed long long )llvm_cbe_tmp__32))
#ifdef AESL_BC_SIM
 % 64
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__32));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__32) < 64)) fprintf(stderr, "%s:%d: warning: Read access out of array 'F_tbl' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i16* %%39, align 2, !dbg !6 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_110_count);
  llvm_cbe_tmp__34 = (unsigned short )*llvm_cbe_tmp__33;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = add i16 %%40, %%20, !dbg !6 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_111_count);
  llvm_cbe_tmp__35 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__34&65535ull)) + ((unsigned short )(llvm_cbe_tmp__19&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__35&65535ull)));
  llvm_cbe_tmp__36__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__21;   /* for PHI node */
  llvm_cbe_tmp__37__PHI_TEMPORARY = (unsigned short )llvm_cbe_tmp__35;   /* for PHI node */
  goto llvm_cbe_tmp__113;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader11:
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = call i8* @memset(i8* %%c, i32 0, i64 4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_155_count);
  ( char *)memset(( char *)llvm_cbe_c, 0u, 4ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",4ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__40);
}
  llvm_cbe_storemerge310__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
  goto llvm_cbe__2e_preheader7;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__110:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge114 = phi i8 [ 0, %%.preheader13 ], [ %%53, %%48  for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_storemerge114_count);
  llvm_cbe_storemerge114 = (unsigned char )llvm_cbe_storemerge114__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge114 = 0x%X",llvm_cbe_storemerge114);
printf("\n = 0x%X",((unsigned char )0));
printf("\n = 0x%X",llvm_cbe_tmp__45);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = zext i8 %%storemerge114 to i64, !dbg !6 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_160_count);
  llvm_cbe_tmp__41 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_storemerge114&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = getelementptr inbounds [3868 x [48 x i8]]* @DECMAT_ROM, i64 0, i64 %%18, i64 %%49, !dbg !6 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_161_count);
  llvm_cbe_tmp__42 = ( char *)(&DECMAT_ROM[(((signed long long )llvm_cbe_tmp__18))
#ifdef AESL_BC_SIM
 % 3868
#endif
][(((signed long long )llvm_cbe_tmp__41))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__18));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__41));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__18) < 3868)) fprintf(stderr, "%s:%d: warning: Read access out of array 'DECMAT_ROM' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__41) < 48)) fprintf(stderr, "%s:%d: warning: Read access out of array 'DECMAT_ROM' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load i8* %%50, align 1, !dbg !6 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_162_count);
  llvm_cbe_tmp__43 = (unsigned char )*llvm_cbe_tmp__42;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = getelementptr inbounds [48 x i8]* %%r, i64 0, i64 %%49, !dbg !6 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_163_count);
  llvm_cbe_tmp__44 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__41))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__41));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__41) < 48 && "Write access out of array 'r' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%51, i8* %%52, align 1, !dbg !6 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_164_count);
  *llvm_cbe_tmp__44 = llvm_cbe_tmp__43;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = add i8 %%storemerge114, 1, !dbg !9 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_165_count);
  llvm_cbe_tmp__45 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_storemerge114&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__45&255ull)));
  if (((llvm_cbe_tmp__45&255U) == (((unsigned char )48)&255U))) {
    goto llvm_cbe__2e_preheader11;
  } else {
    llvm_cbe_storemerge114__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__45;   /* for PHI node */
    goto llvm_cbe_tmp__110;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader7' to make GCC happy */
llvm_cbe__2e_preheader7:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge310 = phi i8 [ 0, %%.preheader11 ], [ %%89, %%88  for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_storemerge310_count);
  llvm_cbe_storemerge310 = (unsigned char )llvm_cbe_storemerge310__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge310 = 0x%X",llvm_cbe_storemerge310);
printf("\n = 0x%X",((unsigned char )0));
printf("\n = 0x%X",llvm_cbe_tmp__73);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = zext i8 %%storemerge310 to i32, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_187_count);
  llvm_cbe_tmp__46 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_storemerge310&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = shl i32 1, %%54, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_188_count);
  llvm_cbe_tmp__47 = (unsigned int )1u << llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
  llvm_cbe_storemerge48__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
  goto llvm_cbe__2e_preheader;

llvm_cbe_tmp__115:
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = add i8 %%storemerge310, 1, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_273_count);
  llvm_cbe_tmp__73 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_storemerge310&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__73&255ull)));
  if (((llvm_cbe_tmp__73&255U) == (((unsigned char )8)&255U))) {
    goto llvm_cbe_tmp__116;
  } else {
    llvm_cbe_storemerge310__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__73;   /* for PHI node */
    goto llvm_cbe__2e_preheader7;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge48 = phi i8 [ 0, %%.preheader7 ], [ %%138, %%136  for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_storemerge48_count);
  llvm_cbe_storemerge48 = (unsigned char )llvm_cbe_storemerge48__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge48 = 0x%X",llvm_cbe_storemerge48);
printf("\n = 0x%X",((unsigned char )0));
printf("\n = 0x%X",llvm_cbe_tmp__108);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = zext i8 %%storemerge48 to i64, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_205_count);
  llvm_cbe_tmp__48 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_storemerge48&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = getelementptr inbounds i8* %%d, i64 %%56, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_206_count);
  llvm_cbe_tmp__49 = ( char *)(&llvm_cbe_d[(((signed long long )llvm_cbe_tmp__48))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__48));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = getelementptr inbounds [48 x i8]* %%r, i64 0, i64 %%56, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__50 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__48))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__48));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__48) < 48)) fprintf(stderr, "%s:%d: warning: Read access out of array 'r' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = load i8* %%58, align 1, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__51 = (unsigned char )*llvm_cbe_tmp__50;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = load i8* %%c, align 1, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_217_count);
  llvm_cbe_tmp__52 = (unsigned char )*llvm_cbe_c;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = load i8* %%57, align 1, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_218_count);
  llvm_cbe_tmp__53 = (unsigned char )*llvm_cbe_tmp__49;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = zext i8 %%61 to i32, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_219_count);
  llvm_cbe_tmp__54 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__53&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = and i32 %%62, %%55, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_220_count);
  llvm_cbe_tmp__55 = (unsigned int )llvm_cbe_tmp__54 & llvm_cbe_tmp__47;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = select i1 %%64, i8 0, i8 %%59, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_222_count);
  llvm_cbe_tmp__56 = (unsigned char )((((llvm_cbe_tmp__55&4294967295U) == (0u&4294967295U))) ? ((unsigned char )((unsigned char )0)) : ((unsigned char )llvm_cbe_tmp__51));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = xor i8 %%65, %%60, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_223_count);
  llvm_cbe_tmp__57 = (unsigned char )((unsigned char )(llvm_cbe_tmp__56 ^ llvm_cbe_tmp__52));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%66, i8* %%c, align 1, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_224_count);
  *llvm_cbe_c = llvm_cbe_tmp__57;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__57);
  if (((( char )llvm_cbe_tmp__51) < (( char )((unsigned char )0)))) {
    goto llvm_cbe_tmp__117;
  } else {
    goto llvm_cbe_tmp__118;
  }

llvm_cbe_tmp__119:
if (AESL_DEBUG_TRACE)
printf("\n  %%137 = phi i8 [ %%135, %%133 ], [ %%132, %%131 ], !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_377_count);
  llvm_cbe_tmp__107 = (unsigned char )llvm_cbe_tmp__107__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__107);
printf("\n = 0x%X",llvm_cbe_tmp__106);
printf("\n = 0x%X",llvm_cbe_tmp__104);
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__94) < 48 && "Write access out of array 'r' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%137, i8* %%120, align 1, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_378_count);
  *llvm_cbe_tmp__95 = llvm_cbe_tmp__107;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE)
printf("\n  %%138 = add i8 %%storemerge48, 1, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_395_count);
  llvm_cbe_tmp__108 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_storemerge48&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__108&255ull)));
  if (((llvm_cbe_tmp__108&255U) == (((unsigned char )12)&255U))) {
    goto llvm_cbe_tmp__115;
  } else {
    llvm_cbe_storemerge48__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__108;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

llvm_cbe_tmp__120:
if (AESL_DEBUG_TRACE)
printf("\n  %%132 = shl i8 %%121, 1, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_372_count);
  llvm_cbe_tmp__104 = (unsigned char )((unsigned char )(llvm_cbe_tmp__96 << ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__104);
  llvm_cbe_tmp__107__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__104;   /* for PHI node */
  goto llvm_cbe_tmp__119;

llvm_cbe_tmp__121:
if (AESL_DEBUG_TRACE)
printf("\n  %%117 = phi i8 [ %%115, %%113 ], [ %%112, %%111 ], !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_331_count);
  llvm_cbe_tmp__92 = (unsigned char )llvm_cbe_tmp__92__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__92);
printf("\n = 0x%X",llvm_cbe_tmp__91);
printf("\n = 0x%X",llvm_cbe_tmp__89);
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__79) < 48 && "Write access out of array 'r' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%117, i8* %%100, align 1, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_332_count);
  *llvm_cbe_tmp__80 = llvm_cbe_tmp__92;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__92);
if (AESL_DEBUG_TRACE)
printf("\n  %%118 = add i8 %%storemerge48, 36, !dbg !9 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_349_count);
  llvm_cbe_tmp__93 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_storemerge48&255ull)) + ((unsigned char )(((unsigned char )36)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__93&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%119 = zext i8 %%118 to i64, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_353_count);
  llvm_cbe_tmp__94 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__93&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE)
printf("\n  %%120 = getelementptr inbounds [48 x i8]* %%r, i64 0, i64 %%119, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_354_count);
  llvm_cbe_tmp__95 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__94))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__94));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__94) < 48)) fprintf(stderr, "%s:%d: warning: Read access out of array 'r' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%121 = load i8* %%120, align 1, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_355_count);
  llvm_cbe_tmp__96 = (unsigned char )*llvm_cbe_tmp__95;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__96);
if (AESL_DEBUG_TRACE)
printf("\n  %%122 = getelementptr inbounds i8* %%c, i64 3, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_361_count);
  llvm_cbe_tmp__97 = ( char *)(&llvm_cbe_c[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%123 = load i8* %%122, align 1, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_362_count);
  llvm_cbe_tmp__98 = (unsigned char )*llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE)
printf("\n  %%124 = load i8* %%57, align 1, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_363_count);
  llvm_cbe_tmp__99 = (unsigned char )*llvm_cbe_tmp__49;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__99);
if (AESL_DEBUG_TRACE)
printf("\n  %%125 = zext i8 %%124 to i32, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_364_count);
  llvm_cbe_tmp__100 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__99&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__100);
if (AESL_DEBUG_TRACE)
printf("\n  %%126 = and i32 %%125, %%55, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_365_count);
  llvm_cbe_tmp__101 = (unsigned int )llvm_cbe_tmp__100 & llvm_cbe_tmp__47;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__101);
if (AESL_DEBUG_TRACE)
printf("\n  %%128 = select i1 %%127, i8 0, i8 %%121, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_367_count);
  llvm_cbe_tmp__102 = (unsigned char )((((llvm_cbe_tmp__101&4294967295U) == (0u&4294967295U))) ? ((unsigned char )((unsigned char )0)) : ((unsigned char )llvm_cbe_tmp__96));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__102);
if (AESL_DEBUG_TRACE)
printf("\n  %%129 = xor i8 %%128, %%123, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_368_count);
  llvm_cbe_tmp__103 = (unsigned char )((unsigned char )(llvm_cbe_tmp__102 ^ llvm_cbe_tmp__98));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__103);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%129, i8* %%122, align 1, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_369_count);
  *llvm_cbe_tmp__97 = llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__103);
  if (((( char )llvm_cbe_tmp__96) < (( char )((unsigned char )0)))) {
    goto llvm_cbe_tmp__122;
  } else {
    goto llvm_cbe_tmp__120;
  }

llvm_cbe_tmp__123:
if (AESL_DEBUG_TRACE)
printf("\n  %%112 = shl i8 %%101, 1, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_326_count);
  llvm_cbe_tmp__89 = (unsigned char )((unsigned char )(llvm_cbe_tmp__81 << ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__89);
  llvm_cbe_tmp__92__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__89;   /* for PHI node */
  goto llvm_cbe_tmp__121;

llvm_cbe_tmp__124:
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = phi i8 [ %%95, %%93 ], [ %%92, %%91 ], !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_285_count);
  llvm_cbe_tmp__77 = (unsigned char )llvm_cbe_tmp__77__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__77);
printf("\n = 0x%X",llvm_cbe_tmp__76);
printf("\n = 0x%X",llvm_cbe_tmp__74);
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__63) < 48 && "Write access out of array 'r' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%97, i8* %%77, align 1, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_286_count);
  *llvm_cbe_tmp__64 = llvm_cbe_tmp__77;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__77);
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = add i8 %%storemerge48, 24, !dbg !9 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_303_count);
  llvm_cbe_tmp__78 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_storemerge48&255ull)) + ((unsigned char )(((unsigned char )24)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__78&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = zext i8 %%98 to i64, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_307_count);
  llvm_cbe_tmp__79 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__78&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__79);
if (AESL_DEBUG_TRACE)
printf("\n  %%100 = getelementptr inbounds [48 x i8]* %%r, i64 0, i64 %%99, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_308_count);
  llvm_cbe_tmp__80 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__79))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__79));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__79) < 48)) fprintf(stderr, "%s:%d: warning: Read access out of array 'r' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%101 = load i8* %%100, align 1, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_309_count);
  llvm_cbe_tmp__81 = (unsigned char )*llvm_cbe_tmp__80;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = getelementptr inbounds i8* %%c, i64 2, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_315_count);
  llvm_cbe_tmp__82 = ( char *)(&llvm_cbe_c[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%103 = load i8* %%102, align 1, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_316_count);
  llvm_cbe_tmp__83 = (unsigned char )*llvm_cbe_tmp__82;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__83);
if (AESL_DEBUG_TRACE)
printf("\n  %%104 = load i8* %%57, align 1, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_317_count);
  llvm_cbe_tmp__84 = (unsigned char )*llvm_cbe_tmp__49;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__84);
if (AESL_DEBUG_TRACE)
printf("\n  %%105 = zext i8 %%104 to i32, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_318_count);
  llvm_cbe_tmp__85 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__84&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__85);
if (AESL_DEBUG_TRACE)
printf("\n  %%106 = and i32 %%105, %%55, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_319_count);
  llvm_cbe_tmp__86 = (unsigned int )llvm_cbe_tmp__85 & llvm_cbe_tmp__47;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE)
printf("\n  %%108 = select i1 %%107, i8 0, i8 %%101, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_321_count);
  llvm_cbe_tmp__87 = (unsigned char )((((llvm_cbe_tmp__86&4294967295U) == (0u&4294967295U))) ? ((unsigned char )((unsigned char )0)) : ((unsigned char )llvm_cbe_tmp__81));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE)
printf("\n  %%109 = xor i8 %%108, %%103, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_322_count);
  llvm_cbe_tmp__88 = (unsigned char )((unsigned char )(llvm_cbe_tmp__87 ^ llvm_cbe_tmp__83));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__88);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%109, i8* %%102, align 1, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_323_count);
  *llvm_cbe_tmp__82 = llvm_cbe_tmp__88;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__88);
  if (((( char )llvm_cbe_tmp__81) < (( char )((unsigned char )0)))) {
    goto llvm_cbe_tmp__125;
  } else {
    goto llvm_cbe_tmp__123;
  }

llvm_cbe_tmp__126:
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = shl i8 %%78, 1, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_280_count);
  llvm_cbe_tmp__74 = (unsigned char )((unsigned char )(llvm_cbe_tmp__65 << ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__74);
  llvm_cbe_tmp__77__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__74;   /* for PHI node */
  goto llvm_cbe_tmp__124;

llvm_cbe_tmp__127:
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = phi i8 [ %%70, %%68 ], [ %%72, %%71 ], !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_232_count);
  llvm_cbe_tmp__61 = (unsigned char )llvm_cbe_tmp__61__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__61);
printf("\n = 0x%X",llvm_cbe_tmp__59);
printf("\n = 0x%X",llvm_cbe_tmp__60);
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__48) < 48 && "Write access out of array 'r' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%74, i8* %%58, align 1, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_233_count);
  *llvm_cbe_tmp__50 = llvm_cbe_tmp__61;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = add i8 %%storemerge48, 12, !dbg !9 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_250_count);
  llvm_cbe_tmp__62 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_storemerge48&255ull)) + ((unsigned char )(((unsigned char )12)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__62&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = zext i8 %%75 to i64, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_254_count);
  llvm_cbe_tmp__63 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__62&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = getelementptr inbounds [48 x i8]* %%r, i64 0, i64 %%76, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_255_count);
  llvm_cbe_tmp__64 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__63))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__63));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__63) < 48)) fprintf(stderr, "%s:%d: warning: Read access out of array 'r' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = load i8* %%77, align 1, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_256_count);
  llvm_cbe_tmp__65 = (unsigned char )*llvm_cbe_tmp__64;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__65);
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = getelementptr inbounds i8* %%c, i64 1, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_262_count);
  llvm_cbe_tmp__66 = ( char *)(&llvm_cbe_c[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = load i8* %%79, align 1, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_263_count);
  llvm_cbe_tmp__67 = (unsigned char )*llvm_cbe_tmp__66;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__67);
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = load i8* %%57, align 1, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_264_count);
  llvm_cbe_tmp__68 = (unsigned char )*llvm_cbe_tmp__49;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = zext i8 %%81 to i32, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_265_count);
  llvm_cbe_tmp__69 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__68&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = and i32 %%82, %%55, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_266_count);
  llvm_cbe_tmp__70 = (unsigned int )llvm_cbe_tmp__69 & llvm_cbe_tmp__47;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = select i1 %%84, i8 0, i8 %%78, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_268_count);
  llvm_cbe_tmp__71 = (unsigned char )((((llvm_cbe_tmp__70&4294967295U) == (0u&4294967295U))) ? ((unsigned char )((unsigned char )0)) : ((unsigned char )llvm_cbe_tmp__65));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = xor i8 %%85, %%80, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_269_count);
  llvm_cbe_tmp__72 = (unsigned char )((unsigned char )(llvm_cbe_tmp__71 ^ llvm_cbe_tmp__67));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%86, i8* %%79, align 1, !dbg !4 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_270_count);
  *llvm_cbe_tmp__66 = llvm_cbe_tmp__72;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__72);
  if (((( char )llvm_cbe_tmp__65) < (( char )((unsigned char )0)))) {
    goto llvm_cbe_tmp__128;
  } else {
    goto llvm_cbe_tmp__126;
  }

llvm_cbe_tmp__117:
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = shl i8 %%59, 1, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_227_count);
  llvm_cbe_tmp__58 = (unsigned char )((unsigned char )(llvm_cbe_tmp__51 << ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = xor i8 %%69, 29, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_228_count);
  llvm_cbe_tmp__59 = (unsigned char )((unsigned char )(llvm_cbe_tmp__58 ^ ((unsigned char )29)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__59);
  llvm_cbe_tmp__61__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__59;   /* for PHI node */
  goto llvm_cbe_tmp__127;

llvm_cbe_tmp__118:
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = shl i8 %%59, 1, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_230_count);
  llvm_cbe_tmp__60 = (unsigned char )((unsigned char )(llvm_cbe_tmp__51 << ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__60);
  llvm_cbe_tmp__61__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__60;   /* for PHI node */
  goto llvm_cbe_tmp__127;

llvm_cbe_tmp__128:
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = shl i8 %%78, 1, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_282_count);
  llvm_cbe_tmp__75 = (unsigned char )((unsigned char )(llvm_cbe_tmp__65 << ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = xor i8 %%94, 29, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_283_count);
  llvm_cbe_tmp__76 = (unsigned char )((unsigned char )(llvm_cbe_tmp__75 ^ ((unsigned char )29)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__76);
  llvm_cbe_tmp__77__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__76;   /* for PHI node */
  goto llvm_cbe_tmp__124;

llvm_cbe_tmp__125:
if (AESL_DEBUG_TRACE)
printf("\n  %%114 = shl i8 %%101, 1, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_328_count);
  llvm_cbe_tmp__90 = (unsigned char )((unsigned char )(llvm_cbe_tmp__81 << ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%115 = xor i8 %%114, 29, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_329_count);
  llvm_cbe_tmp__91 = (unsigned char )((unsigned char )(llvm_cbe_tmp__90 ^ ((unsigned char )29)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__91);
  llvm_cbe_tmp__92__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__91;   /* for PHI node */
  goto llvm_cbe_tmp__121;

llvm_cbe_tmp__122:
if (AESL_DEBUG_TRACE)
printf("\n  %%134 = shl i8 %%121, 1, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_374_count);
  llvm_cbe_tmp__105 = (unsigned char )((unsigned char )(llvm_cbe_tmp__96 << ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__105);
if (AESL_DEBUG_TRACE)
printf("\n  %%135 = xor i8 %%134, 29, !dbg !10 for 0x%I64xth hint within @rs_erasure  --> \n", ++aesl_llvm_cbe_375_count);
  llvm_cbe_tmp__106 = (unsigned char )((unsigned char )(llvm_cbe_tmp__105 ^ ((unsigned char )29)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__106);
  llvm_cbe_tmp__107__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__106;   /* for PHI node */
  goto llvm_cbe_tmp__119;

  } while (1); /* end of syntactic loop '.preheader' */
  } while (1); /* end of syntactic loop '.preheader7' */
llvm_cbe_tmp__116:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @rs_erasure}\n");
  return;
}
