/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396                                                       *
******************************************************************/
/***********************************************************************
 * Module:  main
 * Author:  Carlos Romero - Abigail Cabascango
 * Modified: viernes, 5 de julio de 2020 17:51:04
 * Purpose: Ejecutar el programa
 ***********************************************************************/
#include "Sudoku.h"
#include "Matriz.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
int main() 
{ 
	int** mat;
	int dim = 9;
	Matriz<int> matriz;
	mat = matriz.inicializarMatriz(mat, dim);
	Sudoku <int> jugar;
 	jugar.resolverSudoku(mat, 0, 0, dim, 1);
    return 0; 
} 
