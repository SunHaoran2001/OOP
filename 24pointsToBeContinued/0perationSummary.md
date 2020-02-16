# 24点操作总结
---
Summary
>Program Plan:      
• Declare a final[], optr[] and perm[][] array to store all possible combinations of operands and operators.    
• Define following function:     
• converttonum() Function to convert character into number.    
• determine()Function used to evaluate an expression.     
• checkPreced() Function used to check precedence（优先） of operation which is required in evaluating expression.7      
• checkOprtr()Function used to perform operation like addition, subtraction, multiplication and division on operands.       
• operatrcombination()Function used to determine all possible combination of operators.      
• operandcombination()Function used to determine all possible combination of operands.     
• swap()Function used to swap array element which is required in determining operand combination.        
• change() Function used to convert integer number into string.      
• transformtostring()Function used to determine all possible combination of operator and operands with and without parenthesis.     
• Findsolution()Function used to determine all possible combination by calling different functions and then use for loop to get 
one by one all expression from string and then evaluate to display correct expression if it is possible.     
• check()Function to check same card number has same suit       
• suit()Function used to return suit according to pass value    
• main() function to execute the program:    
• In main function at first declare and initialize      string and integer type variables.       
• Declare two arrays to store card number and suit.    
• Use for loop to generate (产生，生成) 4 random cards.    
• Again use for loop to generate suit of 4 random      cards. Use while loop inside for loop which till card does not have unique suit if two card are same.    
• Use if-else statement to display card details appropriately on screen.   
• After that read expression from user.   
• If user entered 0 then call findsolution() function to determine possible solution.    
• If use enters an expression then call determine() function to evaluate the user entered expression.    
• At the end again use if-else statement to display message according to return value of determine() function.     

1.converttonum
===============
转换为数字
```C++
double converttonum(char t[2], int h)
{
    double num;
    //check number is less than 10
    if (h == 0)
        num = t[0] - 48;
    //check number is greater than or equal to 10
    if (h == 1)
        num = 10 + t[1] - 48;
    return num;
}
```
2.determine()
=============

determine()的主要功能是，根据优先级计算表达式

首先他接收一个string类型表达式，转换为char类型的数组piece。
计算表达式首先定义两个栈，一个存放操作数
一个存放操作符
对新的char数组进行遍历，遇到空格跳过，如果遇到0~9的字符。

```C++
//Function to evaluate the
double determine(string exp)
{
    //determine size of string

    //Step 4 :
    int s = exp.size();
    char piece[s];
    //Use for loop to copy all characters from string to character array.
    for (int j = 0; j < s; j++)
    {
        piece[j] = exp[j];
    }
    // Stack for numbers
    stack<double> numbers;
    // Stack for Operators
    stack<char> oprtr;
    for (int i = 0; i < s; i++)
    {
        // skip white space it
        if (piece[i] == ' ')
            continue;
        // check current character is a number
        if (piece[i] >= '0' && piece[i] <= '9')
        {
            // temporary array to store number
            char t[2];
            int h = -1;
            // use while loop to extract number from
            //string
            while (i < s && piece[i] >= '0' && piece[i] <= '9')
            {
                h++;
                t[h] = piece[i++];
            }
            //convert character into number
            double val = converttonum(t, h);
            numbers.push(val);
        }
        // check current character is a (
        else if (piece[i] == '(')
            oprtr.push(piece[i]);
        // check current character is a)
        else if (piece[i] == ')')
        {
            //Use while loop to pop all values from stack till closing parenthesis is not encountered.
            while (oprtr.top() != '(')
            {
                // get top element from operator stack
                char op = oprtr.top();
                //remove top element from operator
                //stack
                oprtr.pop();
                //get top two elements from stack
                double val1 = numbers.top();
                numbers.pop();
                double val2 = numbers.top();
                numbers.pop();
                //perform operation on operands
                double ret = checkOprtr(op, val1, val2);
                numbers.push(ret);
            }
            oprtr.pop();
        }
        // check current character is operator
        else if (piece[i] == '+' || piece[i] == '-' ||
                 piece[i] == '*' || piece[i] == '/')
        {
            //Use while loop to check top operator has greater precedence.
            while (!oprtr.empty() && checkPreced(piece[i], oprtr.top()))
            {
                //get operand and operators from stack
                char op = oprtr.top();
                oprtr.pop();
                double val1 = numbers.top();
                numbers.pop();
                double val2 = numbers.top();
                numbers.pop();
                double ret = checkOprtr(op, val1, val2); //Evaluatoin
                numbers.push(ret);
            }
            // push new character into stack
            oprtr.push(piece[i]);
        }
    }

    //Step 5 :
    // loop to apply operation on remaining part of
    //expression
    while (!oprtr.empty())
    {
        char op = oprtr.top();
        oprtr.pop();
        double val1 = numbers.top();
        numbers.pop();
        double val2 = numbers.top();
        numbers.pop();
        double ret = checkOprtr(op, val1, val2);
        numbers.push(ret);
    }
    //top of stack contain the resultant value
    double t = numbers.top();
    numbers.pop();
    return t;
}
```
