/*
 * strassen.h
 *
 *  Created on: Apr 20, 2017
 *      Author: Merve Unlu
 */

#ifndef STRASSEN_H_
#define STRASSEN_H_

int timeval_subtract(struct timeval *result,
                     struct timeval *t2, struct timeval *t1);
void matrand(int n, int pitch, double M[]);
void matprint(int n, int pitch, const double M[]);
void matadd(int n,
            int Apitch, const double A[],
            int Bpitch, const double B[],
            int Spitch, double S[]) ;
void matvecadd(int n,
            int Apitch, const double A[],
            int bpitch, const double b[],
	       int Spitch, double S[],int dim) ;
void matsub(int n,
            int Apitch, const double A[],
            int Bpitch, const double B[],
            int Spitch, double S[]);
void matmult(int n,
             int Apitch, const double A[],
             int Bpitch, const double B[],
             int Cpitch, double C[]) ;
void mattranspose(int n,
            int Apitch, const double A[],
	       int Spitch, double S[]);

void matmult_fast(int n,
                  int Xpitch, const double X[],
                  int Ypitch, const double Y[],
                  int Zpitch, double Z[], int min_mat_recurse);
#endif /* STRASSEN_H_ */
