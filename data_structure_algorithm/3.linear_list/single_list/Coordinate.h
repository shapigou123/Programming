#ifndef COORDINATE_H
#define COORDINATE_H

#include<ostream>
using namespace std;
class Coordinate
{
	//����һ����Ԫ����
	friend ostream &operator<<(ostream &out,Coordinate &coor);
	public:
		Coordinate(int x=0, int y=0);
		void printCoordinate();
		//ֻ�贫��һ����������ǰ��������ǵ�һ������
		bool operator==(Coordinate &coor);
	private:
		//��Ϊ�����������ͣ�����ָ�롣��Ҫд�������캯������ֵ�����
		int m_iX;	//������������ͣ�ʹ��Ĭ�ϵĿ������캯����Ĭ�ϵĸ�ֵ���������
		int m_iY;
};
















#endif