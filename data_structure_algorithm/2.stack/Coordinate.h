#ifndef COORDINATE_H
#define COORDINATE_H

#include<ostream>
using namespace std;
class Coordinate
{
	//定义一个友元函数
	friend ostream &operator<<(ostream &out,Coordinate &coor);
	public:
		Coordinate(int x=0, int y=0);
		void printCoordinate();
	private:
		//若为复杂数据类型，比如指针。就要写拷贝构造函数，赋值运算符
		int m_iX;	//这里简单数据类型，使用默认的拷贝构造函数和默认的赋值运算符重载
		int m_iY;
};
















#endif