#include <iostream>


#define _CRT_SECURE_NO_WARINGS

using namespace std;

void changeArrElem(int *arr, int num)
{
	if (arr == NULL)
		return;
	int i = 0;
	int j = (num % 2 == 0) ? num / 2 : num / 2 + 1;

	while (i < num/2)
	{
		swap(arr[i], arr[j]);
		i++;
		j++;
	}
}

void ArrElemReverse(int *arr, int num)
{
	if (arr == NULL)
		return;
	int i = 0;
	int j = num - 1;

	while (i < num / 2)
	{
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
}

int greatestCommonDivisor(int a, int b)
{
	if (a <= 0 || b <= 0)
		return -1;
	//把大的值赋给a
	if (a < b)
	{
		swap(a, b);
	}

	int r = a%b;
	while (r != 0)
	{
		a = b;
		b = r;
		r = a%b;
	}
	return b;
}

int leastCommonMultiple(int a, int b)
{
	return a*b/greatestCommonDivisor(a, b);
	
}

int lastWordLength(char *str, int len)
{
	if (str == NULL)
		return -1;
	int count = 0;
	for (int i = len-1; i >= 0; i--)
	{
		if (str[i] != ' ')
			count++;
		else
			break;
	}
	return count;
}

unsigned long extractEvenIndexNum(unsigned long data)
{
	unsigned long sum = 0;
	unsigned long x = 0;
	while (data)
	{
		x = data % 10;
		sum = sum*10 + x;
		data /= 100;
	}
	
	return sum;
}


unsigned long extractEvenDataNum(unsigned long data)
{
	unsigned long sum = 0;
	unsigned long x = 0;
	while (data)
	{
		x = data % 10;
		if (x % 2 == 0)
		{
			sum = sum*10 + x;	
		}
		data /= 10;
	}
	return sum;
}

void extractOddDataNum(long data, long *t)
{
	int d = 1;
	long x = 0;
	while (data)
	{
		x = data % 10;
		if (x % 2 == 1)
		{
			*t = *t + x*d;
			d = d * 10;
		}
		data /= 10;
	}
}

void mystrcat(char *str, const char *newstr, int len)
{
	if (str == NULL || newstr == NULL)
		return;
	int i = 0;
	int j = 0;
	while (str[i] != '\0')
		i++;
	while (newstr[j] != '\0')
		j++;
	if (i + j >= len)
		return;
	int k = 0;
	while (newstr[k] != '\0')
	{
		str[i++] = newstr[k++];
	}
	str[i] = '\0';
}

void intArrSort(int *arr, int n)
{
	int indexMax, max, indexMin, min; 
	for (int i = 0; i < n - 1; i+=2)
	{
		min = max = arr[i];
		indexMax = indexMin = i;
		for (int j = i+1; j < n; j++)
		{
			if (max < arr[j])
			{
				max = arr[j];
				indexMax = j;
			}
			if (min > arr[j])
			{
				min = arr[j];
				indexMin = j;
			}
		}
		if (indexMin != i)
		{
			swap(arr[i], arr[indexMin]);
			if (indexMax == i)//此时大的数在小的数的前面，故要交换位置
				indexMax = indexMin;
		}
		if (indexMax != i+1)
			swap(arr[i+1], arr[indexMax]);
	}
}

int mainc(void)
{
	int a[] = {9,1,4,2,3,6,5,8,7,100,0,99};
	intArrSort(a, 12);
	for (int i = 0; i < 12; i++)
		cout << a[i] << " ";
	cout << endl;
	system("pause");
	return 0;

}