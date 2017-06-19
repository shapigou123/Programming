#include <iostream>
#include <string>
#include "myclass.h"

using namespace std;

int main()
{
	string name = "hello world";
	cout<<name.size()<<endl;
	Teacher t1;
	Teacher t2("Merry", 15);
	Teacher t3("shabi");
	cout<<t1.getName()<<" "<<t1.getAge()<<endl;
	cout<<t2.getName()<<" "<<t2.getAge()<<endl;
	cout<<t3.getName()<<" "<<t3.getAge()<<endl;
	return 0;
}
