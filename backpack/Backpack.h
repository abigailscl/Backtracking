/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396                                                       *
******************************************************************/
#ifndef BACKPACK_H
#define BACKPACK_H
///@author Abigail Cabascango and Carlos Romero M.
#include "Object.h"
#include "InputData.h"

class Backpack
{
private:
    Object* object;
    int maxWeigth;
    int* solution;
    int numObject;
public:
    /**
    *@brief Default constructor
    *@param int queens number.
    */
    Backpack () {}
    /**
    *@brief Constructor
    *@param int max weigth.
    *@param int number object.
    */
    Backpack (int maxWeigth, int numObject)
    {
        this->numObject = numObject;
        this->maxWeigth = maxWeigth;
        this->object = new Object[numObject];
    }
    ///@brief Destroyer
    ~Backpack () {}
    /**
    *@brief start the solutions.
    *@param void.
    *@return void.
    */
    void findSolution()
    {
        backpackSolution(0, maxWeigth, 0, 0);
    }
    /**
    *@brief find the solutions.
    *@param i iterator inialized with zero.
    *@param weigth backpack.
    *@param solution is the biggest benefit.
    *@param optimal is the optimal benefit.
    *@return void.
    */
    void backpackSolution(int i, int weigth, int solution, int optimal)
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
                if ((object + k)->getWeigth() <= weigth)
                {
                    backpackSolution(k, (weigth - (object + k)->getWeigth()), (solution + (object + k)->getValue()), optimal);
                    if ((solution + object->getValue()) > optimal)
                    {
                        optimal = solution + (object + k)->getValue();
                    }
                }
            }
        }

    }
    /**
    *@brief Fill the backpack.
    *@param void.
    *@return void.
    */
    void fillBackpack()
    {
        int weigth, value;
        Object ob;
        InputData<int> enter;
        for (int i = 0; i < numObject; i++)
        {
            std::cout << "[" << (i + 1) << "]";
            weigth = atoi(enter.positiveInteger("Ingrese el peso del objeto: ").c_str());
            
            std::cout << "[" << (i + 1) << "]";
            value = atoi(enter.positiveInteger("Ingrese el valor del objeto: ").c_str());
            
            ob.setWeigth(weigth);
            ob.setValue(value);
            *(object + i) = ob;
        }
    }
    /**
    *@brief Print the objects.
    *@param void.
    *@return void.
    */
    void printObject()
    {
        for (int i = 0; i < numObject; i++)
        {
            std::cout << "Peso: " << (object + i)->getWeigth() << ", Valor: " << (object + i)->getValue() << std::endl;
        }
    }
    /**
    *@brief get the max weigth of backpack.
    *@param void.
    *@return void.
    */
    int getMaxWeigth()
    {
        return maxWeigth;
    }
    /**
    *@brief set the max weigth of backpack.
    *@param int max weigth.
    *@return void.
    */
    void setMaxWeigth(int maxWeigth)
    {
        this->maxWeigth = maxWeigth;
    }
    /**
    *@brief get the object of backpack.
    *@param void.
    *@return void.
    */
    Object* getObject()
    {
        return object;
    }
    /**
    *@brief set the object of backpack.
    *@param Object* object.
    *@return void.
    */
    void setObject(Object* object)
    {
        this->object = object;
    }
};
#endif // BACKPACK_H
