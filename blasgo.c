#ifdef BLAS
#include "blas.h"
#else
#include "cblas.h"
#endif

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
    return cscal_(&N, &alpha, X, &incX);
#else
    return cblas_cscal(N, alpha, X, incX);
#endif
}
void blasgo_zscal(const int N, const void *alpha, void *X, const int incX)
{
#ifdef BLAS
    return zscal_(&N, &alpha, X, &incX);
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