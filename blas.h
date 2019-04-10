#ifndef BLAS_H
#define BLAS_H

#include <complex.h>

//Level 1
//Max functions
int isamax_(const int *N, const float *X, const int *incX);
int idamax_(const int *N, const double *X, const int *incX);
int icamax_(const int *N, const void *X, const int *incX);
int izamax_(const int *N, const void *X, const int *incX);

//Norm functions
float snrm2_(const int *N, const float *X, const int *incX);
double dnrm2_(const int *N, const double *X, const int *incX);
float scnrm2_(const int *N, const void *X, const int *incX);
double dznrm2_(const int *N, const void *X, const int *incX);

//Swap functions
void sswap_(const int *N, float *X, const int *incX, float *Y, const int *incY);
void dswap_(const int *N, double *X, const int *incX, double *Y, const int *incY);
void cswap_(const int *N, void *X, const int *incX, void *Y, const int *incY);
void zswap_(const int *N, void *X, const int *incX, void *Y, const int *incY);

//Copy functions
void scopy_(const int *N, const float *X, const int *incX, float *Y, const int *incY);
void dcopy_(const int *N, const double *X, const int *incX, double *Y, const int *incY);
void ccopy_(const int *N, const void *X, const int *incX, void *Y, const int *incY);
void zcopy_(const int *N, const void *X, const int *incX, void *Y, const int *incY);

//Sum functions
float sasum_(const int *N, const float *X, const int *incX);
double dasum_(const int *N, const double *X, const int *incX);
float scasum_(const int *N, const void *X, const int *incX);
double dzasum_(const int *N, const void *X, const int *incX);

//Scale functions
void sscal_(const int *N, const float *alpha, float *X, const int *incX);
void dscal_(const int *N, const double *alpha, double *X, const int *incX);
void cscal_(const int *N, const void *alpha, void *X, const int *incX);
void zscal_(const int *N, const void *alpha, void *X, const int *incX);
void csscal_(const int *N, const float *alpha, void *X, const int *incX);
void zdscal_(const int *N, const double *alpha, void *X, const int *incX);

//Dot functions
float sdot_(const int *N, const float *X, const int *incX, const float *Y, const int *incY);
double ddot_(const int *N, const double *X, const int *incX, const double *Y, const int *incY);
double dsdot_(const int *N, const float *X, const int *incX, const float *Y, const int *incY);
float sdsdot_(const int *N, const float *alpha, const float *X, const int *incX, const float *Y, const int *incY);
#ifndef MKL
float complex cdotu_(const int *N, const void *X, const int *incX, const void *Y, const int *incY);
float complex cdotc_(const int *N, const void *X, const int *incX, const void *Y, const int *incY);
double complex zdotu_(const int *N, const void *X, const int *incX, const void *Y, const int *incY);
double complex zdotc_(const int *N, const void *X, const int *incX, const void *Y, const int *incY);
#else
void cdotu_(void *ret, const int *N, const void *X, const int *incX, const void *Y, const int *incY);
void cdotc_(void *ret, const int *N, const void *X, const int *incX, const void *Y, const int *incY);
void zdotu_(void *ret, const int *N, const void *X, const int *incX, const void *Y, const int *incY);
void zdotc_(void *ret, const int *N, const void *X, const int *incX, const void *Y, const int *incY);
#endif

//Axpy functions
void saxpy_(const int *N, const float *alpha, const float *X, const int *incX, float *Y, const int *incY);
void daxpy_(const int *N, const double *alpha, const double *X, const int *incX, double *Y, const int *incY);
void caxpy_(const int *N, const void *alpha, const void *X, const int *incX, void *Y, const int *incY);
void zaxpy_(const int *N, const void *alpha, const void *X, const int *incX, void *Y, const int *incY);

//Level2 Gemv functions
void sgemv_(const char *TransA, const int *M, const int *N, const float *alpha, const float *A, const int *lda, const float *X, const int *incX, const float *beta, float *Y, const int *incY);
void dgemv_(const char *TransA, const int *M, const int *N, const double *alpha, const double *A, const int *lda, const double *X, const int *incX, const double *beta, double *Y, const int *incY);
void cgemv_(const char *TransA, const int *M, const int *N, const void *alpha, const void *A, const int *lda, const void *X, const int *incX, const void *beta, void *Y, const int *incY);
void zgemv_(const char *TransA, const int *M, const int *N, const void *alpha, const void *A, const int *lda, const void *X, const int *incX, const void *beta, void *Y, const int *incY);

#endif
