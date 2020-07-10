#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
template <class T>
class Hanoi
{
	public:
	Hanoi();
	void movimiento(T disco,T torre1,T torre2,T torre3);
	T pasos(T discos);	
};
template <class T>
Hanoi<T>::Hanoi(){}
template <class T>
T Hanoi<T>::pasos(T discos)
{
	 if(discos == 1)
        return 1;
    else
    return 2 * pasos(discos-1) + 1;
}
template <class T>
void Hanoi<T>::movimiento(T disco,T torre1,T torre2,T torre3)
{
	 if(disco==1)
    {
 		cout<<"Mover disco: "<<disco << " de la torre: "<<torre1<<" hacia la torre: "<< torre3<<endl;
    }
    else
    {
		movimiento(disco-1,torre1, torre3, torre2);
		cout<<"Mover disco: "<< disco<<" de la torre: "<<torre1<<" hacia la torre: "<<torre3<<endl;
		movimiento(disco-1, torre2, torre1, torre3);
    }
	
}

