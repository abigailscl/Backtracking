#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iostream>

using namespace std;
template <class T>
class VueltaCaballo
{
	public:
		VueltaCaballo();
		int movimiento(int** mat,T num, T i, T j, T dim, T *q);
			int movimiento(int** mat,T num, T i, T j, T dim);
		int** inicializarMatriz(int ** mat, T dim);
		void imprimir(int ** mat, T dim);
	private:
	int * movi = new int [8];
	int* movj = new int [8];	
};
/**@brief  Constructor
@param 
@returns
*/
template <class T>
VueltaCaballo<T>::VueltaCaballo()
{
	*(movi+0) = -1;
	*(movi+1) = -2;
	*(movi+2) = -2;
	*(movi+3) = -1;
	*(movi+4) =  1;
	*(movi+5) =  2;
	*(movi+6) =  2;
	*(movi+7) =  1 ;
	*(movj+0) =  -2;
	*(movj+1) = -1;
	*(movj+2) = 1; 
	*(movj+3) = 2;
	*(movj+4) = 2; 
	*(movj+5) = 1;
	*(movj+6) = -1;
	*(movj+7) = -2 ;
}
/**@brief  Movimiento del caballo (Backtraking)
@param  int** mat
@param  T num
@param  T i
@param  T j
@param  T dim
@returns
*/
template <class T>
int  VueltaCaballo<T>:: movimiento(int** mat,T num, T i, T j, T dim)
{
  int k, u, v;

  for (k = 0; k < 8; k++) {
        u = i + this->movi[k]; v = j + this->movj[k];
    if (u >= 0 && u < dim && v >= 0 && v < dim) { /* esta dentro de los limites */
      if (*(*(mat+u)+v)== 0) {
        *(*(mat+u)+v) = num;  
        if (i < dim*dim)   
          movimiento(mat,num+1,u,v, dim);
        else 
		{
			*(*(mat+u)+v) = 0; 
		}//imprimir(mat, dim); 
      }
    }
  }
}
/**@brief  Movimiento del caballo (Backtraking)
@param  int** mat
@param  T num
@param  T i
@param  T j
@param  T dim
@param  T *control
@returns int control
*/
template <class T>
int  VueltaCaballo<T>:: movimiento(int** mat,T num, T i, T j, T dim, T *control)
{
	int k, u, v;
  k = 0;
   *control = 0;
   if(*control == 1)
   {
   	 imprimir(mat,dim);
   	 return 0;
   }else
   {
   	do {
     	u = i + this->movi[k]; v = j + this->movj[k];
    	if (u >= 0 && u < dim && v >= 0 && v < dim) { 
      		if (*(*(mat+u)+v)== 0) { 
        		*(*(mat+u)+v) = num;  
        		if (num < dim*dim) {  
          			movimiento(mat,num+1,u,v,dim, control);
         		 if (*control==0){
		   		*(*(mat+u)+v) = 0;  
				}
        	}else {
			*control = 1; 
			return 1;
			}
      	  }
    	}
    		k++;
  	} while (*control==0 && k < 8);
   }
  

}
/**@brief  Inicializar matriz
@param  int** mat
@param  T dim
@returns int** mat
*/
template <class T>
int** VueltaCaballo<T>::inicializarMatriz(int ** mat, T dim)
{
		mat = (int**)malloc(dim*sizeof(int*));
		for(int j = 0; j < dim; j++)
		{
			*(mat+j)= (int*)malloc(dim*sizeof(int));
		//	cout<<"1";	
		}
	for (int i = 0; i < dim; i++)
	{
		for(int j = 0; j < dim; j++)
		{
			mat[i][j] = 0;
		}
	}
	return mat;
}
/**@brief  Imprimir matriz
@param  int** mat
@param  T dim
@returns void
*/
template <class T>
void VueltaCaballo<T>::imprimir(int ** mat, T dim)
{
	for (int i = 0; i < dim; i++)
	{
		for(int j = 0; j < dim; j++)
		{
			cout << "    " <<mat[i][j] ;
		}
		cout<<endl;
	}
	free(movi);
	free(movj);
}

