#ifdef BLAS

#include <complex.h>
#include "blas.h"
#include "cblas.h"

//Level 1
//Max functions
CBLAS_INDEX cblas_isamax(const int N, const float *X, const int incX)
{
    return isamax_(&N, X, &incX) - 1;
}
CBLAS_INDEX cblas_idamax(const int N, const double *X, const int incX)
{
    return idamax_(&N, X, &incX) - 1;
}
CBLAS_INDEX cblas_icamax(const int N, const void *X, const int incX)
{
    return icamax_(&N, X, &incX) - 1;
}
CBLAS_INDEX cblas_izamax(const int N, const void *X, const int incX)
{
    return izamax_(&N, X, &incX) - 1;
}

//Norm functions
float cblas_snrm2(const int N, const float *X, const int incX)
{
    return snrm2_(&N, X, &incX);
}
double cblas_dnrm2(const int N, const double *X, const int incX)
{
    return dnrm2_(&N, X, &incX);
}
float cblas_scnrm2(const int N, const void *X, const int incX)
{
    return scnrm2_(&N, X, &incX);
}
double cblas_dznrm2(const int N, const void *X, const int incX)
{
    return dznrm2_(&N, X, &incX);
}

//Swap functions
void cblas_sswap(const int N, float *X, const int incX, float *Y, const int incY)
{
    return sswap_(&N, X, &incX, Y, &incY);
}
void cblas_dswap(const int N, double *X, const int incX, double *Y, const int incY)
{
    return dswap_(&N, X, &incX, Y, &incY);
}
void cblas_cswap(const int N, void *X, const int incX, void *Y, const int incY)
{
    return cswap_(&N, X, &incX, Y, &incY);
}
void cblas_zswap(const int N, void *X, const int incX, void *Y, const int incY)
{
    return zswap_(&N, X, &incX, Y, &incY);
}

//Copy functions
void cblas_scopy(const int N, const float *X, const int incX, float *Y, const int incY)
{
    return scopy_(&N, X, &incX, Y, &incY);
}
void cblas_dcopy(const int N, const double *X, const int incX, double *Y, const int incY)
{
    return dcopy_(&N, X, &incX, Y, &incY);
}
void cblas_ccopy(const int N, const void *X, const int incX, void *Y, const int incY)
{
    return ccopy_(&N, X, &incX, Y, &incY);
}
void cblas_zcopy(const int N, const void *X, const int incX, void *Y, const int incY)
{
    return zcopy_(&N, X, &incX, Y, &incY);
}

//Sum functions
float cblas_sasum(const int N, const float *X, const int incX)
{
    return sasum_(&N, X, &incX);
}
double cblas_dasum(const int N, const double *X, const int incX)
{
    return dasum_(&N, X, &incX);
}
float cblas_scasum(const int N, const void *X, const int incX)
{
    return scasum_(&N, X, &incX);
}
double cblas_dzasum(const int N, const void *X, const int incX)
{
    return dzasum_(&N, X, &incX);
}

//Scale functions
void cblas_sscal(const int N, const float alpha, float *X, const int incX)
{
    return sscal_(&N, &alpha, X, &incX);
}
void cblas_dscal(const int N, const double alpha, double *X, const int incX)
{
    return dscal_(&N, &alpha, X, &incX);
}
void cblas_cscal(const int N, const void *alpha, void *X, const int incX)
{
    return cscal_(&N, alpha, X, &incX);
}
void cblas_zscal(const int N, const void *alpha, void *X, const int incX)
{
    return zscal_(&N, alpha, X, &incX);
}
void cblas_csscal(const int N, const float alpha, void *X, const int incX)
{
    return csscal_(&N, &alpha, X, &incX);
}
void cblas_zdscal(const int N, const double alpha, void *X, const int incX)
{
    return zdscal_(&N, &alpha, X, &incX);
}

//Dot functions
float cblas_sdot(const int N, const float *X, const int incX, const float *Y, const int incY)
{
    return sdot_(&N, X, &incX, Y, &incY);
}
double cblas_ddot(const int N, const double *X, const int incX, const double *Y, const int incY)
{
    return ddot_(&N, X, &incX, Y, &incY);
}
double cblas_dsdot(const int N, const float *X, const int incX, const float *Y, const int incY)
{
    return dsdot_(&N, X, &incX, Y, &incY);
}
float cblas_sdsdot(const int N, const float alpha, const float *X, const int incX, const float *Y, const int incY)
{
    return sdsdot_(&N, &alpha, X, &incX, Y, &incY);
}
void cblas_cdotu_sub(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotu)
{
#ifndef MKL
    *(float complex *)dotu = cdotu_(&N, X, &incX, Y, &incY);
#else
    //MKL uses different signature
    return cdotu_(dotu, &N, X, &incX, Y, &incY);
#endif
}
void cblas_cdotc_sub(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotc)
{
#ifndef MKL
    *(float complex *)dotc = cdotc_(&N, X, &incX, Y, &incY);
#else
    return cdotc_(dotc, &N, X, &incX, Y, &incY);
#endif
}
void cblas_zdotu_sub(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotu)
{
#ifndef MKL
    *(double complex *)dotu = zdotu_(&N, X, &incX, Y, &incY);
#else
    return zdotu_(dotu, &N, X, &incX, Y, &incY);
#endif
}
void cblas_zdotc_sub(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotc)
{
#ifndef MKL
    *(double complex *)dotc = zdotc_(&N, X, &incX, Y, &incY);
#else
    return zdotc_(dotc, &N, X, &incX, Y, &incY);
#endif
}

