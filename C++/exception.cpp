#include <iostream>

using namespace std;

void fun(int a)
{
	if(a == 0)
		throw 1;
	cout << "try" <<endl;
}

int main()
{
	int a = 1;
	try
	{
		fun(a);
	}
	catch(int)
	{
		cout << "catch" << endl;
	}
	return 0;
}