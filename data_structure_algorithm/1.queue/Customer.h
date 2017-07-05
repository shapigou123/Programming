#ifndef __CUSTOMER_H__
#define	__CUSTOMER_H__

#include <string>
using namespace std;

class Customer
{
	public:
		//因为我们在MyQueue的构造函数中，用Customer实例化了一个对象数组，
		//此时需要Customer有默认的构造函数,解决方法是给构造函数中的每个参数赋初值
		Customer(string name = "", int age = 0);	
		void printInfo()const;
	private:
		string m_strName;	//普通数据类型，并不是指针，不需要考虑深拷贝浅拷贝的问题
		int m_iAge;
	
};

#endif