#include<iostream>

using namespace std;
class Bug
{
private:
	int nlegs;
	int nColor;
public:
	int ntype;
	Bug(int legs, int color);
	void PrintBug() {};
};
class FlyBug :public Bug
{
	int nWings;
public:
	FlyBug(int legs, int color, int wings);
};

Bug::Bug(int legs, int color) :nlegs(legs), nColor(color) {};

FlyBug::FlyBug(int legs, int color, int wings) :Bug( legs, color)
{
	nWings = wings;
}

int main()
{
	FlyBug F1(1 , 2 , 3);
	return 0;
}