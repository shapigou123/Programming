#include <stdio.h>

int main(void)
{
	int a;
	int b,c;
	a = b =10;
	printf("%d\n",a);
	a=(b=10)+(c=20);
	printf("%d\n",a);
	return 0;
}