#include <complex.h>

#ifdef BLAS

#include "blas.h"

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

//Level 1
//Max functions
int blasgo_isamax(const int N, const float *X, const int incX)
{
    return isamax_(&N, X, &incX) - 1;
}
int blasgo_idamax(const int N, const double *X, const int incX)
{
    return idamax_(&N, X, &incX) - 1;
}
int blasgo_icamax(const int N, const void *X, const int incX)
{
    return icamax_(&N, X, &incX) - 1;
}
int blasgo_izamax(const int N, const void *X, const int incX)
{
    return izamax_(&N, X, &incX) - 1;
}

//Norm functions
float blasgo_snrm2(const int N, const float *X, const int incX)
{
    return snrm2_(&N, X, &incX);
}
double blasgo_dnrm2(const int N, const double *X, const int incX)
{
    return dnrm2_(&N, X, &incX);
}
float blasgo_scnrm2(const int N, const void *X, const int incX)
{
    return scnrm2_(&N, X, &incX);
}
double blasgo_dznrm2(const int N, const void *X, const int incX)
{
    return dznrm2_(&N, X, &incX);
}

//Swap functions
void blasgo_sswap(const int N, float *X, const int incX, float *Y, const int incY)
{
    return sswap_(&N, X, &incX, Y, &incY);
}
void blasgo_dswap(const int N, double *X, const int incX, double *Y, const int incY)
{
    return dswap_(&N, X, &incX, Y, &incY);
}
void blasgo_cswap(const int N, void *X, const int incX, void *Y, const int incY)
{
    return cswap_(&N, X, &incX, Y, &incY);
}
void blasgo_zswap(const int N, void *X, const int incX, void *Y, const int incY)
{
    return zswap_(&N, X, &incX, Y, &incY);
}

//Copy functions
void blasgo_scopy(const int N, const float *X, const int incX, float *Y, const int incY)
{
    return scopy_(&N, X, &incX, Y, &incY);
}
void blasgo_dcopy(const int N, const double *X, const int incX, double *Y, const int incY)
{
    return dcopy_(&N, X, &incX, Y, &incY);
}
void blasgo_ccopy(const int N, const void *X, const int incX, void *Y, const int incY)
{
    return ccopy_(&N, X, &incX, Y, &incY);
}
void blasgo_zcopy(const int N, const void *X, const int incX, void *Y, const int incY)
{
    return zcopy_(&N, X, &incX, Y, &incY);
}

//Sum functions
float blasgo_sasum(const int N, const float *X, const int incX)
{
    return sasum_(&N, X, &incX);
}
double blasgo_dasum(const int N, const double *X, const int incX)
{
    return dasum_(&N, X, &incX);
}
float blasgo_scasum(const int N, const void *X, const int incX)
{
    return scasum_(&N, X, &incX);
}
double blasgo_dzasum(const int N, const void *X, const int incX)
{
    return dzasum_(&N, X, &incX);
}

//Scale functions
void blasgo_sscal(const int N, const float alpha, float *X, const int incX)
{
    return sscal_(&N, &alpha, X, &incX);
}
void blasgo_dscal(const int N, const double alpha, double *X, const int incX)
{
    return dscal_(&N, &alpha, X, &incX);
}
void blasgo_cscal(const int N, const void *alpha, void *X, const int incX)
{
    return cscal_(&N, alpha, X, &incX);
}
void blasgo_zscal(const int N, const void *alpha, void *X, const int incX)
{
    return zscal_(&N, alpha, X, &incX);
}
void blasgo_csscal(const int N, const float alpha, void *X, const int incX)
{
    return csscal_(&N, &alpha, X, &incX);
}
void blasgo_zdscal(const int N, const double alpha, void *X, const int incX)
{
    return zdscal_(&N, &alpha, X, &incX);
}

