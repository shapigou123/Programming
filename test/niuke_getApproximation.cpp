#include <iostream>

using namespace std;

int main2(void)
{
	double a;
	while (cin >> a)
		//	if (a - 0.5 >= 0)
		//		a = a + 1;
		//	else
		//		a = a - 1;

			/*int b = static_cast<double>(a);
			if (a - b > 0.5)
				cout << b + 1;
			else
				cout <<b;*/
	{
		int b = int(a+0.5);
		cout << b << endl;
	}
	
	system("pause");
	return 0;
}

