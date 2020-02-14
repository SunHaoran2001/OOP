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
//创建派生类的对象时，需要调用基类的构造函数:初始化派生类对象中从基类继承的成员。
//在执行一个派生类的构造函数之前，总是先执行基类的构造函数。
FlyBug::FlyBug(int legs, int color, int wings) :Bug( legs, color)
{
	nWings = wings;
}

int main()
{



	return 0;
}