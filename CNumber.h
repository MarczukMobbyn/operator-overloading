#ifndef LISTA2_CNUMBER_H
#define LISTA2_CNUMBER_H
#define NUMBER_DEFAULT_LENGTH 10
#define DEFAULT_BASE 10
#include <string>

class CNumber
{
public:
    CNumber() {i_length = NUMBER_DEFAULT_LENGTH; pi_number = new
   int[i_length]; i_base = DEFAULT_BASE; b_isNegative = false;};
    ~CNumber() {delete[] pi_number;}

    CNumber& operator=(const CNumber &pcNewVal);
    CNumber& operator=(const int iValue);
    CNumber operator+(CNumber &pcNewVal);
    CNumber operator*(CNumber &pcNewVal);
    CNumber operator-(CNumber &pcNewVal);
    CNumber operator/(CNumber &pcNewVal);
    CNumber operator+(int iNewVal);
    CNumber operator*(int iNewVal);
    CNumber operator-(int iNewVal);
    CNumber operator/(int iNewVal);
    bool bIsNegative() {return b_isNegative;}
    bool bWasLastOperationSuccessful() {return b_wasLastOperationSuccessful;}
    std::string toString();
private:
    int *pi_number; //liczby przechowywane w odwrotnej kolejnosci dla uproszczenia dzialan np dzielenia
    int i_length;
    bool b_isNegative;
    int i_base;
    bool b_wasLastOperationSuccessful;
};
#endif //LISTA2_CNUMBER_H