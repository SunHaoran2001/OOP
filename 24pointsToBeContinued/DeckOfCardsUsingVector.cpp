#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

const int NUMBER_OF_CARDS = 52;
string suits[4] = {"spades", "Heart", "Diamonds", "Clubs"};
string ranks[13] = {"Ace (1)", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack (11)", "Queen (12)", "King (13)"};
vector<int> deck(NUMBER_OF_CARDS);

void getCard()
{
	for (int i = 0; i < NUMBER_OF_CARDS; ++i)
	{
		deck[i] = i;
	}

	srand(time(0));
	int index, temp;
	for (int i = 0; i < NUMBER_OF_CARDS; ++i)
	{
		index = rand() % NUMBER_OF_CARDS;
		temp = deck[i];
		deck[i] = deck[index];
		deck[index] = temp;
	}

	for (int i = 0; i < 4; ++i)
	{
		cout << ranks[deck[i] % 13] << " of " << suits[deck[i] / 13] << endl;
	}
}