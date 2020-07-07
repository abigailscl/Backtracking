#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "VueltaCaballo.h"
#include "InputData.h"
using namespace std;
int main()
{
	InputData<int>ingresar;
	VueltaCaballo<int> caballo;
	int **mat;
	int fila, columna, dimension, controlador;
	dimension = atoi(ingresar.positiveInteger("Ingrese la dimension del tablero: ", 4, 8).c_str());
	mat = caballo.inicializarMatriz(mat,dimension);
	fila = atoi(ingresar.positiveInteger("Ingrese la posicion en la fila y columna del primer caballo: ", 0, dimension-1).c_str());
	columna = fila;
	*(*(mat+fila)+columna) = 1;
	//caballo.movimiento(mat,2,fila,columna, dimension);
	caballo.movimiento(mat,2,fila,columna, dimension, &controlador);
	caballo.imprimir(mat, dimension);
	free(mat);
	return 0;
}
