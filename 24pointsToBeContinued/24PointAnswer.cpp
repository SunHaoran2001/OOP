/*Step 1:
Program Plan: 
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
• In main function at first declare and initialize string and integer type variables.
• Declare two arrays to store card number and suit.
• Use for loop to generate (产生，生成) 4 random cards.
• Again use for loop to generate suit of 4 random cards. Use while loop inside for loop which till card does not have unique suit if two card are same.
• Use if-else statement to display card details appropriately on screen.
• After that read expression from user.
• If user entered 0 then call findsolution() function to determine possible solution.
• If use enters an expression then call determine() function to evaluate the user entered expression.
• At the end again use if-else statement to display message according to return value of determine() function.
*/
//Step2:
/**********************************************************
* Program to implement Test 24 card game *
**********************************************************/
//Header files
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <ctime>
#include <cstring>
//#include
using namespace std;
//store all possible combination of operator and operands
string final[10000];
int total_comb = 0;
//store all operator combination
string optr[64];
//store all operand combination
int perm[24][4];
//function prototypes
void swap(int *, int *);
bool checkPreced(char tr1, char tr2);
double checkOprtr(char tr, double d, double c);
//Step 3 :
//Function to convert character into double type number
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
// function to return true if first operator has greater
//precedence
bool checkPreced(char tr1, char tr2)
{
    //Use if else statement to return true and false according to precedence
    if (tr2 == '(' || tr2 == ')')
        return false;
    if ((tr1 == '*' || tr1 == '/') && (tr2 == '+' || tr2 == '-'))
        return false;
    else
        return true;
}
// function to perform operation on operand and then return
//value
double checkOprtr(char tr, double d, double c)
{
    //Use switch statement to perform different operation on different operator.
    switch (tr)
    {
    case '+':
        return c + d;
    case '-':
        return c - d;
    case '*':
        return c * d;
    case '/':
        if (d == 0)
            return 0;
        return c / d;
    }
    return 0;
}
//Step 6 :
// function to determine different operator combinations
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
        n++;

        //Step 7:
    }
}
//Step 8 :
// Function to take operands from user and determine
//operand combinations
void operandcombination(int card[4]) //permutations 排列或者组合(方式)
{
    int x, y, n = 4, count = 0, permutations = 1, p = 0, q = 0;
    vector<int> a;
    int t;
    //Use for loop to store 4 randomly generated operand (card).
    for (x = 0; x < n; x++)
    {
        a.push_back(card[x]);
    }
    //use for loop to calculate number of permutation
    for (x = 1; x <= n; x++)
    {
        permutations = permutations * x;
    }
    // Implement while loop to determine all permutation
    // sequence
    while (count < permutations)
    {
        //Use for loop to display n-1 permutation sequence.
        for (y = 0; y < n - 1; y++)
        {
            //Call swap() function to swap elements of vector in order to show permutation sequence.
            swap(&a[y], &a[y + 1]);
            //Use for loop to determine one permutation
            //sequence.
            for (x = 0; x < n; x++)
            {
                perm[p][q] = a[x];
                q++;
            }
            p++;
            q = 0;
            count++;
        }
        //Again swap() first and second element of array to determine permutation sequence.
        swap(&a[0], &a[1]);
        for (x = 0; x < n; x++)
        {
            perm[p][q] = a[x];
            q++;
        }
        p++;
        q = 0;
        count++;
        //Use for loop to display n-1 permutation sequence
        for (y = n - 1; y > 0; y--)
        {
            swap(&a[y], &a[y - 1]);
            for (x = 0; x < n; x++)
            {
                perm[p][q] = a[x];
                q++;
            }
            p++;
            q = 0;
            count++;
        }
        //Call swap() function to swap elements of vector in order to determine permutation sequence
        swap(&a[n - 1], &a[n - 2]);
        //Use for loop to show one permutation sequence
        for (x = 0; x < n; x++)
        {
            perm[p][q] = a[x];
            q++;
        }
        p++;
        q = 0;
        count++;
    }
}

