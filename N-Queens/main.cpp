#include <iostream>
#include "Queen.h"
#include "InputData.h"

using namespace std;

int main()
{
    InputData<int> enter;
    int queens;
    queens = atoi(enter.positiveInteger("Ingrese el numero de reinas: ").c_str());
    Queen queen(queens);
    queen.NQueens();
    return 0;
}
