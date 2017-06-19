#ifndef __MYCLASS_H__
#define	__MYCLASS_H__

#include <iostream>
#include <string>

using namespace std;
class Teacher
{
public:
	Teacher();
	Teacher(string name, int age =20);
	void setName(string name);
	string getName();
	void setAge(int age);
	int getAge();
private:
	string m_strName;
	int m_Age;
};

Teacher::Teacher()
{
	m_strName = "yuyang";
	m_Age = 24;
	cout<<"Teacher()"<<endl;
}

Teacher::Teacher(string name,int age)
{
	m_strName = name;
	m_Age = age;
	cout<<"Teacher(string name,int age)"<<endl;
}

void Teacher::setName(string name)
{
	m_strName = name;
}

string Teacher::getName()
{
	return m_strName;
}

void Teacher::setAge(int age)
{
	m_Age = age;
}

int Teacher::getAge()
{
	return m_Age;
}

#endif