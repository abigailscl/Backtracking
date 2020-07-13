#ifndef BACKPACK_H
#define BACKPACK_H

#include "Object.h"

class Backpack
{
private:
    Object* object;
    int maxWeigth;
    int* solution;
    int numObject;
public:
    Backpack () {}
    Backpack (int maxWeigth, int numObject)
    {
        this->numObject = numObject;
        this->maxWeigth = maxWeigth;
        this->object = new Object[numObject];
    }
    ~Backpack () {}
    void findSolution()
    {
        backpackSolution(0, maxWeigth, 0, 0);
    }
    void backpackSolution(int i, int r, int solution, int optimal)
    {
        int k;
        if (optimal > solution)
        {
            printObject();
            std::cout <<"Beneficio mayor: " << optimal << std::endl;
        }
        else
        {

            for (k = i; k < numObject; k++)
            {
                if ((object + k)->getWeigth() <= r)
                {
                    backpackSolution(k, (r - (object + k)->getWeigth()), (solution + (object + k)->getValue()), optimal);
                    if ((solution + object->getValue()) > optimal)
                    {
                        optimal = solution + (object + k)->getValue();
                    }
                }
            }
        }

    }
    void fillBackpack()
    {
        int weigth, value;
        Object ob;
        for (int i = 0; i < numObject; i++)
        {
            std::cout << "Ingresar peso al objecto[" << (i + 1) << "]: " << std::endl;
            std::cin >> weigth;
            std::cout << "Ingresar valor al objecto[" << (i + 1) << "]: " << std::endl;
            std::cin >> value;
            ob.setWeigth(weigth);
            ob.setValue(value);
            *(object + i) = ob;
        }
    }
    void printObject()
    {
        for (int i = 0; i < numObject; i++)
        {
            std::cout << "Peso: " << (object + i)->getWeigth() << ", Valor: " << (object + i)->getValue() << std::endl;
        }
    }
    int getMaxWeigth()
    {
        return maxWeigth;
    }
    void setMaxWeigth(int maxWeigth)
    {
        this->maxWeigth = maxWeigth;
    }
    Object* getObject()
    {
        return object;
    }
    void setObject(Object* object)
    {
        this->object = object;
    }
};

#endif // BACKPACK_H
