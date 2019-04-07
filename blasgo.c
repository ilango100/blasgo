#include "blas.h"
#include "blasgo.h"

int blasgo_isamax(int N, float *X, int incX)
{
    return isamax_(&N, X, &incX) - 1;
}

int blasgo_idamax(int N, double *X, int incX)
{
    return idamax_(&N, X, &incX) - 1;
}

int blasgo_icamax(int N, void *X, int incX)
{
    return icamax_(&N, X, &incX) - 1;
}

int blasgo_izamax(int N, void *X, int incX)
{
    return izamax_(&N, X, &incX) - 1;
}