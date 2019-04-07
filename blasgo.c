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