#pragma once

#include <iostream>
#include <algorithm>

using namespace std;
#if 0
void insertSort(T a[], int n)
{
	for (int i=1; i<n; i++)
	{
		for (int j = i; j > 0; i--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
			else
				break;
	}
}



template<typename T>
void insertSort(T a[], int n)
{
	for (int i = 1; i<n; i++)
	{
		int j = i - 1; //j表示有序区
		int temp = a[i];
		while (j >= 0 && temp>a[j])
		{
			a[j++] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}
#endif