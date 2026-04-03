#include <iostream>

#include "CNumber.h"
#include "DividedByZeroException.h"

int main() {
    CNumber num1, num3;
    CNumber num2(2);
    num1 = 20;
    num2 = 0;
    try {
        num3 = num1 / 0;
    }
    catch (const DividedByZeroException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "num1: " << num1.sToString() << std::endl;
    std::cout << "num2: " << num2.sToString() << std::endl;
    std::cout << "num3: " << num3.sToString() << std::endl;




    return 0;
}
