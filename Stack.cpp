#include "Stack.hpp"

bool isOperator(char item)
{
    return item == '-' || item == '+' || item == '*' || item == '/';
}

bool isBrackets(char item)
{
    return item == '(' || item == ')';
}

int getPriority(char item)
{
    if(item == '*' || item == '/')
        return 3;
    if(item == '+' || item == '-')
        return 2;
    if(item == ')')
        return 1;
    else
        return 0;
}

void getPostfixFromInfix(const std::string& infix, std::string& postfix, const std::size_t stackSize)
{
    StackArray<char> PostfromInf(stackSize);
    for(char c : infix)
    {
        if(c == ' ')
        {
            continue;
        }
        if(!isOperator(c) && !isBrackets(c))
            postfix += c;
        else if(isOperator(c))
        {
            if(PostfromInf.isEmpty())
                PostfromInf.push(c);
            else
            {
                while(!PostfromInf.isEmpty() && getPriority(PostfromInf.Top()) >= getPriority(c))
                {
                    postfix += PostfromInf.Top();
                    PostfromInf.pop();
                }
                if(!PostfromInf.isEmpty() && getPriority(PostfromInf.Top()) < getPriority(c))
                    PostfromInf.push(c);
                else if(PostfromInf.isEmpty())
                    PostfromInf.push(c);
                    
            }
        }
        else if(c == '(')
            PostfromInf.push(c);
        else if(getPriority(c) == 1)
        {
            while (PostfromInf.Top() != '(')
            {
                postfix += PostfromInf.Top();
                PostfromInf.pop();          
            }
            PostfromInf.pop();
        }
    }
    while (!PostfromInf.isEmpty())
    {
        postfix += PostfromInf.Top();
        PostfromInf.pop();        
    }
}

int evaluatePostfix(const std::string& postfix, const size_t stackSize)
{
    StackArray<int> operands(stackSize);
    for(char c : postfix)
    {
        if(isdigit(c))
            operands.push(c - '0');
        else if(isOperator(c))
        {
            if (operands.getTop() + 1 < 2) {
                throw NotEnoughOperands();
            }
            int a2 = operands.Top();
            operands.pop();
            int a1 = operands.Top();
            operands.pop();
            int result;
            switch (c)
            {
                case '+':
                    result = a1 + a2;
                    break;
                case '*':
                    result = a1 * a2;
                    break;
                case '-':
                    result = a1 - a2;
                    break;
                case '/':
                    if(a2 == 0)
                        throw DivisionByZero();                    
                    result = a1 / a2;
                    break;
            }
            operands.push(result);
        }
        else
        {
            throw InvalidСharacter();
        }
    }
    if (operands.getTop() != 1) {
        throw WrongExpression();
    }
    return operands.Top();
}

std::ostream& operator<<(std::ostream& out, const std::string& postfix)
{
    for(char c : postfix)
        out << c;
    return out;
}
