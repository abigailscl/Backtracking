#include <stdio.h> 
#include <iostream>
#include "Matriz.h"
#include "File.h"
using namespace std;
template<class T>
class Sudoku{
	public:
		Sudoku();
		bool buscarFilColVacia(T**, T*, T*, T );  
		bool numRepetido(T**, T, T, T ,T); 
		bool numRepFila( T**, T, T, T) ;
		bool numRepColumna( T**, T, T, T) ;
		bool numRepSeccion( T**, T, T, T, T) ;
		bool resolverSudoku( T**, T, T, T, T);
	private:
		Matriz<int> matrix;
		File <int> file;
		
};
/**@brief  Constructor
@param 
@returns
*/
template <class T>
Sudoku<T>::Sudoku()
{
	file.crearArchivo();	
}
/**@brief  Busca filas y columnas vacias
@param T** mat
@param T* fil
@param T* col
@returns bool
*/
template <class T>
bool Sudoku<T>::buscarFilColVacia(T** mat, T* fil, T* col, T dim)
{
	for (int i = 0; i < dim; i++) {
    	for (int j = 0; j < dim; j++){
    	    if (*(*(mat+i)+j) == 0){
    	    	*fil = i; *col = j;
                return false;     	    	
			}	
		}
	}
	
    return true;
}
/**@brief  Backtraking 
@param T** mat
@param T fila
@param T columna
@param T dim
@param T num
@returns bool
*/
template <class T>
bool Sudoku<T>::resolverSudoku( T** mat, T fila, T columna, T dim, T num)
{
    if (buscarFilColVacia(mat, &fila, &columna, dim)){
    	cout<<"Solucion del sudoku: "<<endl;
    		matrix.imprimirMat(mat, dim);
    		return true;
	}else
	{	 
    	do {  
       	 if (numRepetido(mat, fila, columna, num, dim)) { 

            *(*(mat+fila)+columna) = num; 
            file.mostrar(mat, dim);
            if (resolverSudoku(mat, fila, columna, dim, 1)) {
            	return true; 
			}
            *(*(mat+fila)+columna) = 0; 
         }
         num ++;
    	}while(num <=9) ; 
    	return false;
	}
}
/**@brief  Indica si se repetie en la fila, columna o bloque
@param T** mat
@param T fil
@param T col
@param T num
@param T dim
@returns bool
*/
template <class T>
bool Sudoku<T>::numRepetido(T**mat, T fil, T col, T num , T dim)
{
	return !numRepFila( mat, fil, num, dim) && !numRepColumna(mat, col, num, dim) && !numRepSeccion(mat, fil - fil % 3, col - col % 3, num, dim);
}
/**@brief  Indica si el numero se repite en la fila 
@param T** mat
@param T fil
@param T col
@param T num
@param T dim
@returns bool
*/
template <class T>
bool Sudoku<T>::numRepFila( T**mat, T fil, T num, T dim)
{
	 for (int j = 0; j < dim; j++) 
        if (*(*(mat+fil)+j) == num) 
            return true; 
    return false; 
}
/**@brief  Indica si el numero se repite en la columna 
@param T** mat
@param T fil
@param T col
@param T num
@param T dim
@returns bool
*/
template <class T>
bool Sudoku<T>::numRepColumna( T** mat, T col, T num, T dim)
{
	   for (int i = 0; i < dim; i++) 
        if (*(*(mat+i)+col) == num) 
            return true; 
    return false; 
}
/**@brief  Indica si el numero se repite en el bloque de 3x3
@param T** mat
@param T fil
@param T col
@param T num
@param T dim
@returns bool
*/
template <class T>
bool Sudoku<T>::numRepSeccion( T** mat, T fil, T col, T num, T dim)
{
	    for (int i = 0; i < dim /3; i++){
        for (int j = 0; j < dim /3; j++){
            if ( *(*(mat+i+fil)+j+col) == num) {
            	return true; 
			}		
		}	
	}
    return false; 
}

