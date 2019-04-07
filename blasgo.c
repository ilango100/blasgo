#ifdef BLAS
#include "blas.h"
#else
#include "cblas.h"
#endif

#include <complex.h>

//Level 1
//Max functions
int blasgo_isamax(const int N, const float *X, const int incX)
{
#ifdef BLAS
    return isamax_(&N, X, &incX) - 1;
#else
    return cblas_isamax(N, X, incX);
#endif
}
int blasgo_idamax(const int N, const double *X, const int incX)
{
#ifdef BLAS
    return idamax_(&N, X, &incX) - 1;
#else
    return cblas_idamax(N, X, incX);
#endif
}
int blasgo_icamax(const int N, const void *X, const int incX)
{
#ifdef BLAS
    return icamax_(&N, X, &incX) - 1;
#else
    return cblas_icamax(N, X, incX);
#endif
}
int blasgo_izamax(const int N, const void *X, const int incX)
{
#ifdef BLAS
    return izamax_(&N, X, &incX) - 1;
#else
    return cblas_izamax(N, X, incX);
#endif
}

//Norm functions
float blasgo_snrm2(const int N, const float *X, const int incX)
{
#ifdef BLAS
    return snrm2_(&N, X, &incX);
#else
    return cblas_snrm2(N, X, incX);
#endif
}
double blasgo_dnrm2(const int N, const double *X, const int incX)
{
#ifdef BLAS
    return dnrm2_(&N, X, &incX);
#else
    return cblas_dnrm2(N, X, incX);
#endif
}
float blasgo_scnrm2(const int N, const void *X, const int incX)
{
#ifdef BLAS
    return scnrm2_(&N, X, &incX);
#else
    return cblas_scnrm2(N, X, incX);
#endif
}
double blasgo_dznrm2(const int N, const void *X, const int incX)
{
#ifdef BLAS
    return dznrm2_(&N, X, &incX);
#else
    return cblas_dznrm2(N, X, incX);
#endif
}

//Swap functions
void blasgo_sswap(const int N, float *X, const int incX, float *Y, const int incY)
{
#ifdef BLAS
    return sswap_(&N, X, &incX, Y, &incY);
#else
    return cblas_sswap(N, X, incX, Y, incY);
#endif
}
void blasgo_dswap(const int N, double *X, const int incX, double *Y, const int incY)
{
#ifdef BLAS
    return dswap_(&N, X, &incX, Y, &incY);
#else
    return cblas_dswap(N, X, incX, Y, incY);
#endif
}
void blasgo_cswap(const int N, void *X, const int incX, void *Y, const int incY)
{
#ifdef BLAS
    return cswap_(&N, X, &incX, Y, &incY);
#else
    return cblas_cswap(N, X, incX, Y, incY);
#endif
}
void blasgo_zswap(const int N, void *X, const int incX, void *Y, const int incY)
{
#ifdef BLAS
    return zswap_(&N, X, &incX, Y, &incY);
#else
    return cblas_zswap(N, X, incX, Y, incY);
#endif
}

//Copy functions
void blasgo_scopy(const int N, const float *X, const int incX, float *Y, const int incY)
{
#ifdef BLAS
    return scopy_(&N, X, &incX, Y, &incY);
#else
    return cblas_scopy(N, X, incX, Y, incY);
#endif
}
void blasgo_dcopy(const int N, const double *X, const int incX, double *Y, const int incY)
{
#ifdef BLAS
    return dcopy_(&N, X, &incX, Y, &incY);
#else
    return cblas_dcopy(N, X, incX, Y, incY);
#endif
}
void blasgo_ccopy(const int N, const void *X, const int incX, void *Y, const int incY)
{
#ifdef BLAS
    return ccopy_(&N, X, &incX, Y, &incY);
#else
    return cblas_ccopy(N, X, incX, Y, incY);
#endif
}
void blasgo_zcopy(const int N, const void *X, const int incX, void *Y, const int incY)
{
#ifdef BLAS
    return zcopy_(&N, X, &incX, Y, &incY);
#else
    return cblas_zcopy(N, X, incX, Y, incY);
#endif
}

//Sum functions
float blasgo_sasum(const int N, const float *X, const int incX)
{
#ifdef BLAS
    return sasum_(&N, X, &incX);
#else
    return cblas_sasum(N, X, incX);
#endif
}
double blasgo_dasum(const int N, const double *X, const int incX)
{
#ifdef BLAS
    return dasum_(&N, X, &incX);
#else
    return cblas_dasum(N, X, incX);
#endif
}
float blasgo_scasum(const int N, const void *X, const int incX)
{
#ifdef BLAS
    return scasum_(&N, X, &incX);
#else
    return cblas_scasum(N, X, incX);
#endif
}
double blasgo_dzasum(const int N, const void *X, const int incX)
{
#ifdef BLAS
    return dzasum_(&N, X, &incX);
#else
    return cblas_dzasum(N, X, incX);
#endif
}

