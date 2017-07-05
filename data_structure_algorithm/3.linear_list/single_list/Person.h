#ifndef	PERSON_H
#define PERSON_H

#include <string>
using namespace std;
class Person  
{
		friend ostream &operator<<(ostream &out, Person &person);
	public:
		string name;
		string phone;
		Person &operator=(Person &person); //对赋值符号进行重载
		bool operator==(Person &person);	//对==进行重载
};



#endif