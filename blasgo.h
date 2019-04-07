#ifndef BLASGO_H
#define BLASGO_H

int blasgo_isamax(int N, float *X, int incX);
int blasgo_idamax(int N, double *X, int incX);
int blasgo_icamax(int N, void *X, int incX);
int blasgo_izamax(int N, void *X, int incX);

#endif