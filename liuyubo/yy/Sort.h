
#include <iostream>
#include <algorithm>
#include "Heap.h"
using namespace std;


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

/*****************************************************************************/

template<typename T>
//时间复杂度低  10万个数据0.001s
void insertSort(T a[], int n)
{
	for (int i = 1; i<n; i++)
	{
		//寻找元素a[i]合适的插入位置（在前面）
		//每一次把当前元素和它前一个元素做比较，判断它放在前一个元素的位置。
		for (int j = i; j > 0; j--)
		{
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
			else
				break;
		}
		//只有同时满足两个的情况下才进行交换，也就是说插入排序第二次循环可以提前结束
		//for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
		//	swap(arr[j], arr[j - 1]);
	}
	//return;
}



#if 1
//时间复杂度要大 10万个数据 1.8S
template<typename T>
void insertSortAdvance(T a[], int n)
{
	for (int i = 1; i<n; i++)
	{
		int j = i - 1; //j表示有序区	
		T temp = a[i];
		//把一次的交换操作，变成了比较后的一次赋值！并能提前终止
		//以是一次交换，三次赋值！
		for (; j >= 0 && temp < a[j]; j--)
			a[j + 1] = a[j];
		a[j+1] = temp;

	/*	int j;
		T e = arr[i];
		for (j = i; j > 0 && temp < a[j-1]; j--)
			a[j] = a[j - 1];
		a[j] = e;
	*/
		//while (j >= 0 && temp<a[j])
		//{
		//	a[j+1] = a[j];	//不能写成j++
		//	j--;
		//}		
	}
	return;
}

#endif
//对a[l...r]范围的数组进行插入排序
template<typename T>
void insertionSort(T a[], int l, int r)
{
	for (int i = l + 1; i <= r; i++)
	{
		T e = a[i];
		int j;
		for (j = i; j > l && a[j - 1] > e; j--)
			a[j] = a[j - 1];
		a[j] = e;	
	}
	return;
}

/*****************************************************************************/


template <typename T>
void bubbleSort(T arr[], int n)
{
	bool flag;
	for (int i = 0; i < n-1; i++)
	{
		flag = false;
		for (int j=i+1; j<n; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
				flag = true;
			}
			
		}
		if (flag == false)
				return;
	}
}


/*****************************************************************************/
template<typename T>
void shellSort(T a[], int n)
{
	int gap = n / 2;
	int temp;
	while (gap>0)
	{
		for (int i = gap; i < n; i++)
		{
			temp = a[i];	//temp表示无序区数据
			int j = i - gap;	//j代表有序区
			while (j >= 0 && temp < a[j])
			{
				a[j + gap] = a[j];
				j -= gap;
			}
			a[j + gap] = temp;
			//j = j - gap;
		}
		gap /= 2;
	}
}

/*****************************************************************************/



// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename  T>
void _merge(T arr[], int l, int mid, int r)
{
	// 经测试,传递aux数组的性能效果并不好
	T *aux = new T[r - l + 1];
	int i = l;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= r)
	{
		if (arr[i] > arr[j])
		{
			aux[k] = arr[j];
			k++;
			j++;
		}			
		else
			aux[k++] = arr[i++];	
	}
	while (i <= mid)
		aux[k++] = arr[i++];
	while (j <= r)
		aux[k++] = arr[j++];
	for (k = 0, i = l; i <= r; i++, k++)
		arr[i] = aux[k];
}


// 递归使用归并排序,对arr[l...r]的范围进行排序
template<typename T>
void _mergeSort(T a[], int l, int r)
{
	if (r <= l)
		return;
	int mid = (r + l) / 2;
	//该归并过程保证了l到mid是有序的，mid到r是有序的
	_mergeSort(a, l, mid);
	_mergeSort(a, mid + 1, r);
	// 对于arr[mid] <= arr[mid+1]的情况,不进行merge。arr就是有序的
	// 对于近乎有序的数组非常有效,但是对于一般情况,有一定的性能损失
	if (a[mid] > a[mid + 1])
		_merge(a, l, mid, r);
}

template<typename T>
void mergeSort(T a[], int n)
{
	_mergeSort(a, 0, n - 1);
}

// 递归使用归并排序,对arr[l...r]的范围进行排序
template<typename T>
void _mergeSort1(T a[], int l, int r)
{
	if (r - l <= 15)
	{
		insertionSort(a, l, r);
		return;
	}	
	int mid = (r + l) / 2;
	//该归并过程保证了l到mid是有序的，mid到r是有序的
	_mergeSort1(a, l, mid);
	_mergeSort1(a, mid + 1, r);
	// 对于arr[mid] <= arr[mid+1]的情况,不进行merge。arr就是有序的
	// 对于近乎有序的数组非常有效,但是对于一般情况,有一定的性能损失
	if (a[mid] > a[mid + 1])
		_merge(a, l, mid, r);
}

template<typename T>
void mergeSort1(T a[], int n)
{
	_mergeSort1(a, 0, n - 1);
}



/*****************************************************/
//快速排序
template<typename T>
int _partition(T a[], int l, int r)
{
	T v = a[l];	
	//arr[l+1...j] <v a[j+1...i]>v
	int j = l;
	//j指向前半部分（小与元素V的最后位置，i为要比较的元素）
	for (int i = l + 1; i <= r; i++)
	{
		if (a[i] < v)
		{
			swap(a[j + 1], a[i]);
			j++;
		}	
	}
	swap(a[l], a[j]);
	return j;
}


template<typename T>
void _quickSort(T a[], int l, int r)
{
	if (r <= l)
		return;
	int p = _partition(a, l, r);
	_quickSort(a, l, p - 1);
	_quickSort(a, p + 1, r);
}

