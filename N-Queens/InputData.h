/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396                                                       *
******************************************************************/
#if !defined(__Input_Data_h)
#define __Input_Data_h
///@author Abigail Cabascango and Carlos Romero M.
///@include Check.h
#include <iostream>
#include <string>
#include "Check.h"

using namespace std;
/**
*@brief Generic template
*/
template <class T>  class InputData{
public:
    ///@brief Constructor
	InputData() {}
	/**
	*@brief Float data entry.
	*@param int i row of matrix.
	*@param int j column of matrix.
	*@see Check.h
	*@return string
	*/
    string matrizFloatDouble(int i, int j) {
        cout << "\nIngrese valor[" << i << "][" << j << "]: ";
        cin >> value;
        while (check.floatDouble(value)) {
            cout << "\nIngreso erroneo, vuelva a ingresar: ";
            cin >> value;
        }
        return value;
    }
    /**
	*@brief Float data entry.
	*@see Check.h
	*@return string
	*/
    string floatDouble() {
        cout << "\nIngrese valor real:  ";
        cin >> value;
        while (check.floatDouble(value)) {
            cout << "\nIngreso erroneo, vuelva a ingresar: ";
            cin >> value;
        }
        return value;
    }
private:
    Check check;
    string value;
};
///@brief Specific template int
template <>         class InputData<int> {
public:
    /**
	*@brief Integer data entry.
	*@param string message.
	*@see Check.h
	*@return string
	*/
    string integer(string message) {
        cout << message;
        cin >> value;
        while (check.integer(value)) {
            cout << "\nIngreso erroneo, vuelva a ingresar: ";
            cin >> value;
        }
        return value;
    }
    /**
	*@brief Positive integer data entry.
	*@param string message.
	*@see Check.h
	*@return string
	*/
    string positiveInteger(string message) {
        cout << message;
        cin >> value;
        while (check.positiveInteger(value)) {
            cout << "\nIngreso erroneo, vuelva a ingresar: ";
            cin >> value;
        }
        return value;
    }
    /**
	*@brief Integer data entry.
	*@param int i position of array.
	*@see Check.h
	*@return string
	*/
    string integerArray(int i) {
        cout << "\nIngrese valor[" << i << "]: ";
        cin >> value;
        while (check.integer(value)) {
            cout << "\nIngreso erroneo, vuelva a ingresar: ";
            cin >> value;
        }
        return value;
    }
    /**
	*@brief Integer data entry.
	*@param int i row of matrix.
	*@param int j column of matrix.
	*@see Check.h
	*@return string
	*/
    string matrizInteger(int const i, int const j) {
        cout << "\nIngrese valor[" << i << "][" << j << "]: ";
        cin >> value;
        while (check.integer(value)) {
            cout << "\nIngreso erroneo, vuelva a ingresar: ";
            cin >> value;
        }
        return value;
    }
private:
    Check check;
    string value;
};
template <>         class InputData<double> {
public:
    /**
	*@brief Double data entry.
	*@param int i position of array.
	*@see Check.h
	*@return string
	*/
    string realArray(int i) {
        cout << "\nIngrese valor real[" << i << "]: ";
        cin >> value;
        while (check.floatDouble(value)) {
            cout << "\nIngreso erroneo, vuelva a ingresar: ";
            cin >> value;
        }
        return value;
    }
private:
    Check check;
    string value;
};
template <>         class InputData<string> {
public:
    /**
	*@brief Ecuador ID number entry.
	*@param int message.
	*@see Check.h
	*@return string
	*/
    string CI(string message) {
        cout << message;
        cin >> value;
        while (check.identificationCard(value)) {
            cout << "\nCedula incorrecta, ingrese nuevamente: ";
            cin >> value;
        }
        //while para verificar si existe en el archivo
        return value;
    }
    /**
	*@brief Data entry in capital letters.
	*@param int message.
	*@see Check.h
	*@return string
	*/
    string data(string message) {
        cout << message;
        cin >> value;
        while (check.character(value)) {
            cout << "\nIngreso incorrecto, ingrese nuevamente: ";
            cin >> value;
        }
        return value;
    }
    string ruc(string message) {
        cout << message;
        cin >> value;
        while (check.ruc(value)) {
            cout << "\nRUC incorrecto, ingrese nuevamente: ";
            cin >> value;
        }
        return value;
    }
private:
    Check check;
    string value;
};
#endif
