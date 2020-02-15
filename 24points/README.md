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