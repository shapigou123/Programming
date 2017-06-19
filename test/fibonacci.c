#include <stdio.h>

int fibonacci(unsigned int n)
{
	int result[] = {0, 1};
	if(n < 2)
		return result[n];
	return fibonacci(n-1)+fibonacci(n-2);
}

long long int fibonacci_advcance(unsigned int n)
{
	int result[] = {0, 1};
	int i =2;
	if(n < 2)
		return result[n];
	long  long int fibN = 0;
	long  long int fibOne = 1;
	long  long int fibTwo = 0;
	for(i; i<=n; i++)
	{
		fibN = fibOne + fibTwo;
		fibTwo = fibOne;
		fibOne = fibN;
	}
	return fibN;
}
int main()
{
	int n;
	int data = -1;
	scanf("%d",&n);
	printf("%d\n",fibonacci_advcance(n));
	return 0;
}