//Dot functions
float blasgo_sdot(const int N, const float *X, const int incX, const float *Y, const int incY)
{
    return sdot_(&N, X, &incX, Y, &incY);
}
double blasgo_ddot(const int N, const double *X, const int incX, const double *Y, const int incY)
{
    return ddot_(&N, X, &incX, Y, &incY);
}
double blasgo_dsdot(const int N, const float *X, const int incX, const float *Y, const int incY)
{
    return dsdot_(&N, X, &incX, Y, &incY);
}
float blasgo_sdsdot(const int N, const float alpha, const float *X, const int incX, const float *Y, const int incY)
{
    return sdsdot_(&N, &alpha, X, &incX, Y, &incY);
}
void blasgo_cdotu(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotu)
{
#ifndef MKL
    *(float complex *)dotu = cdotu_(&N, X, &incX, Y, &incY);
#else
    //MKL uses different signature
    return cdotu_(dotu, &N, X, &incX, Y, &incY);
#endif
}
void blasgo_cdotc(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotc)
{
#ifndef MKL
    *(float complex *)dotc = cdotc_(&N, X, &incX, Y, &incY);
#else
    return cdotc_(dotc, &N, X, &incX, Y, &incY);
#endif
}
void blasgo_zdotu(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotu)
{
#ifndef MKL
    *(double complex *)dotu = zdotu_(&N, X, &incX, Y, &incY);
#else
    return zdotu_(dotu, &N, X, &incX, Y, &incY);
#endif
}
void blasgo_zdotc(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotc)
{
#ifndef MKL
    *(double complex *)dotc = zdotc_(&N, X, &incX, Y, &incY);
#else
    return zdotc_(dotc, &N, X, &incX, Y, &incY);
#endif
}

//Axpy functions
void blasgo_saxpy(const int N, const float alpha, const float *X, const int incX, float *Y, const int incY)
{
    return saxpy_(&N, &alpha, X, &incX, Y, &incY);
}
void blasgo_daxpy(const int N, const double alpha, const double *X, const int incX, double *Y, const int incY)
{
    return daxpy_(&N, &alpha, X, &incX, Y, &incY);
}
void blasgo_caxpy(const int N, const void *alpha, const void *X, const int incX, void *Y, const int incY)
{
    return caxpy_(&N, alpha, X, &incX, Y, &incY);
}
void blasgo_zaxpy(const int N, const void *alpha, const void *X, const int incX, void *Y, const int incY)
{
    return zaxpy_(&N, alpha, X, &incX, Y, &incY);
}

//Level 2
//Gemv functions
void blasgo_sgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const float alpha, const float *A, const int lda, const float *X, const int incX, const float beta, float *Y, const int incY)
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
void blasgo_dgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const double alpha, const double *A, const int lda, const double *X, const int incX, const double beta, double *Y, const int incY)
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
void blasgo_cgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const void *alpha, const void *A, const int lda, const void *X, const int incX, const void *beta, void *Y, const int incY)
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
void blasgo_zgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const void *alpha, const void *A, const int lda, const void *X, const int incX, const void *beta, void *Y, const int incY)
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

#else

#include "cblas.h"

//Level 1
//Max functions
int blasgo_isamax(const int N, const float *X, const int incX)
{
    return cblas_isamax(N, X, incX);
}
int blasgo_idamax(const int N, const double *X, const int incX)
{
    return cblas_idamax(N, X, incX);
}
int blasgo_icamax(const int N, const void *X, const int incX)
{
    return cblas_icamax(N, X, incX);
}
int blasgo_izamax(const int N, const void *X, const int incX)
{
    return cblas_izamax(N, X, incX);
}

//Norm functions
float blasgo_snrm2(const int N, const float *X, const int incX)
{
    return cblas_snrm2(N, X, incX);
}
double blasgo_dnrm2(const int N, const double *X, const int incX)
{
    return cblas_dnrm2(N, X, incX);
}
float blasgo_scnrm2(const int N, const void *X, const int incX)
{
    return cblas_scnrm2(N, X, incX);
}
double blasgo_dznrm2(const int N, const void *X, const int incX)
{
    return cblas_dznrm2(N, X, incX);
}

//Swap functions
void blasgo_sswap(const int N, float *X, const int incX, float *Y, const int incY)
{
    return cblas_sswap(N, X, incX, Y, incY);
}
void blasgo_dswap(const int N, double *X, const int incX, double *Y, const int incY)
{
    return cblas_dswap(N, X, incX, Y, incY);
}
void blasgo_cswap(const int N, void *X, const int incX, void *Y, const int incY)
{
    return cblas_cswap(N, X, incX, Y, incY);
}
void blasgo_zswap(const int N, void *X, const int incX, void *Y, const int incY)
{
    return cblas_zswap(N, X, incX, Y, incY);
}

//Copy functions
void blasgo_scopy(const int N, const float *X, const int incX, float *Y, const int incY)
{
    return cblas_scopy(N, X, incX, Y, incY);
}
void blasgo_dcopy(const int N, const double *X, const int incX, double *Y, const int incY)
{
    return cblas_dcopy(N, X, incX, Y, incY);
}
void blasgo_ccopy(const int N, const void *X, const int incX, void *Y, const int incY)
{
    return cblas_ccopy(N, X, incX, Y, incY);
}
void blasgo_zcopy(const int N, const void *X, const int incX, void *Y, const int incY)
{
    return cblas_zcopy(N, X, incX, Y, incY);
}

