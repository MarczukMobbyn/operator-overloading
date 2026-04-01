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
