#include <cstdio>
#include <omp.h>
#include <Windows.h>

int main(int argc, char *argv[]){
	printf("Bienvenido, programador de omp\n\n");

#pragma omp parallel num_threads(20)
	{
		int identidad = omp_get_thread_num();
		int size = omp_get_num_threads();
		printf("Hola desde el hilo %d, somos %d\n", identidad, size);
	}

	double inicio, fin, intervalo;
	inicio = omp_get_wtime();
	Sleep(1000);
	fin = omp_get_wtime();
	intervalo = omp_get_wtick();
	printf("\nTiempo transcurrido: %lf milisegundos \nprecision del tick: %g nanosegundos\n",(fin - inicio)*1.0e3, intervalo*1.0e9);

	//fin
	printf("\n Héctor Garbisu MNC 2015");
	std::getchar();
	return 0;
}