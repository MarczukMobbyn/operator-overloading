#include "CNumber.h"

CNumber::CNumber(const CNumber &pcOther) {
    pi_number = NULL;
    *this = pcOther; //deep copy
}
CNumber::CNumber(int iBase) {
    i_length = NUMBER_DEFAULT_LENGTH;
    pi_number = new int[i_length];
    i_base = iBase;
    pi_number[0] = 0;
    b_isNegative = false;
    b_wasLastOperationSuccessful = true;
}

CNumber::CNumber() {
    i_length = NUMBER_DEFAULT_LENGTH;
    pi_number = new int[i_length];
    i_base = DEFAULT_BASE;
    pi_number[0] = 0;
    b_isNegative = false;
    b_wasLastOperationSuccessful = true;
};

CNumber& CNumber::operator=(const int iValue) {
    int i_value = abs(iValue);
    b_isNegative = (iValue < 0);

    int i_temp = i_value;
    int i_len = 0;
    do {
        i_len++;
        i_temp /= i_base;
    } while (i_temp > 0);

    int* pi_new = new int[i_len];

    i_temp = i_value;
    for (int i = 0; i < i_len; i++) {
        pi_new[i] = i_temp % i_base;
        i_temp /= i_base;
    }

    delete[] pi_number;
    pi_number = pi_new;
    i_length = i_len;
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

    if (this->i_base != pcOther.i_base) {
        CNumber c_other_copy = pcOther;
        c_other_copy.vChangeBase(this->i_base);
        return (*this + c_other_copy);
    }

    CNumber c_res;
    c_res.i_base = this->i_base;

    if (this->b_isNegative == pcOther.b_isNegative) {
        c_res.b_isNegative = this->b_isNegative;
    }
    //jesli znaki rozne to traktujemy to jako odejmowanie, ale jeszcze nie mam zaimplementowanego

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

CNumber CNumber::operator-(CNumber &pcOther) {
    if (this->i_base != pcOther.i_base) {
        CNumber c_other_copy;
        c_other_copy = pcOther;
        c_other_copy.vChangeBase(this->i_base);
        return (*this - c_other_copy);
    }

    // a - (-b) = a + b
    if (!this->bIsNegative() && pcOther.bIsNegative()) {
        CNumber c_temp;
        c_temp = pcOther;
        c_temp.b_isNegative = false;
        return (*this + c_temp);
    }
    // -a - b = -(a + b)
    else if (this->bIsNegative() && !pcOther.bIsNegative()) {
        CNumber c_temp;
        c_temp = *this;
        c_temp.b_isNegative = false;
        CNumber c_res;
        c_res = (c_temp + pcOther);
        c_res.b_isNegative = true;
        return (c_res);
    } // -a - (-b) = b - a
    else if (this->bIsNegative() && pcOther.bIsNegative()) {
        CNumber c_temp1, c_temp2;
        c_temp1 = *this;
        c_temp2 = pcOther;
        c_temp1.b_isNegative = false;
        c_temp2.b_isNegative = false;
        return (c_temp2 - c_temp1);
    }

    CNumber *pc_big = this;
    CNumber *pc_small = &pcOther;
    bool b_final_negative = false;

    if (!this->bIsGreaterOrEqual(pcOther)) {
        pc_big = &pcOther;
        pc_small = this;
        b_final_negative = true;
    }

    CNumber c_res;
    c_res.i_base = this->i_base;

    int* pi_new_table = new int[i_length];
    int i_borrow = 0;

    for (int i = 0; i < pc_big->i_length; i++) {
        int i_d1 = pc_big->pi_number[i];
        int i_d2 = (i < pc_small->i_length) ? pc_small->pi_number[i] : 0;

        int i_diff = i_d1 - i_d2 - i_borrow;
        if (i_diff < 0) {
            i_diff += i_base;
            i_borrow = 1;
        } else {
            i_borrow = 0;
        }
        pi_new_table[i] = i_diff;
    }

    //usuwanie zer i przypisanie
    int i_final_len = pc_big->i_length;
    while (i_final_len > 1 && pi_new_table[i_final_len - 1] == 0) {
        i_final_len--;
    }

    delete[] c_res.pi_number;
    c_res.pi_number = pi_new_table;
    c_res.i_length = i_final_len;
    c_res.b_isNegative = b_final_negative;

    return c_res;
}

CNumber CNumber::operator-(int iNewVal) {
    CNumber c_temp;
    c_temp = iNewVal;

    return (*this - c_temp);
}


CNumber CNumber::operator*(int iMult) {
    CNumber c_res;
    if (iMult == 0) {
        c_res = 0;
        return c_res;
    }

    int i_absMult = abs(iMult);
    c_res.i_base = this->i_base;

    //iMult length check
    int iMultLength = 0;
    int iMultCopy = i_absMult;
    while (iMultCopy > 0) {
        iMultLength++;
        iMultCopy /= i_base;
    }

    int i_newLength = i_length + iMultLength;
    int* pi_new_table = new int[i_newLength + 1]; //potencjalne przeniesienie
    int i_carry = 0;

    for (int i = 0; i < i_length; i++) {
        int i_prod = pi_number[i] * i_absMult + i_carry;
        pi_new_table[i] = (i_prod % i_base);
        i_carry = (i_prod / i_base);
    }

    int i_currentPos = i_length;
    while (i_carry > 0) {
        pi_new_table[i_currentPos] = i_carry % i_base;
        i_carry /= i_base;
        i_currentPos++;
    }

    delete[] c_res.pi_number;

    c_res.i_length = i_currentPos;
    c_res.pi_number = pi_new_table;
    c_res.b_isNegative = (this->b_isNegative != (iMult < 0));
    c_res.b_wasLastOperationSuccessful = true;

    return c_res;
}

CNumber CNumber::operator*(CNumber &pcOther) {
    if (this->i_base != pcOther.i_base) {
        CNumber c_other_copy = pcOther;
        c_other_copy.vChangeBase(this->i_base);
        return (*this * c_other_copy);
    }

    CNumber c_res(this->i_base);
    c_res = 0;

    //pobieramy this ale jako wartosc bezwzgledna
    CNumber c_this_abs = *this;
    c_this_abs.b_isNegative = false;

    for (int i = 0; i < pcOther.i_length; i++) {
        if (pcOther.pi_number[i] != 0) {

            CNumber c_step = c_this_abs * pcOther.pi_number[i];

            if (i > 0) {
                int i_new_len = c_step.i_length + i;
                int* pi_shifted = new int[i_new_len];

                for (int j = 0; j < i; j++) {
                    pi_shifted[j] = 0;
                }

                for (int j = 0; j < c_step.i_length; j++) {
                    pi_shifted[j + i] = c_step.pi_number[j];
                }

                delete[] c_step.pi_number;
                c_step.pi_number = pi_shifted;
                c_step.i_length = i_new_len;
            }

            c_res = c_res + c_step;
        }
    }

    if (this->bIsNegative() == pcOther.bIsNegative()) {
        c_res.b_isNegative = false;
    } else {
        c_res.b_isNegative = true;
    }

    if (c_res.i_length == 1 && c_res.pi_number[0] == 0) {
        c_res.b_isNegative = false;
    }

    return c_res;
}

bool CNumber::bIsGreaterOrEqual(CNumber &pcOther) {
    if (this->i_length > pcOther.i_length) {
        return true;
    } else if (this->i_length < pcOther.i_length) {
        return false;
    } else {
        for (int i = i_length - 1; i >= 0; i--) {
            if (pi_number[i] > pcOther.pi_number[i]) {
                return true;
            } else if (pi_number[i] < pcOther.pi_number[i]) {
                return false;
            }
        }
        return true; //sa rowne
    }
}

void CNumber::vChangeBase(int iNewBase) {
    if (i_base == iNewBase) return;

    CNumber c_new_val;
    c_new_val.i_base = iNewBase;
    c_new_val = 0;

    //algorytm Hornera
    for (int i = i_length - 1; i >= 0; i--) {
        CNumber c_temp_mult = c_new_val * i_base;
        c_new_val = c_temp_mult + pi_number[i];
    }

    c_new_val.b_isNegative = this->b_isNegative;
    *this = c_new_val;
    this->i_base = iNewBase;
}

std::string CNumber::sToString() {
    std::string s_number = "";
    if (b_isNegative) {
        s_number += "-";
    }
    for (int i = i_length - 1; i >= 0; i--) {
        s_number += std::to_string(pi_number[i]);
    }
    return s_number + "(base: " + std::to_string(i_base) + ")";
}
;