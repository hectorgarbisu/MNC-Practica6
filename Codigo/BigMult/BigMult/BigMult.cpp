#include <cstdio>
#include <random>
#include <mkl.h>
#include <omp.h>

#define Nbig 4*1024
#define MAXTHREADS 20
extern void BalanceoCarga(int Nth, int M, int *Pos, int *Num);

int main(int argc, char *argv[]){
	int Pos[MAXTHREADS], Num[MAXTHREADS];
	int Nth, N;
	double *A, *B, *C;
	bool test = false;
	int nmuestras = 10;
	int nrepeticiones = 10;
	N = Nbig;
	A = (double *)mkl_malloc(N*N*sizeof(double), 64);
	B = (double *)mkl_malloc(N*N*sizeof(double), 64);
	C = (double *)mkl_malloc(N*N*sizeof(double), 64);
	for (int muestra = 0; muestra < nmuestras; muestra++){

		std::default_random_engine generador;
		std::normal_distribution<double> distribucion(0.0, 1.0);
		for (int i = 0; i < N*N; i++){
			A[i] = distribucion(generador);
			B[i] = distribucion(generador);
		}

		Nth = muestra+1;
		BalanceoCarga(Nth, N, Pos, Num);
		int i;
		double inicio = omp_get_wtime();
#pragma omp parallel for private(i) num_threads(Nth)
		for (int repeticion = 0; repeticion < nrepeticiones; repeticion++){
			for (i = 0; i < Nth; i++){
				cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, Num[i], N, N, 1.0, &(A[Pos[i] * N]), N, B, N, 0.0, &(C[Pos[i] * N]), N);
			}
		}
		double fin = omp_get_wtime();
		double tiempo = fin - inicio;
		tiempo = tiempo / nrepeticiones;
		double Gflops = 2.0*N*N*N*1.0e-09 / tiempo;
		printf("\nNthread: %d\tTiempo: %g s\tGflops: %g\n", Nth, tiempo, Gflops);
	}
	mkl_free(A);
	mkl_free(B);
	printf("\n Hector Garbisu MNC 2015");
	std::getchar();
	return 0;
}