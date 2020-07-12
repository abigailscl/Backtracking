#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
#if !defined(__Matriz_h)
#define __Matriz_h
template <class T>
class Matriz
{
	public:


	Matriz(){}
	T ** inicializarMatriz(T ** mat, T dim);
	void imprimirMat(T ** mat, T dim);

};
template <class T>
T** Matriz<T>::inicializarMatriz(T ** mat, T dim)
{
	mat = (int**)malloc(dim*sizeof(int*));
	for(int j = 0; j < dim; j++){
		*(mat+j)= (int*)malloc(dim*sizeof(int));	
	}
		  int sudoku[9][9] = { { 0, 0, 7, 0, 0, 0, 9, 0, 0 }, 
                       { 0, 0, 0, 0, 1, 0, 4, 7, 2 }, 
                       { 0, 0, 4, 0, 8, 0, 0, 0, 0 }, 
                       { 0, 6, 0, 9, 0, 0, 0, 1, 0 }, 
                       { 0, 0, 0, 0, 0, 0, 0, 3, 0 }, 
                       { 0, 9, 0, 6, 0, 3, 0, 0, 0 }, 
                       { 1, 0, 0, 7, 0, 8, 0, 0, 0 }, 
                       { 7, 0, 0, 0, 0, 6, 0, 0, 0 }, 
                       { 3, 0, 0, 0, 0, 0, 0, 8, 5 } };
	for (int i = 0; i < dim; i++)
	{
		for(int j = 0; j < dim; j++)
		{
			*(*(mat+i)+j)= sudoku[i][j];
		}
	}
	return mat;
}
template <class T>
void Matriz<T>::imprimirMat(T ** mat, T dim)
{ 
    for (int i = 0; i < dim; i++) { 
        for (int j = 0; j < dim; j++){
        	cout<<" "<<*(*(mat+i)+j); 
		} 
        cout<<endl; 
    } 
} 
  
#endif