template<typename T>
void quickSort(T a[], int n)
{
	_quickSort(a, 0, n - 1);
}


template<typename T>
int _partition1(T a[], int l, int r)
{
	swap(a[l], a[rand() % (r - l + 1)+l]);
	T v = a[l];
	//arr[l+1...j] <v a[j+1...i]>v
	int j = l;
	//j指向前半部分（小与元素V的最后位置，i为要比较的元素）
	for (int i = l + 1; i <= r; i++)
	{
		if (a[i] < v)
		{
			swap(a[j + 1], a[i]);
			j++;
		}
	}
	swap(a[l], a[j]);
	return j;
}


template<typename T>
void _quickSort1(T a[], int l, int r)
{
	/*if (r <= l)
		return;*/
	if (r - l <= 15)
	{
		insertionSort(a, l, r);
		return;
	}
	int p = _partition1(a, l, r);
	_quickSort1(a, l, p - 1);
	_quickSort1(a, p + 1, r);
}


template<typename T>
void quickSort1(T a[], int n)
{
	srand((unsigned int )time(NULL));
	_quickSort1(a, 0, n - 1);
}


template<typename T>
int _partition2Ways(T a[], int l, int r)
{
	swap(a[l], a[rand() % (r - l + 1) + l]);
	T v = a[l];
	//arr[l+1...j] <v a[j+1...i]>v
#if 1
	//不能写a[i]<=V a[j]>=v 否则速度慢很多
	int i = l+1, j = r;
	while (true)
	{
		//结束时，i停在了从前往后看第一个大于等于V的位置
		while (i <= r && a[i]<v)i++;
		//结束时，j停在了整个数组中最后一个小与等于V的位置
		//我们的标定点V是在小与等于V的一端
		while (j >= l+1 && a[j]>v)j--;
		if (i > j)	break;
		swap(a[i], a[j]);
		i++;
		j--;
	}
	swap(a[l], a[j]);
	return j;
#endif
//数据达到100W栈溢出
////不能写a[i]<V a[j]>v 否则速度慢很多
#if 0
	int i = l, j = r;
	if (l < r)
	{
		while (i != j)
		{
			while (j > i && a[j] >= v)j--;	
			a[i] = a[j];
			while (i < j && a[i] <= v)i++;		
			a[j] = a[i];
		}
		a[i] = v;
		return i;
	}
#endif
}

template<typename T>
void _quickSort2Ways(T a[], int l, int r)
{
	/*if (r <= l)
	return;*/
	if (r - l <= 15)
	{
		insertionSort(a, l, r);
		return;
	}
	int p = _partition2Ways(a, l, r);
	_quickSort2Ways(a, l, p - 1);
	_quickSort2Ways(a, p + 1, r);
}

template<typename T>
void quickSort2Ways(T a[], int n)
{
	srand((unsigned int)time(NULL));
	_quickSort2Ways(a, 0, n - 1);
}


//三路快速排序处理arr[l...r]
//将arr[l...r]分为<v; ==v; >v三部分
//之后递归对 <v; >v 两部分继续进行三路快速排序
template<typename T>
void _quickSort3Ways(T a[], int l, int r){
	if (r - l <= 15){
		insertionSort(a, l, r);
		return;
	}
	swap(a[l], a[rand() % (r - l + 1) + l]);
	T v = a[l];
	int lt = l;		//a[l+1...lt] < v初始为空
	int gt = r + 1; //a[gt...r] > v初始为空
	int i = l + 1;  //a[lt+1...i) ==v
	while (i < gt){
		if (a[i] < v){
			swap(a[i], a[lt + 1]);
			lt++;
			i++;
		}
		else if (a[i] > v){
			swap(a[i], a[gt - 1]);
			gt--;
		}
		else
			i++;
	}
	swap(a[l], a[lt]);
	_quickSort3Ways(a, l, lt-1);
	_quickSort3Ways(a, gt, r);
}

template<typename T>
void quickSort3Ways(T a[], int n)
{
	srand((unsigned int)time(NULL));
	_quickSort3Ways(a, 0, n - 1);
}

/*****************************************************/

template<typename T>
void heapSort1(T arr[], int n)
{
	MaxHeap<T> maxheap = MaxHeap<T>(n);
	for (int i = 0; i < n; i++)
		maxheap.insert(arr[i]);
	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxheap.extractMax();
}


template<typename T>
void heapSort2(T arr[], int n)
{
	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxheap.extractMax();
}



template<typename T>
void __shiftDown(T arr[], int n, int k) {
	//数组中有N个元素，是不到N的。左孩子不越界
	while (2 * k + 1 < n) {
		int j = 2 * k + 1;
		//右孩子不越界
		if (j + 1 < n && arr[j + 1] > arr[j])
			j += 1;
		if (arr[k] >= arr[j])break;
		swap(arr[k], arr[j]);
		k = j;
	}
}

template<typename T>
void __shiftDown2(T arr[], int n, int k) {
	T e = arr[k];
	while (2 * k + 1 < n) {
		int j = 2 * k + 1;
		if (j + 1 < n && arr[j + 1] > arr[j])
			j += 1;
		if (e >= arr[j]) break;
		arr[k] = arr[j];
		k = j;
	}
	arr[k] = e;
}

template<typename T>
void heapSort(T arr[], int n) {
	//Heapiy过程，直接将arr数组构成一个堆
	for (int i = (n - 1) / 2; i >= 0; i--)
		__shiftDown2(arr, n, i);
	//当堆中只剩一个元素时，就不需要进行交换操作了
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		//每次循环时，堆中的元素个数减一
		__shiftDown2(arr, i, 0);
	}
}