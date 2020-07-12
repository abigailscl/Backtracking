#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
template <class T>
class File
{
	public:
		File();
		void crearArchivo();
		void mostrar(T** tablero, T n);
	private :
	int contador;
	fstream archivo;	
};
template <class T>
File<T>::File(){
	
}
template <class T>
void File<T>::crearArchivo(){
	archivo.open("solucion.txt",fstream::out); //para leer in, para salir es out escribir
	contador=0;	
}
template <class T>
void File<T>::mostrar(T ** tablero, T n){
	   	contador++;
	   	archivo<<"Solucion "<<contador<<endl;
	   	for(int i=0;i<n;i++){
	   		for(int j=0;j<n;j++){
	   			archivo<<*(*(tablero+i)+j)<<"  ";
			   }
			   archivo<<endl;
		   }
		   archivo<<endl;
	   }