//Step 9 :
//Function used to swap elements.
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
//Step 10 :
//Function to convert integer into string
string change(int n)
{
    string s;
    // Use if - else statement to convert number into string.
    if (n > 9)
    {
        s = '1';
        //convert number into string
        s = s + char(n % 10 + 48);
    }
    else
        //convert number into string
        s = char(n + 48);
    return s;
}
//Function to determine all possible combination to
//determine possible solution
void transformtostring();
void findsolution(int card[4])
{
    double eval = 0;
    //call function to determine all operator combination
    operatrcombination();
    // call function to determine all operand combination
    operandcombination(card);
    //call function to determine all possible combination
    transformtostring();
    //Use for loop to get one by one all expression from string and then evaluate.
    for (int i = 0; i < total_comb; i++)
    {
        //evaluate the expression
        eval = determine(final[i]);
        //check calculated value is 24
        if (eval == 24)
        {
            cout << "Sorry, one correct expression would be " << final[i] << endl;
            system("pause");
            exit(0);
        }
    }
    //display message no solution
    cout << "Yes. No 24 points " << endl;
    system("pause");
    exit(0);
}
//Function use to determine all possible expression.
void transformtostring()
{
    string t;
    int k = 0;
    //Use for loop to get one by one all combination operand.
    for (int i = 0; i < 24; i++)
    {
        int nd[4];
        //use for loop to copy one operand combination in
        //temporary array
        for (int w = 0; w < 4; w++)
        {
            nd[w] = perm[i][w];
        }
        //Use for loop to get one by one all operator combination.
        for (int j = 0; j < 64; j++)
        {
            string tor = optr[j];
            //first expression, the following line of
            //statement used to determine expression in one
            //form like A+B-C*D
            t = t + change(nd[0]);
            t = t + ' ' + tor[0];
            t = t + ' ' + change(nd[1]);
            t = t + ' ' + tor[1];
            t = t + ' ' + change(nd[2]);
            t = t + ' ' + tor[2];
            t = t + ' ' + change(nd[3]);
            final[k] = t;

            //Step 11 :
            k++;
            t = "";
            //second expression, the following line of
            //statement used to determine expression in one
            //form like (A+B)-C*D
            t = t + '(' + ' ' + change(nd[0]);
            t = t + ' ' + tor[0];
            t = t + ' ' + change(nd[1]) + ' ' + ')';
            t = t + ' ' + tor[1];
            t = t + ' ' + change(nd[2]);
            t = t + ' ' + tor[2];
            t = t + ' ' + change(nd[3]);
            final[k] = t;
            k++;
            t = "";
            //third expression, the following line of
            //statement used to determine expression in one
            //form like A+B-(C*D)
            t = t + change(nd[0]);
            t = t + ' ' + tor[0];
            t = t + ' ' + change(nd[1]);
            t = t + ' ' + tor[1] + ' ' + '(';
            t = t + ' ' + change(nd[2]);
            t = t + ' ' + tor[2];
            t = t + ' ' + change(nd[3]) + ' ' + ')';
            final[k] = t;
            k++;
            t = "";
            //fourth expression, the following line of
            //statement used to determine expression in one
            //form like (A+B)-(C*D)
            t = t + '(' + ' ' + change(nd[0]);
            t = t + ' ' + tor[0];
            t = t + ' ' + change(nd[1]) + ' ' + ')';
            t = t + ' ' + tor[1] + ' ' + '(';
            t = t + ' ' + change(nd[2]);
            t = t + ' ' + tor[2];
            t = t + ' ' + change(nd[3]) + ' ' + ')';
            final[k] = t;
            k++;
            t = "";
            //Fifth expression, the following line of
            //statement used to determine expression in one
            //form like (A+B-C)*D
            t = t + '(' + ' ' + change(nd[0]);
            t = t + ' ' + tor[0];
            t = t + ' ' + change(nd[1]);
            t = t + ' ' + tor[1];
            t = t + ' ' + change(nd[2]) + ' ' + ')';
            t = t + ' ' + tor[2];
            t = t + ' ' + change(nd[3]);
            final[k] = t;
            k++;
            t = "";
            //Sixth expression, the following line of
            //statement used to determine expression in one
            //form like A+(B-C*D)
            t = t + change(nd[0]);
            t = t + ' ' + tor[0];
            t = t + ' ' + '(' + ' ' + change(nd[1]);
            t = t + ' ' + tor[1];
            t = t + ' ' + change(nd[2]);
            t = t + ' ' + tor[2];
            t = t + ' ' + change(nd[3]) + ' ' + ')';
            final[k] = t;
            k++;
            t = "";
        }
    }
    //store number of possible combination
    total_comb = k;
}
//Function to check card number has same suit
bool check(int tempcar[4], int c, int d, int cardsuit[4])
{
    //Use for loop to determine cards has same suit.
    for (int i = 0; i < 4; i++)
    {
        if (tempcar[i] == c)
        {
            //ith card has same suit number
            if (cardsuit[i] == d)
                return false;
        }
    }
    return true;
}