//Scale functions
void blasgo_sscal(const int N, const float alpha, float *X, const int incX)
{
#ifdef BLAS
    return sscal_(&N, &alpha, X, &incX);
#else
    return cblas_sscal(N, alpha, X, incX);
#endif
}
void blasgo_dscal(const int N, const double alpha, double *X, const int incX)
{
#ifdef BLAS
    return dscal_(&N, &alpha, X, &incX);
#else
    return cblas_dscal(N, alpha, X, incX);
#endif
}
void blasgo_cscal(const int N, const void *alpha, void *X, const int incX)
{
#ifdef BLAS
    return cscal_(&N, alpha, X, &incX);
#else
    return cblas_cscal(N, alpha, X, incX);
#endif
}
void blasgo_zscal(const int N, const void *alpha, void *X, const int incX)
{
#ifdef BLAS
    return zscal_(&N, alpha, X, &incX);
#else
    return cblas_zscal(N, alpha, X, incX);
#endif
}
void blasgo_csscal(const int N, const float alpha, void *X, const int incX)
{
#ifdef BLAS
    return csscal_(&N, &alpha, X, &incX);
#else
    return cblas_csscal(N, alpha, X, incX);
#endif
}
void blasgo_zdscal(const int N, const double alpha, void *X, const int incX)
{
#ifdef BLAS
    return zdscal_(&N, &alpha, X, &incX);
#else
    return cblas_zdscal(N, alpha, X, incX);
#endif
}

//Dot functions
float blasgo_sdot(const int N, const float *X, const int incX, const float *Y, const int incY)
{
#ifdef BLAS
    return sdot_(&N, X, &incX, Y, &incY);
#else
    return cblas_sdot(N, X, incX, Y, incY);
#endif
}
double blasgo_ddot(const int N, const double *X, const int incX, const double *Y, const int incY)
{
#ifdef BLAS
    return ddot_(&N, X, &incX, Y, &incY);
#else
    return cblas_ddot(N, X, incX, Y, incY);
#endif
}
double blasgo_dsdot(const int N, const float *X, const int incX, const float *Y, const int incY)
{
#ifdef BLAS
    return dsdot_(&N, X, &incX, Y, &incY);
#else
    return cblas_dsdot(N, X, incX, Y, incY);
#endif
}
float blasgo_sdsdot(const int N, const float alpha, const float *X, const int incX, const float *Y, const int incY)
{
#ifdef BLAS
    return sdsdot_(&N, &alpha, X, &incX, Y, &incY);
#else
    return cblas_sdsdot(N, alpha, X, incX, Y, incY);
#endif
}
float complex blasgo_cdotu(const int N, const void *X, const int incX, const void *Y, const int incY)
{
#ifdef BLAS
    return cdotu_(&N, X, &incX, Y, &incY);
#else
    float complex ret;
    cblas_cdotu_sub(N, X, incX, Y, incY, &ret);
    return ret;
#endif
}
float complex blasgo_cdotc(const int N, const void *X, const int incX, const void *Y, const int incY)
{
#ifdef BLAS
    return cdotc_(&N, X, &incX, Y, &incY);
#else
    float complex ret;
    cblas_cdotc_sub(N, X, incX, Y, incY, &ret);
    return ret;
#endif
}
double complex blasgo_zdotu(const int N, const void *X, const int incX, const void *Y, const int incY)
{
#ifdef BLAS
    return zdotu_(&N, X, &incX, Y, &incY);
#else
    double complex ret;
    cblas_zdotu_sub(N, X, incX, Y, incY, &ret);
    return ret;
#endif
}
double complex blasgo_zdotc(const int N, const void *X, const int incX, const void *Y, const int incY)
{
#ifdef BLAS
    return zdotc_(&N, X, &incX, Y, &incY);
#else
    double complex ret;
    cblas_zdotc_sub(N, X, incX, Y, incY, &ret);
    return ret;
#endif
}

//Axpy functions
void blasgo_saxpy(const int N, const float alpha, const float *X, const int incX, float *Y, const int incY)
{
#ifdef BLAS
    return saxpy_(&N, &alpha, X, &incX, Y, &incY);
#else
    return cblas_saxpy(N, alpha, X, incX, Y, incY);
#endif
}
void blasgo_daxpy(const int N, const double alpha, const double *X, const int incX, double *Y, const int incY)
{
#ifdef BLAS
    return daxpy_(&N, &alpha, X, &incX, Y, &incY);
#else
    return cblas_daxpy(N, alpha, X, incX, Y, incY);
#endif
}
void blasgo_caxpy(const int N, const void *alpha, const void *X, const int incX, void *Y, const int incY)
{
#ifdef BLAS
    return caxpy_(&N, alpha, X, &incX, Y, &incY);
#else
    return cblas_caxpy(N, alpha, X, incX, Y, incY);
#endif
}
void blasgo_zaxpy(const int N, const void *alpha, const void *X, const int incX, void *Y, const int incY)
{
#ifdef BLAS
    return zaxpy_(&N, alpha, X, &incX, Y, &incY);
#else
    return cblas_zaxpy(N, alpha, X, incX, Y, incY);
#endif
}