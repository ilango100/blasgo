#include "blas.h"
#include "blasgo.h"

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