//Axpy functions
void cblas_saxpy(const int N, const float alpha, const float *X, const int incX, float *Y, const int incY)
{
    return saxpy_(&N, &alpha, X, &incX, Y, &incY);
}
void cblas_daxpy(const int N, const double alpha, const double *X, const int incX, double *Y, const int incY)
{
    return daxpy_(&N, &alpha, X, &incX, Y, &incY);
}
void cblas_caxpy(const int N, const void *alpha, const void *X, const int incX, void *Y, const int incY)
{
    return caxpy_(&N, alpha, X, &incX, Y, &incY);
}
void cblas_zaxpy(const int N, const void *alpha, const void *X, const int incX, void *Y, const int incY)
{
    return zaxpy_(&N, alpha, X, &incX, Y, &incY);
}

//Level 2
//Gemv functions
void cblas_sgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const float alpha, const float *A, const int lda, const float *X, const int incX, const float beta, float *Y, const int incY)
{
    char trans = 'N';
    if (order == CblasColMajor)
    {
        if (TransA == CblasTrans || TransA == CblasConjTrans)
            trans = 'T';
    }
    else if (TransA == CblasNoTrans)
        trans = 'T';
    return sgemv_(&trans, &M, &N, &alpha, A, &lda, X, &incX, &beta, Y, &incY);
}
void cblas_dgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const double alpha, const double *A, const int lda, const double *X, const int incX, const double beta, double *Y, const int incY)
{
    char trans = 'N';
    if (order == CblasColMajor)
    {
        if (TransA == CblasTrans || TransA == CblasConjTrans)
            trans = 'T';
    }
    else if (TransA == CblasNoTrans)
        trans = 'T';
    return dgemv_(&trans, &M, &N, &alpha, A, &lda, X, &incX, &beta, Y, &incY);
}
void cblas_cgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const void *alpha, const void *A, const int lda, const void *X, const int incX, const void *beta, void *Y, const int incY)
{
    char trans = 'N';
    if (order == CblasColMajor)
    {
        if (TransA == CblasTrans)
            trans = 'T';
        else if (TransA == CblasConjTrans)
            trans = 'C';
    }
    else
    {
        if (TransA == CblasNoTrans)
            trans = 'T';
        else if (TransA == CblasConjTrans)
        {
            float complex B[M * N];
            const float complex *c = A;
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                    B[i * N + j] = conj(c[i * lda + j]);
            }
            A = B;
            return cgemv_(&trans, &M, &N, alpha, A, &N, X, &incX, beta, Y, &incY);
        }
    }
    return cgemv_(&trans, &M, &N, alpha, A, &lda, X, &incX, beta, Y, &incY);
}
void cblas_zgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const void *alpha, const void *A, const int lda, const void *X, const int incX, const void *beta, void *Y, const int incY)
{
    char trans = 'N';
    if (order == CblasColMajor)
    {
        if (TransA == CblasTrans)
            trans = 'T';
        else if (TransA == CblasConjTrans)
            trans = 'C';
    }
    else
    {
        if (TransA == CblasNoTrans)
            trans = 'T';
        else if (TransA == CblasConjTrans)
        {
            double complex B[M * N];
            const double complex *c = A;
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                    B[i * N + j] = conj(c[i * lda + j]);
            }
            A = B;
            return zgemv_(&trans, &M, &N, alpha, A, &N, X, &incX, beta, Y, &incY);
        }
    }
    return zgemv_(&trans, &M, &N, alpha, A, &lda, X, &incX, beta, Y, &incY);
}

//Ger functions
void cblas_sger(const enum CBLAS_ORDER order, const int M, const int N, const float alpha, const float *X, const int incX, const float *Y, const int incY, float *A, const int lda)
{
    if (order == CblasRowMajor)
    {
        return sger_(&N, &M, &alpha, Y, &incY, X, &incX, A, &lda);
    }
    return sger_(&M, &N, &alpha, X, &incX, Y, &incY, A, &lda);
}
void cblas_dger(const enum CBLAS_ORDER order, const int M, const int N, const double alpha, const double *X, const int incX, const double *Y, const int incY, double *A, const int lda)
{
    if (order == CblasRowMajor)
    {
        return dger_(&N, &M, &alpha, Y, &incY, X, &incX, A, &lda);
    }
    return dger_(&M, &N, &alpha, X, &incX, Y, &incY, A, &lda);
}
void cblas_cgeru(const enum CBLAS_ORDER order, const int M, const int N, const void *alpha, const void *X, const int incX, const void *Y, const int incY, void *A, const int lda)
{
    if (order == CblasRowMajor)
    {
        return cgeru_(&N, &M, alpha, Y, &incY, X, &incX, A, &lda);
    }
    return cgeru_(&M, &N, &alpha, X, &incX, Y, &incY, A, &lda);
}
void cblas_zgeru(const enum CBLAS_ORDER order, const int M, const int N, const void *alpha, const void *X, const int incX, const void *Y, const int incY, void *A, const int lda)
{
    if (order == CblasRowMajor)
    {
        return zgeru_(&N, &M, alpha, Y, &incY, X, &incX, A, &lda);
    }
    return zgeru_(&M, &N, &alpha, X, &incX, Y, &incY, A, &lda);
}

#endif
