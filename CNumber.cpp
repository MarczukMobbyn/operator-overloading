#include "CNumber.h"

CNumber::CNumber(const CNumber &pcOther) {
    pi_number = NULL;
    *this = pcOther; //deep copy
}

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

CNumber CNumber::operator+(CNumber &pcOther) {
    CNumber c_res;
    if (this->b_isNegative == pcOther.b_isNegative) {
        c_res.b_isNegative = this->b_isNegative;
    }
    //jesli znaki rozne to traktujemy to jako dodawanie, ale jeszcze nie mam zaimplementowanego

    int i_max_len;
    if (i_length > pcOther.i_length) {
        i_max_len = i_length;
    } else {
        i_max_len = pcOther.i_length;
    }
    int* pi_new_table = new int[i_max_len + 1];

    int i_carry = 0;
    int i_sum = 0;

    for (int i = 0; i < i_max_len; i++) {
        int i_d1 = (i < i_length) ? pi_number[i] : 0;
        int i_d2 = (i < pcOther.i_length) ? pcOther.pi_number[i] : 0;

        i_sum = i_d1 + i_d2 + i_carry;
        pi_new_table[i] = i_sum % i_base;
        i_carry = i_sum / i_base;
    }

    int i_final_len = i_max_len;
    if (i_carry > 0) {
        pi_new_table[i_final_len] = i_carry;
        i_final_len++;
    }

    delete[] c_res.pi_number;
    c_res.pi_number = pi_new_table;
    c_res.i_length = i_final_len;

    return c_res;
}

CNumber CNumber::operator+(int iNewVal) {
    CNumber c_temp;
    c_temp = iNewVal;

    return (*this + c_temp);
}

std::string CNumber::sToString() {
    std::string s_number = "";
    if (b_isNegative) {
        s_number += "-";
    }
    for (int i = i_length - 1; i >= 0; i--) {
        s_number += std::to_string(pi_number[i]);
    }
    return s_number;
}
