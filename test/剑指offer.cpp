#include <iostream>


#define _CRT_SECURE_NO_WARINGS

using namespace std;

long long Fibonacci(unsigned int n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];
	
	
		long long fibN = 0;
		long long fibOne = 1;
		long long fibTwo = 0;
		for (int i = 2; i <= n; i++)
		{
			fibN = fibOne + fibTwo;
			fibTwo = fibOne;
			fibOne = fibN;
		}
		return fibN;

}

long long FibonacciRecur(unsigned int n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
		return result[n];
	return FibonacciRecur(n-1) + FibonacciRecur(n - 2);
}

int BinaryNumberOf(int data)
{
	int count = 0;
	unsigned int n = 1;
	while (n)
	{
		if (data & n)
			count++;
		n = n << 1;
	}
	return count;
}

//int mainj(void)
//{
//	int n = -11;
//	cout << BinaryNumberOf(n) <<endl;
//	system("pause");
//	return 0;
//}

