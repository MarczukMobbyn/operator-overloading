#include <iostream>

#include "CNumber.h"

int main() {
    CNumber num1;
    num1 = -12345;
    std::cout << num1.sToString() << std::endl;
    return 0;
}
