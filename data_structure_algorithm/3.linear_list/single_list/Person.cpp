#include "Person.h"

#include<ostream>
using namespace std;
//��������Person����࣬��ֻ��һ��ȫ�ֺ���������ֻ����
//����д������
ostream &operator<<(ostream &out, Person &person)
{
	out<<person.name<<"-------"<<person.phone<<endl;
	return out;
}

//��ֵ�������������Ϊһ��������˵����Person�����ĳ�Ա����
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