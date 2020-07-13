#include <iostream>
#include "Backpack.h"

using namespace std;

int main()
{
    int maxWeigth, numObject;
    cout << "Ingrese el peso maximo: " << endl;
    cin >> maxWeigth;
    cout << "Ingrese el numero de objectos: " << endl;
    cin >> numObject;
    Backpack backpack(maxWeigth, numObject);
    backpack.fillBackpack();
    backpack.findSolution();
    return 0;
}
