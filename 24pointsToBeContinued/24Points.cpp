#include <iostream>
#include "DeckOfCardsUsingVector.cpp"
#include "EvaluateExpression.cpp"
using namespace std;

int main()
{
     //obtain the cards
     getCard();
     //the number of the cards
     cout << deck[0] % 13 + 1 << endl
          << deck[1] % 13 + 1 << endl
          << deck[2] % 13 + 1 << endl
          << deck[3] % 13 + 1 << endl;

     string expression;
     cout << "Enter an expression:";
     getline(cin, expression);

     cout << expression << " = "
          << evaluateExpression(expression) << endl;
     return 0;
}