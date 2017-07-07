#include <iostream>
#include <string>
#include "Sort.h"
//#include "SortTestHelper.h"
#include "Heap.h"

using namespace std;


//int main_sort(void)
//{
//	//int N = 10;
//	int N = 1000000;
//	int *arr = SortTestHelper::generateRandomArray(N, 0, 10);
//	//SortTestHelper::printArray(arr, N);
//	int *arr1 = SortTestHelper::copyIntArray(arr, N);
//	//SortTestHelper::printArray(arr1, N);
//	int *arr2 = SortTestHelper::copyIntArray(arr, N);
//	//SortTestHelper::printArray(arr2, N);
//	int *arr3 = SortTestHelper::copyIntArray(arr, N);
//	int *arr4 = SortTestHelper::copyIntArray(arr, N);
//	int *arr5= SortTestHelper::copyIntArray(arr, N);
//	int *arr6 = SortTestHelper::copyIntArray(arr, N);
//	//SortTestHelper::printArray(arr3, N);
//
//	int swapTimes = 100;
//	
//	int *arrOrder = SortTestHelper::generateNearlyOrderedArray(N, swapTimes);
//	int *arrOrder1 = SortTestHelper::copyIntArray(arrOrder, N);
//	int *arrOrder2 = SortTestHelper::copyIntArray(arrOrder, N);
//	//SortTestHelper::testSort("Selection Sort", selectSort, arr, N);
//	
//	//SortTestHelper::testSort("Insert Sort", insertSortAdvance, arr1, N);
//	
//	//SortTestHelper::testSort("bubble Sort", bubbleSort, arr2, N);
//	
//	//SortTestHelper::testSort("shell Sort", shellSort, arr3, N);
//
//	//SortTestHelper::testSort("merge Sort", mergeSort, arr2, N);
//	//SortTestHelper::printArray(arr4, N);
//	SortTestHelper::testSort("merge Sort Advance", mergeSort1, arr, N);
//	//SortTestHelper::printArray(arrOrder1, N);
//	
//	//SortTestHelper::testSort("quick Sort", quickSort, arr2, N);
//	SortTestHelper::testSort("quick Sort Advance2Ways", quickSort2Ways, arr3, N);
//	SortTestHelper::testSort("quick Sort Advance3Ways", quickSort3Ways, arr4, N);
//	//SortTestHelper::testSort("quick Sort AdvanceRandom", quickSort1, arr1, N);
//	SortTestHelper::testSort("heap Sort1", heapSort1, arrOrder, N);
//	SortTestHelper::testSort("heap Sort2", heapSort2, arrOrder1, N);
//	SortTestHelper::testSort("heap Sort3", heapSort, arrOrder2, N);
//	//SortTestHelper::printArray(arr5, N);
//	//SortTestHelper::printArray(arr6, N);
//
//	delete[] arr;
//	delete[] arr1;
//	delete[] arr2;
//	delete[] arr3;
//
//	cout << endl;
//	system("pause");
//	return 0;
//}