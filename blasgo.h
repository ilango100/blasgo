#ifndef BLASGO_H
#define BLASGO_H

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

#endif