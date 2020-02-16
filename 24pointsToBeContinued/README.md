# 24点
- - -

介绍
====
24点游戏的规则如下：
从52张牌（去掉大小王）中抽出任意4张牌，每张牌代表一个数，从1到13。编写一个程序，随机选择4张牌，提示用户输入一个表达式，该表达式由选择的4张牌代表的4个数字组成，每个数字必须使用，且只能使用一次，表达式可以按任意组合使用运算符（加减乘除）以及括号。该表达式的计算结果必须为24.如果这样的表达式不存在，输入0.下面是样例运行：

>4 of Clubs   
Ace (1) of Diamonds   
6 of Hearts    
Jack (11) of Clubs    
Enter an expression: (13 - 9) * (1 + 5)←Enter   
Congratulations! You got it!

>Ace (1) of Diamonds     
5 of Diamonds     
9 of Spades     
Queen (12) of Hearts
Enter an expression: (13 - 9) * (1 + 5)←Enter      
Congratulations! You got it!       

>6 of Clubs    
5 of Clubs    
Jack (11) of Clubs   
5 of Spades   
Enter an expression: 0←Enter    
Sorry, one correct expression would be (5 * 6) - (11 - 5)   

>6 of Clubs   
5 of Clubs    
Queen (12) of Clubs   
5 of Spades    
Enter an expression: 0←Enter     
Yes, No 24 points   



解决方案
1）计算
2）枚举所有排列方式
1.枚举运算符
```C++
void operatrcombination()
{
    //declare a string variable
    string s = "+-/*";
    //declare and initialize an integer variable
    int l, m, n, t;
    l = 0;
    m = 0;
    n = 0;
    t = 0;
    //Use for loop to determine all operator combinations and simultaneously(同时地) store it in array
    for (int i = 0; i < 64; i++)
    {
        //check value of i is divisible by 4
        t = i % 4;
        //use if statement to set and reset the second and
        //last character in each string
        if (t == 0 && i != 0)
        {
            m++;
            n = 0;
        }
        //use if statement to reset the first character in
        //each string
        if (i % 16 == 0 && i != 0)
        {
            l++;
            m = 0;
        }
        //concatenate the string to determine operator
        //combination.
        optr[i] = optr[i] + s[l];
        optr[i] = optr[i] + s[m];
        optr[i] = optr[i] + s[n];
        //四个数字三个运算符
        n++;
    }
}
```