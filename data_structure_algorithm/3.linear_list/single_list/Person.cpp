#include "Person.h"

#include<ostream>
using namespace std;
//并不属于Person这个类，它只是一个全局函数，我们只不过
//把它写到这里
ostream &operator<<(ostream &out, Person &person)
{
	out<<person.name<<"-------"<<person.phone<<endl;
	return out;
}

//赋值运算符的重载作为一个函数来说属于Person这个类的成员函数
Person &Person::operator=(Person &person)
{
	this->name = person.name;
	this->phone = person.phone;
	return *this;
}

bool Person::operator==(Person &person)
{
	if(this->name == person.name && this->phone == person.phone)
		return true;
	else
		return false;
}