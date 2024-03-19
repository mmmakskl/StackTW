#pragma once
#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
#include <cstring>
#include <string>
#include "exception.hpp"

void test();

int getPriority(char item);

bool isOperator(char item);

void getPostfixFromInfix(const std::string& infix, std::string& postfix, const size_t stackSize);

int evaluatePostfix(const std::string& postfix, const size_t stackSize);

std::ostream& operator<<(std::ostream& out, const std::string& postfix);

template<typename T>
class Stack
{
public:
    virtual ~Stack() {}
    virtual void push(const T& e) = 0;
    virtual T pop() = 0;
    virtual bool isEmpty() = 0;
};

/* 
* Initialization and definition of the StackArray class:
*/
template<typename T>
class StackArray : public Stack<T>
{
private:
    std::size_t size_;
    int top_;
    T* array_;
    void swap(StackArray<T>& src)
    {
        std::swap(array_, src.array_);
        std::swap(top_, src.top_);
        std::swap(size_, src.size_);
    }

public:
    StackArray(size_t size = 100);
    ~StackArray();

    void push(const T& e) override;
    T pop() override;
    bool isEmpty() override;
    
	T Top() const;
    T& operator[](size_t top);
    int getTop();
};

template <typename T>
inline StackArray<T>::StackArray(size_t size) :
    size_(size), 
    top_(-1)
{
    if(size < 0)
    {
        throw WrongStackSize();
    }
    array_ = new T[size];
}

template <typename T>
inline StackArray<T>::~StackArray()
{
    delete[] array_;
}

template <typename T>
inline void StackArray<T>::push(const T &e) 
{
    if (top_ + 1 == size_)
    {
        throw StackOverflow();
    }
    array_[++top_] = e;
}

template <typename T>
inline T StackArray<T>::pop() 
{
    if (isEmpty())
    {
        throw StackUnderflow();
    }
    return array_[top_--];
}

template <typename T>
inline bool StackArray<T>::isEmpty() 
{
    return (top_ == -1);
}

template <typename T>
T StackArray<T>::Top() const
{
	return array_[top_];
}

template<typename T>
int StackArray<T>::getTop()
{
    return top_;
}

template <typename T>
T &StackArray<T>::operator[](size_t top)
{
    T* array = array_;
    return array[top];
}

#endif


