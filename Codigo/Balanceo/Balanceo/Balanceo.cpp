#include <cstdio>
#define MAXTHREADS 20

extern void BalanceoCarga(int Nth, int M, int *Pos, int *Num);

int main(int argc, char *argv[]){
	int Pos[MAXTHREADS], Num[MAXTHREADS];
	int Nth, M;
	Nth, M;
	Nth = 5;
	M = 8;
	printf("\nTareas: %d,\tHilos: %d\n", M, Nth);
	BalanceoCarga(Nth, M, Pos, Num);
	for (int i = 0; i < Nth; i++){
		printf("hilo: %d\tNumero: %d\tPosicion: %d\n",i,Num[i], Pos[i]);
	}
	Nth = 7;
	M = 3;
	printf("\nTareas: %d,\tHilos: %d\n", M, Nth);
	BalanceoCarga(Nth, M, Pos, Num);
	for (int i = 0; i < Nth; i++){
		printf("hilo: %d%\tNumero: %d\tPosicion %d\n", i, Num[i], Pos[i]);
	}
	Nth = 6;
	M = 100;
	printf("\nTareas: %d,\tHilos: %d\n", M, Nth);
	BalanceoCarga(Nth, M, Pos, Num);
	for (int i = 0; i < Nth; i++){
		printf("hilo: %d%\tNumero: %d\tPosicion %d\n", i, Num[i], Pos[i]);
	}
	//fin
	printf("\n Hector Garbisu MNC 2015");
	std::getchar();
	return 0;
}