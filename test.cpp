#include "Stack.hpp"

void test()
{
    std::cout << "Test 1: Simple arithmetic expression without parentheses:" << std::endl;
    {
        const std::string infix = "3+4*2";
        size_t stackSize = infix.size();
        std::string postfix;
        getPostfixFromInfix(infix, postfix, stackSize);
        std::cout << infix << " -> " << postfix << std::endl;
        std::cout << "sum of " + postfix + " : " << evaluatePostfix(postfix, stackSize) << std::endl << std::endl;
    }

    std::cout << "Test 2: Arithmetic expression with different operations and parentheses:" << std::endl;
    {
        const std::string infix = "2*3/(2-1)+4";
        size_t stackSize = infix.size();
        std::string postfix;
        getPostfixFromInfix(infix, postfix, stackSize);
        std::cout << infix << " -> " << postfix << std::endl;
        std::cout << "sum of " + postfix + " : " << evaluatePostfix(postfix, stackSize) << std::endl << std::endl;
    }

    std::cout << "Test 3: Arithmetic expression with multiple parentheses:" << std::endl;
    {
        const std::string infix = "((3+4)*2-1)/5";
        size_t stackSize = infix.size();
        std::string postfix;
        getPostfixFromInfix(infix, postfix, stackSize);
        std::cout << infix << " -> " << postfix << std::endl;
        std::cout << "sum of " + postfix + " : " << evaluatePostfix(postfix, stackSize) << std::endl << std::endl;
    }

    std::cout << "Test 4: Arithmetic expression with one digit:" << std::endl;
    {
        const std::string infix = "9";
        size_t stackSize = infix.size();
        std::string postfix;
        getPostfixFromInfix(infix, postfix, stackSize);
        std::cout << infix << " -> " << postfix << std::endl;
        std::cout << "sum of " + postfix + " : " << evaluatePostfix(postfix, stackSize) << std::endl << std::endl;
    }

    std::cout << "Test 5: Arithmetic expression with spaces:" << std::endl;
    {
        const std::string infix = "1 + 2 * (7 - 2) / 5";
        size_t stackSize = infix.size();
        std::string postfix;
        getPostfixFromInfix(infix, postfix, stackSize);
        std::cout << infix << " -> " << postfix << std::endl;
        std::cout << "sum of " + postfix + " : " << evaluatePostfix(postfix, stackSize) << std::endl << std::endl;
    }
}