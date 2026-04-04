PROJECT OVERVIEW
This project implements the CNumber class in C++, designed to perform mathematical operations on integers of arbitrary size, limited only by the available system memory. The implementation supports various numeral systems (bases) and ensures robust management of dynamic resources.

KEY FEATURES

Multi-Base Support: The class allows for defining a specific base (e.g., base 2 or base 10) and handles automatic base conversion during operations between different CNumber objects.

Operator Overloading: Provides a natural syntax by overloading standard arithmetic operators (+, -, *, /) and assignment operators for both int and CNumber types.

Memory Management: Utilizes dynamic integer arrays to store digits, allowing for flexible scaling of number length.

Exception Handling: Includes a custom exception mechanism (DividedByZeroException) to handle illegal operations, such as division by zero.

TECHNICAL DETAILS

Memory and Lifecycle: Adheres to the "Rule of Three" by implementing a destructor, copy constructor, and assignment operator to ensure deep copying and prevent memory leaks.

Algorithmic Approach:

Internal Representation: Digits are stored in reverse order (least significant digit first) to simplify the implementation of arithmetic algorithms.

Base Conversion: Employs Horner's method for efficient conversion between different numeral systems.

Division: Implements a long division algorithm to handle large-scale quotients and remainders.

Efficiency: Methods utilize references for object parameters to minimize unnecessary data copying during complex calculations.

FILE STRUCTURE

CNumber.h / CNumber.cpp: Core class logic, including operator definitions and arithmetic algorithms.

DividedByZeroException.h: Definition of a custom exception class inheriting from std::exception.

main.cpp: Demonstration of usage, showcasing object initialization, arithmetic operations, and exception catching.

IMPLEMENTATION EXAMPLE
CNumber num1;
num1 = 100;                   // Assigning from an int
CNumber num2(2);              // Initializing in binary system
num2 = 10;
CNumber result = num1 / num2; // Operations with automatic base synchronization
