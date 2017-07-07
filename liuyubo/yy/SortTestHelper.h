#ifndef __SORTTESTHELPER_H
#define __SORTTESTHELPER_H

#include <iostream>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <string>

using namespace std;

//定义一个命名空间
namespace SortTestHelper
{
	//判断该数组是否排序成功
	template<typename T>
	bool isSorted(T arr[], int n)
	{
		for (int i = 0; i < n - 1; i++)
			if (arr[i] > arr[i + 1])
				return false;

		return true;
	}

	// 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR]
	int *generateRandomArray(int n, int rangeL, int rangeR) {

		assert(rangeL <= rangeR);

		int *arr = new int[n];

		srand(unsigned int(time(NULL)));
		for (int i = 0; i < n; i++)
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		return arr;
	}
	

	int *generateNearlyOrderedArray(int n, int swapTimes) {

		int *arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = i;

		srand((unsigned int)time(NULL));
		for (int i = 0; i < swapTimes; i++) {
			int posx = rand() % n;
			int posy = rand() % n;
			swap(arr[posx], arr[posy]);
		}

		return arr;
	}

	//模板函数
	template<typename T>
	void printArray(T arr[], int n) {

		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;

		return;
	}





	//sortName为要测试的排序算法的名称
	//排序算法本身
	//endTime-startTime 表示的排序算法运行的时钟周期数
	//CLOCKS_PER_SEC 每秒钟运行的时钟周期的个数
	template<typename T>
	void testSort(string sortName, void(*sort)(T[], int), T arr[], int n)
	{
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
		assert(isSorted(arr, n));
		return;
		
	}

	int *copyIntArray(int a[], int n)
	{
		int *arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = a[i];
		//copy(a, a+n, arr);
		return arr;
	}



};


#endif


















