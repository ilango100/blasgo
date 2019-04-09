#include <complex.h>

#ifdef BLAS

#include "blas.h"

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
float complex blasgo_cdotu(const int N, const void *X, const int incX, const void *Y, const int incY)
{
#ifndef MKL
    return cdotu_(&N, X, &incX, Y, &incY);
#else
    complex float ret;
    cdotu_(&ret, &N, X, &incX, Y, &incY);
    return ret;
#endif
}
float complex blasgo_cdotc(const int N, const void *X, const int incX, const void *Y, const int incY)
{
#ifndef MKL
    return cdotc_(&N, X, &incX, Y, &incY);
#else
    complex float ret;
    cdotc_(&ret, &N, X, &incX, Y, &incY);
    return ret;
#endif
}
double complex blasgo_zdotu(const int N, const void *X, const int incX, const void *Y, const int incY)
{
#ifndef MKL
    return zdotu_(&N, X, &incX, Y, &incY);
#else
    complex double ret;
    zdotu_(&ret, &N, X, &incX, Y, &incY);
    return ret;
#endif
}
double complex blasgo_zdotc(const int N, const void *X, const int incX, const void *Y, const int incY)
{
#ifndef MKL
    return zdotc_(&N, X, &incX, Y, &incY);
#else
    complex double ret;
    zdotc_(&ret, &N, X, &incX, Y, &incY);
    return ret;
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
float complex blasgo_cdotu(const int N, const void *X, const int incX, const void *Y, const int incY)
{
    float complex ret;
    cblas_cdotu_sub(N, X, incX, Y, incY, &ret);
    return ret;
}
float complex blasgo_cdotc(const int N, const void *X, const int incX, const void *Y, const int incY)
{
    float complex ret;
    cblas_cdotc_sub(N, X, incX, Y, incY, &ret);
    return ret;
}
double complex blasgo_zdotu(const int N, const void *X, const int incX, const void *Y, const int incY)
{
    double complex ret;
    cblas_zdotu_sub(N, X, incX, Y, incY, &ret);
    return ret;
}
double complex blasgo_zdotc(const int N, const void *X, const int incX, const void *Y, const int incY)
{
    double complex ret;
    cblas_zdotc_sub(N, X, incX, Y, incY, &ret);
    return ret;
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

#endif
