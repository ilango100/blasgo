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

#endif