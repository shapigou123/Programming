
#include <iostream>
#include <algorithm>
#include "Heap.h"
using namespace std;


//ԭ�ض������������
//ʱ�临�Ӷ� 10������� 3.6S
template <typename T>
void selectSort(T arr[], int n)
{
	for (int i = 0; i < n; i++) {

		int minIndex = i;
		//�������ǵ�������ʲô���ӣ�Ϊ�˱�֤�ҵ�ÿ������С��λ�ã�
		//�����ͷ��β��ʣ�µ�����Ԫ�ر���һ�ߣ�û����ǰ��ֹ�Ļ���
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;

		swap(arr[i], arr[minIndex]);
	}
}

/*****************************************************************************/

template<typename T>
//ʱ�临�Ӷȵ�  10�������0.001s
void insertSort(T a[], int n)
{
	for (int i = 1; i<n; i++)
	{
		//Ѱ��Ԫ��a[i]���ʵĲ���λ�ã���ǰ�棩
		//ÿһ�ΰѵ�ǰԪ�غ���ǰһ��Ԫ�����Ƚϣ��ж�������ǰһ��Ԫ�ص�λ�á�
		for (int j = i; j > 0; j--)
		{
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
			else
				break;
		}
		//ֻ��ͬʱ��������������²Ž��н�����Ҳ����˵��������ڶ���ѭ��������ǰ����
		//for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
		//	swap(arr[j], arr[j - 1]);
	}
	//return;
}



#if 1
//ʱ�临�Ӷ�Ҫ�� 10������� 1.8S
template<typename T>
void insertSortAdvance(T a[], int n)
{
	for (int i = 1; i<n; i++)
	{
		int j = i - 1; //j��ʾ������	
		T temp = a[i];
		//��һ�εĽ�������������˱ȽϺ��һ�θ�ֵ��������ǰ��ֹ
		//����һ�ν��������θ�ֵ��
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
		//	a[j+1] = a[j];	//����д��j++
		//	j--;
		//}		
	}
	return;
}

#endif
//��a[l...r]��Χ��������в�������
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
			temp = a[i];	//temp��ʾ����������
			int j = i - gap;	//j����������
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



// ��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
template<typename  T>
void _merge(T arr[], int l, int mid, int r)
{
	// ������,����aux���������Ч��������
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


// �ݹ�ʹ�ù鲢����,��arr[l...r]�ķ�Χ��������
template<typename T>
void _mergeSort(T a[], int l, int r)
{
	if (r <= l)
		return;
	int mid = (r + l) / 2;
	//�ù鲢���̱�֤��l��mid������ģ�mid��r�������
	_mergeSort(a, l, mid);
	_mergeSort(a, mid + 1, r);
	// ����arr[mid] <= arr[mid+1]�����,������merge��arr���������
	// ���ڽ������������ǳ���Ч,���Ƕ���һ�����,��һ����������ʧ
	if (a[mid] > a[mid + 1])
		_merge(a, l, mid, r);
}

template<typename T>
void mergeSort(T a[], int n)
{
	_mergeSort(a, 0, n - 1);
}

// �ݹ�ʹ�ù鲢����,��arr[l...r]�ķ�Χ��������
template<typename T>
void _mergeSort1(T a[], int l, int r)
{
	if (r - l <= 15)
	{
		insertionSort(a, l, r);
		return;
	}	
	int mid = (r + l) / 2;
	//�ù鲢���̱�֤��l��mid������ģ�mid��r�������
	_mergeSort1(a, l, mid);
	_mergeSort1(a, mid + 1, r);
	// ����arr[mid] <= arr[mid+1]�����,������merge��arr���������
	// ���ڽ������������ǳ���Ч,���Ƕ���һ�����,��һ����������ʧ
	if (a[mid] > a[mid + 1])
		_merge(a, l, mid, r);
}

template<typename T>
void mergeSort1(T a[], int n)
{
	_mergeSort1(a, 0, n - 1);
}



/*****************************************************/
//��������
template<typename T>
int _partition(T a[], int l, int r)
{
	T v = a[l];	
	//arr[l+1...j] <v a[j+1...i]>v
	int j = l;
	//jָ��ǰ�벿�֣�С��Ԫ��V�����λ�ã�iΪҪ�Ƚϵ�Ԫ�أ�
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
	//jָ��ǰ�벿�֣�С��Ԫ��V�����λ�ã�iΪҪ�Ƚϵ�Ԫ�أ�
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
	//����дa[i]<=V a[j]>=v �����ٶ����ܶ�
	int i = l+1, j = r;
	while (true)
	{
		//����ʱ��iͣ���˴�ǰ���󿴵�һ�����ڵ���V��λ��
		while (i <= r && a[i]<v)i++;
		//����ʱ��jͣ�����������������һ��С�����V��λ��
		//���ǵı궨��V����С�����V��һ��
		while (j >= l+1 && a[j]>v)j--;
		if (i > j)	break;
		swap(a[i], a[j]);
		i++;
		j--;
	}
	swap(a[l], a[j]);
	return j;
#endif
//���ݴﵽ100Wջ���
////����дa[i]<V a[j]>v �����ٶ����ܶ�
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


//��·����������arr[l...r]
//��arr[l...r]��Ϊ<v; ==v; >v������
//֮��ݹ�� <v; >v �����ּ���������·��������
template<typename T>
void _quickSort3Ways(T a[], int l, int r){
	if (r - l <= 15){
		insertionSort(a, l, r);
		return;
	}
	swap(a[l], a[rand() % (r - l + 1) + l]);
	T v = a[l];
	int lt = l;		//a[l+1...lt] < v��ʼΪ��
	int gt = r + 1; //a[gt...r] > v��ʼΪ��
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
	//��������N��Ԫ�أ��ǲ���N�ġ����Ӳ�Խ��
	while (2 * k + 1 < n) {
		int j = 2 * k + 1;
		//�Һ��Ӳ�Խ��
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
	//Heapiy���̣�ֱ�ӽ�arr���鹹��һ����
	for (int i = (n - 1) / 2; i >= 0; i--)
		__shiftDown2(arr, n, i);
	//������ֻʣһ��Ԫ��ʱ���Ͳ���Ҫ���н���������
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		//ÿ��ѭ��ʱ�����е�Ԫ�ظ�����һ
		__shiftDown2(arr, i, 0);
	}
}