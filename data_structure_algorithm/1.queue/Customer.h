#ifndef __CUSTOMER_H__
#define	__CUSTOMER_H__

#include <string>
using namespace std;

class Customer
{
	public:
		//��Ϊ������MyQueue�Ĺ��캯���У���Customerʵ������һ���������飬
		//��ʱ��ҪCustomer��Ĭ�ϵĹ��캯��,��������Ǹ����캯���е�ÿ����������ֵ
		Customer(string name = "", int age = 0);	
		void printInfo()const;
	private:
		string m_strName;	//��ͨ�������ͣ�������ָ�룬����Ҫ�������ǳ����������
		int m_iAge;
	
};

#endif