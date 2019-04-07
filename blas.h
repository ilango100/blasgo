#ifndef BLAS_H
#define BLAS_H

//Level 1
//Max functions
int isamax_(int *N, float *X, int *incX);
int idamax_(int *N, double *X, int *incX);
int icamax_(int *N, void *X, int *incX);
int izamax_(int *N, void *X, int *incX);

//Norm functions
float snrm2_(int *N, float *X, int *incX);
double dnrm2_(int *N, double *X, int *incX);
float scnrm2_(int *N, void *X, int *incX);
double dznrm2_(int *N, void *X, int *incX);

//Swap functions
void sswap_(int *N, float *X, int *incX, float *Y, int *incY);
void dswap_(int *N, double *X, int *incX, double *Y, int *incY);
void cswap_(int *N, void *X, int *incX, void *Y, int *incY);
void zswap_(int *N, void *X, int *incX, void *Y, int *incY);

//Copy functions
void scopy_(int *N, float *X, int *incX, float *Y, int *incY);
void dcopy_(int *N, double *X, int *incX, double *Y, int *incY);
void ccopy_(int *N, void *X, int *incX, void *Y, int *incY);
void zcopy_(int *N, void *X, int *incX, void *Y, int *incY);

#endif

