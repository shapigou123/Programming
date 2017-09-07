#include <iostream>
using namespace std;
#pragma pack(1)	//结构体1字节对齐
struct student
{
	int a;	//4
	char b;	//4
	float c;//8
	double d;//8
};

int main()
{
	int len = sizeof(struct student);
	cout << len <<endl;
	return 0;
}