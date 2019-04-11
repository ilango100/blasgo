#ifndef BLASGO_H
#define BLASGO_H

#include <complex.h>

#ifndef CBLAS_H

enum CBLAS_ORDER
{
    CblasRowMajor = 101,
    CblasColMajor = 102
};
enum CBLAS_TRANSPOSE
{
    CblasNoTrans = 111,
    CblasTrans = 112,
    CblasConjTrans = 113
};
enum CBLAS_UPLO
{
    CblasUpper = 121,
    CblasLower = 122
};
enum CBLAS_DIAG
{
    CblasNonUnit = 131,
    CblasUnit = 132
};
enum CBLAS_SIDE
{
    CblasLeft = 141,
    CblasRight = 142
};

#endif

// Level 1
//Max functions
int blasgo_isamax(const int N, const float *X, const int incX);
int blasgo_idamax(const int N, const double *X, const int incX);
int blasgo_icamax(const int N, const void *X, const int incX);
int blasgo_izamax(const int N, const void *X, const int incX);

//Norm functions
float blasgo_snrm2(const int N, const float *X, const int incX);
double blasgo_dnrm2(const int N, const double *X, const int incX);
float blasgo_scnrm2(const int N, const void *X, const int incX);
double blasgo_dznrm2(const int N, const void *X, const int incX);

//Swap functions
void blasgo_sswap(const int N, float *X, const int incX, float *Y, const int incY);
void blasgo_dswap(const int N, double *X, const int incX, double *Y, const int incY);
void blasgo_cswap(const int N, void *X, const int incX, void *Y, const int incY);
void blasgo_zswap(const int N, void *X, const int incX, void *Y, const int incY);

//Copy functions
void blasgo_scopy(const int N, const float *X, const int incX, float *Y, const int incY);
void blasgo_dcopy(const int N, const double *X, const int incX, double *Y, const int incY);
void blasgo_ccopy(const int N, const void *X, const int incX, void *Y, const int incY);
void blasgo_zcopy(const int N, const void *X, const int incX, void *Y, const int incY);

//Sum functions
float blasgo_sasum(const int N, const float *X, const int incX);
double blasgo_dasum(const int N, const double *X, const int incX);
float blasgo_scasum(const int N, const void *X, const int incX);
double blasgo_dzasum(const int N, const void *X, const int incX);

//Scale functions
void blasgo_sscal(const int N, const float alpha, float *X, const int incX);
void blasgo_dscal(const int N, const double alpha, double *X, const int incX);
void blasgo_cscal(const int N, const void *alpha, void *X, const int incX);
void blasgo_zscal(const int N, const void *alpha, void *X, const int incX);
void blasgo_csscal(const int N, const float alpha, void *X, const int incX);
void blasgo_zdscal(const int N, const double alpha, void *X, const int incX);

//Dot functions
float blasgo_sdot(const int N, const float *X, const int incX, const float *Y, const int incY);
double blasgo_ddot(const int N, const double *X, const int incX, const double *Y, const int incY);
double blasgo_dsdot(const int N, const float *X, const int incX, const float *Y, const int incY);
float blasgo_sdsdot(const int N, const float alpha, const float *X, const int incX, const float *Y, const int incY);
void blasgo_cdotu(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotu);
void blasgo_cdotc(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotc);
void blasgo_zdotu(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotu);
void blasgo_zdotc(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotc);

//Axpy functions
void blasgo_saxpy(const int N, const float alpha, const float *X, const int incX, float *Y, const int incY);
void blasgo_daxpy(const int N, const double alpha, const double *X, const int incX, double *Y, const int incY);
void blasgo_caxpy(const int N, const void *alpha, const void *X, const int incX, void *Y, const int incY);
void blasgo_zaxpy(const int N, const void *alpha, const void *X, const int incX, void *Y, const int incY);

//Level 2
//Gemv functions
void blasgo_sgemv(const enum CBLAS_ORDER order,
                  const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                  const float alpha, const float *A, const int lda,
                  const float *X, const int incX, const float beta,
                  float *Y, const int incY);
void blasgo_dgemv(const enum CBLAS_ORDER order,
                  const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                  const double alpha, const double *A, const int lda,
                  const double *X, const int incX, const double beta,
                  double *Y, const int incY);
void blasgo_cgemv(const enum CBLAS_ORDER order,
                  const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                  const void *alpha, const void *A, const int lda,
                  const void *X, const int incX, const void *beta,
                  void *Y, const int incY);
void blasgo_zgemv(const enum CBLAS_ORDER order,
                  const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                  const void *alpha, const void *A, const int lda,
                  const void *X, const int incX, const void *beta,
                  void *Y, const int incY);

#endif