//Step 12 :
//function to return suit according to passed value
string suit(int t3)
{
    //Use switch statement to return suit according to value of t3.
    switch (t3)
    {
    case 0:
        return "Clubs";
    case 1:
        return "Diamonds";
    case 2:
        return "Spades";
    case 3:
        return "Hearts";
    }
}
//Function to execute program
int main()
{
    //Declare and initialize string, integer type
    //variables.
    double eval1 = 0;
    int t3;
    string exprsn;
    //function to randomly generate value
    srand(time(0));
    bool che = false;
    //arrays to store card numbers their suits
    int card[4] = {0};
    int cardsuit[4] = {5, 5, 5, 5};
    int t2 = 0;
    //Use for loop to generate 4 random cards.
    for (int i = 0; i < 4; i++)
    {
        //randomly generate number between 1 and 13
        t2 = rand() % 13 + 1;
        card[i] = t2;
    }
    //Use for loop to generate suit of 4 random cards.
    for (int i = 0; i < 4; i++)
    {
        //loop continues iterate till card does not
        //have unique suit if two card are same.
        while (che == false)
        {
            t3 = rand() % 4;
            che = check(card, card[i], t3, cardsuit);
        }
        cardsuit[i] = t3;
        //Use if - else statement to display card details appropriately on screen.
        if (card[i] == 1)
            cout << "Ace (1) of " << suit(t3);
        else if (card[i] > 1 && card[i] <= 10)
            cout << card[i] << " of " << suit(t3);
        else if (card[i] == 11)
            cout << "Jack (11) of " << suit(t3);
        else if (card[i] == 12)
            cout << "Queen (12) of " << suit(t3);
        else
            cout << "King (13) of " << suit(t3);
        //reset value for next iteration
        che = false;
        cout << endl;
    }
    cout << "Please give space between operator, operand and parenthesis" << endl;
    cout << "Enter an expression: ";
    //read expression from user
    getline(cin, exprsn);
    //Use if - else statement to call findsolution() function if user does not know answer, other evaluate the user entered expression.
    if (exprsn.compare("0") == 0)
    {
        cout << "";
        //call function to determine solution
        findsolution(card);
    }
    else
    {
        //call function to evaluate expression
        eval1 = determine(exprsn);
    }
    //Use if - else statement to display message according to return value of determine() function.
    if (eval1 == 24)
    {
        //display win message

        //Step 13 :
        cout << "Congratulation! You got it! " << endl;
        system("pause");
        exit(0);
    }
    else //display lose message
        cout << "Sorry! You lose! " << endl;
    findsolution(card);
    cout << endl;

    system("pause");
    return 0;
}