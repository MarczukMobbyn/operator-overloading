#ifndef LISTA2_DIVIDEDBYZEROEXCEPTION_H
#define LISTA2_DIVIDEDBYZEROEXCEPTION_H
#define DIVIDED_BY_ZERO_MESSAGE "Division by zero is not allowed."
#include <exception>

class DividedByZeroException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return DIVIDED_BY_ZERO_MESSAGE;
    }
};

#endif //LISTA2_DIVIDEDBYZEROEXCEPTION_H