#pragma once
#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP
#include <iostream>
#include <exception>

class StackOverflow : public std::exception
{
private:
    const char* reason_;
public:
    StackOverflow() : reason_("Stack Overflow") {}
    const char* what() const noexcept override { return reason_; }
};

class StackUnderflow : public std::exception
{
private:
    const char* reason_;
public: 
    StackUnderflow() : reason_("Stack Underflow") {}
    const char* what() const noexcept override { return reason_; }
};

class WrongStackSize : public std::exception
{
private:
    const char* reason_;
public:
    WrongStackSize() : reason_("Wrong Stack Size") {}
    const char* what() const noexcept override { return reason_; }
};

class DivisionByZero : public std::exception
{
private:
    const char* reason_;
public:
    DivisionByZero() : reason_("Division by zero is impossible") {}
    const char* what() const noexcept override { return reason_; }
};

class NotEnoughOperands : public std::exception
{
private:
    const char* reason_;
public:
    NotEnoughOperands() : reason_("There are not enough operands to execute the operator") {}
    const char* what() const noexcept override { return reason_; }
};

class WrongExpression : public std::exception
{
private:
    const char* reason_;
public:
    WrongExpression() : reason_("Incorrect postfix expression") {}
    const char* what() const noexcept override { return reason_; }
};

class InvalidСharacter : public std::exception
{
private:
    const char* reason_;
public:
    InvalidСharacter() : reason_("Invalid character") {}
    const char* what() const noexcept override { return reason_; }
};

#endif