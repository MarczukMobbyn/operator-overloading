#ifndef LISTA2_CNUMBER_H
#define LISTA2_CNUMBER_H
#define NUMBER_DEFAULT_LENGTH 1
#define DEFAULT_BASE 10
#include <string>

class CNumber
{
public:
    CNumber();
    ~CNumber() {delete[] pi_number;}
    CNumber(const CNumber &pcOther);
    CNumber(int iBase);

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
    std::string sToString();
    void vChangeBase(int iNewBase);
private:
    int *pi_number; //liczby przechowywane w odwrotnej kolejnosci dla uproszczenia dzialan np dzielenia
    int i_length;
    bool b_isNegative;
    int i_base;
    bool b_wasLastOperationSuccessful;
};
#endif //LISTA2_CNUMBER_H