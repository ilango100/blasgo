#ifndef BLAS_H
#define BLAS_H

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

#endif
