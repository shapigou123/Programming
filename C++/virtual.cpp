#include <iostream>

using namespace std;

class Shape
{
public:
	Shape();
	virtual ~Shape();
	#if 0
	virtual double calcArea()
	{
		cout << "Shape virtual calcArea" << endl;
	}
	#endif
	//类内声明，类外定义虚函数
	virtual double calcArea();
};

Shape::Shape()
{
	cout << "Shape constructor" <<endl;
}

Shape::~Shape()
{
	cout << "Shape destructors" <<endl;
}

double Shape::calcArea()
{
	cout << "Shape virtual calcArea" << endl;
}

class Rect : public Shape
{
public:
	Rect();
	 ~Rect();
	 #if 0
	virtual double calcArea()
	{
		cout << "Rect virtual calcArea" << endl;
	}
	#endif
	virtual double calcArea();
};

Rect::Rect()
{
	cout << "Rect constructor" <<endl;
}

Rect::~Rect()
{
	cout << "Rect destructors" <<endl;
}

double Rect::calcArea()
{
	cout << "Rect virtual calcArea" << endl;
}



int main()
{
	Shape *p = new Rect;
	p->calcArea();

	delete p;
	return 0;
}