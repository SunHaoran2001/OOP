#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "ImprovedStack.h"

using namespace std;

//split: split(divide)  an expression into numbers , operators and parentheses( "()" )
vector<string> split(const string &expression);
//Evaluate an expression and return the result
int evaluateExpression(const string &expression);
//Perform an operation
void processAnOperator(
    Stack<int> &operandStack, Stack<char> &operatorStack);

int main()
{
    string expression;
    cout << "Enter an expression:";
    getline(cin, expression);

    cout << expression << " = "
         << evaluateExpression(expression) << endl;

    return 0;
}

vector<string> split(const string &expression)
{
    vector<string> v;    //A vector to store split items as strings
    string numberString; //A numeric string

    for (unsigned i = 0; i < expression.size(); ++i)
    {
        if (isdigit(expression[i]))
            numberString.append(1, expression[i]); //Append a digit
        else
        {
            if (numberString.size() > 0)
            {
                v.push_back(numberString); //Store the numeric string
                numberString.erase();      //Empty the numeric string
            }

            if (!isspace(expression[i]))
            {
                string s;
                s.append(1, expression[i]);
                v.push_back(s); //Store an operator and parenthesis
            }
        }
    }
    //Store the last numeric string
    if (numberString.size() > 0)
    {
        v.push_back(numberString);
    }
    return v;
}

//Evaluate an expression
int evaluateExpression(const string &expression)
{
    //Create operandStack to store operands
    Stack<int> operandStack;

    //Create operatorStack to store operators
    Stack<char> operatorStack;

    //Extract operands and operators
    vector<string> tokens = split(expression);

    //Phase 1:scan tokens
    for (unsigned i = 0; i < tokens.size(); ++i)
    {
        if (tokens[i][0] == '+' || tokens[i][0] == '-')
        {
            //process all + , - , * , / in the top of the operator stack
            while (!operatorStack.empty() && (operatorStack.peek() == '+') || (operatorStack.peek() == '-') || (operatorStack.peek() == '*') || (operatorStack.peek() == '/'))
            {
                processAnOperator(operandStack, operatorStack);
            }

            // Push the + or - operator into operator stack
            operatorStack.push(tokens[i][0]);
        }
        else if (tokens[i][0] == '*' || tokens[i][0] == '/')
        {
            //Process all * , / in the top of the operator stack
            while (!operatorStack.empty() && (operatorStack.peek() == '*' || operatorStack.peek() == '/'))
            {
                processAnOperator(operandStack, operatorStack);
            }

            //Push the * or / operator into the operator stack
            operatorStack.push(tokens[i][0]);
        }
        else if (tokens[i][0] == '(')
        {
            operatorStack.push('('); //Push '(' to stack
        }
        else if (tokens[i][0] == ')')
        {
            //process al operators in the stack until seeing '('
            while (operatorStack.peek() != '(')
            {
                processAnOperator(operandStack, operatorStack);
            }

            operatorStack.pop();
        }
        else
        {
            operandStack.push(atoi(tokens[i].c_str()));
        }
    }

    //Phase 2: process all the remaining operators in the stack
    while (!operatorStack.empty())
    {
        processAnOperator(operandStack, operatorStack);
    }

    //return a result
    return operandStack.pop();
}

//Process one operator: Take an operator from operatorStack and
//apply it on the operands in the operandStack
void processAnOperator(
    Stack<int> &operandStack, Stack<char> &operatorStack)
{
    char op = operatorStack.pop();
    int op1 = operandStack.pop();
    int op2 = operandStack.pop();
    if (op == '+')
        operandStack.push(op2 + op1);
    else if (op == '-')
        operandStack.push(op2 - op1);
    else if (op == '*')
        operandStack.push(op2 * op1);
    else if (op == '/')
        operandStack.push(op2 / op1);
}