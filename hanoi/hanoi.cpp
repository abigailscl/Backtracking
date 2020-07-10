#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Hanoi.h"
#include "InputData.h"
using namespace std;
int main()
{
	InputData<int> enter;
	Hanoi<int> jugar;
	int discos = atoi(enter.positiveInteger("Ingrese el nmero de discos: ", 3, 8).c_str());
	cout<< "El numero de pasos para resolver es: "<< jugar.pasos(discos)<< " , los pasos son: "<< endl;
	jugar.movimiento(discos, 1,2,3);
	
	return 0;
}
