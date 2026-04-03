#include <iostream>

#include "CNumber.h"

int main() {
    CNumber num1, num3;
    CNumber num2(2);
    num1 = 20;
    num2 = -10;
    num3 = num1 + num2;
    std::cout << "num1: " << num1.sToString() << std::endl;
    std::cout << "num2: " << num2.sToString() << std::endl;
    std::cout << "num3: " << num3.sToString() << std::endl;




    return 0;
}
