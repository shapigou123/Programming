#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

//模板函数
//原地对数组进行排序
//时间复杂度 10万个数据 3.6S
template <typename T>
void selectSort(T arr[], int n)
{
	for (int i = 0; i < n; i++) {

		int minIndex = i;
		//不管我们的数组是什么样子，为了保证找到每轮中最小的位置，
		//必须从头到尾把剩下的整个元素遍历一边，没有提前终止的机会
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;

		swap(arr[i], arr[minIndex]);
	}
}