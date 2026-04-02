#include "CNumber.h"


CNumber& CNumber::operator=(const int iValue)
{
    int i_value = iValue;
    if (iValue < 0)
    {
        b_isNegative = true;
        i_value *= -1;
    }
    else
    {
        b_isNegative = false;
    }

    //check table length
    int i_value_length = 0;
    int i_value_copy = i_value;

    if (i_value_copy == 0) {
        i_value_length = 1;
    }
    while (i_value_copy > 0) {
        i_value_length++;
        i_value_copy /= i_base;
    }

    int* pi_number_new = new int[i_value_length];

    int j = 0;

    while (i_value > 0) {
        pi_number_new[j] = i_value % i_base;
        i_value /= i_base;
        j++;
    }


    delete[] pi_number;
    pi_number = pi_number_new;
    i_length = i_value_length;
    b_wasLastOperationSuccessful = true;

    return *this;
}

CNumber& CNumber::operator=(const CNumber &pcOther)
{
    if (this == &pcOther) {
        return *this;
    }

    int i_new_length = pcOther.i_length;
    int* pi_number_new = new int[i_new_length];
    for (int i = 0; i < i_new_length; i++) {
        pi_number_new[i] = pcOther.pi_number[i];
    }

    i_length = i_new_length;
    b_isNegative = pcOther.b_isNegative;
    i_base = pcOther.i_base;
    b_wasLastOperationSuccessful = pcOther.b_wasLastOperationSuccessful;

    delete[] pi_number;
    pi_number = pi_number_new;
    return *this;
}


std::string CNumber::toString() {
    std::string s_number = "";
    if (b_isNegative) {
        s_number += "-";
    }
    for (int i = i_length - 1; i >= 0; i--) {
        s_number += std::to_string(pi_number[i]);
    }
    return s_number;
}