//Sum functions
float blasgo_sasum(const int N, const float *X, const int incX)
{
    return cblas_sasum(N, X, incX);
}
double blasgo_dasum(const int N, const double *X, const int incX)
{
    return cblas_dasum(N, X, incX);
}
float blasgo_scasum(const int N, const void *X, const int incX)
{
    return cblas_scasum(N, X, incX);
}
double blasgo_dzasum(const int N, const void *X, const int incX)
{
    return cblas_dzasum(N, X, incX);
}

//Scale functions
void blasgo_sscal(const int N, const float alpha, float *X, const int incX)
{
    return cblas_sscal(N, alpha, X, incX);
}
void blasgo_dscal(const int N, const double alpha, double *X, const int incX)
{
    return cblas_dscal(N, alpha, X, incX);
}
void blasgo_cscal(const int N, const void *alpha, void *X, const int incX)
{
    return cblas_cscal(N, alpha, X, incX);
}
void blasgo_zscal(const int N, const void *alpha, void *X, const int incX)
{
    return cblas_zscal(N, alpha, X, incX);
}
void blasgo_csscal(const int N, const float alpha, void *X, const int incX)
{
    return cblas_csscal(N, alpha, X, incX);
}
void blasgo_zdscal(const int N, const double alpha, void *X, const int incX)
{
    return cblas_zdscal(N, alpha, X, incX);
}

//Dot functions
float blasgo_sdot(const int N, const float *X, const int incX, const float *Y, const int incY)
{
    return cblas_sdot(N, X, incX, Y, incY);
}
double blasgo_ddot(const int N, const double *X, const int incX, const double *Y, const int incY)
{
    return cblas_ddot(N, X, incX, Y, incY);
}
double blasgo_dsdot(const int N, const float *X, const int incX, const float *Y, const int incY)
{
    return cblas_dsdot(N, X, incX, Y, incY);
}
float blasgo_sdsdot(const int N, const float alpha, const float *X, const int incX, const float *Y, const int incY)
{
    return cblas_sdsdot(N, alpha, X, incX, Y, incY);
}
void blasgo_cdotu(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotu)
{
    return cblas_cdotu_sub(N, X, incX, Y, incY, dotu);
}
void blasgo_cdotc(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotc)
{
    return cblas_cdotc_sub(N, X, incX, Y, incY, dotc);
}
void blasgo_zdotu(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotu)
{
    return cblas_zdotu_sub(N, X, incX, Y, incY, dotu);
}
void blasgo_zdotc(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotc)
{
    return cblas_zdotc_sub(N, X, incX, Y, incY, dotc);
}

//Axpy functions
void blasgo_saxpy(const int N, const float alpha, const float *X, const int incX, float *Y, const int incY)
{
    return cblas_saxpy(N, alpha, X, incX, Y, incY);
}
void blasgo_daxpy(const int N, const double alpha, const double *X, const int incX, double *Y, const int incY)
{
    return cblas_daxpy(N, alpha, X, incX, Y, incY);
}
void blasgo_caxpy(const int N, const void *alpha, const void *X, const int incX, void *Y, const int incY)
{
    return cblas_caxpy(N, alpha, X, incX, Y, incY);
}
void blasgo_zaxpy(const int N, const void *alpha, const void *X, const int incX, void *Y, const int incY)
{
    return cblas_zaxpy(N, alpha, X, incX, Y, incY);
}

//Level 2
//Gemv functions
void blasgo_sgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const float alpha, const float *A, const int lda, const float *X, const int incX, const float beta, float *Y, const int incY)
{
    return cblas_sgemv(order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
}
void blasgo_dgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const double alpha, const double *A, const int lda, const double *X, const int incX, const double beta, double *Y, const int incY)
{
    return cblas_dgemv(order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
}
void blasgo_cgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const void *alpha, const void *A, const int lda, const void *X, const int incX, const void *beta, void *Y, const int incY)
{
    return cblas_cgemv(order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
}
void blasgo_zgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA, const int M, const int N, const void *alpha, const void *A, const int lda, const void *X, const int incX, const void *beta, void *Y, const int incY)
{
    return cblas_zgemv(order, TransA, M, N, alpha, A, lda, X, incX, beta, Y, incY);
}

#endif
