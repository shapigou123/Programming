#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"


using namespace std;

template <typename T>

//没用通过索引直接获取元素，可以非常好的使用NlgN的时间对链表进行排序
void mergeSortBU(T arr[], int n)
{
	
		//Merge的元素个数进行遍历
		//每次归并排序，看的元素个数为1 2 4 8
//    for( int sz = 1; sz <= n ; sz += sz )
			//每一轮元素的起始位置，i每次移动的距离为2*size
		//第一轮 0——sz-1  sz——2*sz-1进行归并
		//第二轮 2*sz——3*sz-1  3*sz——4*sz-1
		
																//for( int i = 0 ; i < n ; i += sz+sz )
	
			//i+size保证了第二部分的存在
			//for( int i = 0 ; i+size < n ; i += sz+sz )
				
//            // 对 arr[i...i+sz-1] 、arr[i+sz...i+2*sz-1]两个有序的部分合成一个有序的
				//防止数组越界
//            __merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1) );

    // Merge Sort Bottom Up 优化
	
    for( int i = 0 ; i < n ; i += 16 )
        insertionSort(arr,i,min(i+15,n-1));

    for( int sz = 16; sz <= n ; sz += sz )
        for( int i = 0 ; i < n - sz ; i += sz+sz )
            if( arr[i+sz-1] > arr[i+sz] )
                __merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1) );
}


int main() {

    int n = 1000000;

    cout<<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Merge Sort Bottom Up", mergeSortBU, arr2, n);

    delete(arr1);
    delete(arr2);

    cout<<endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for Random Nearly Ordered Array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Merge Sort Bottom Up", mergeSortBU, arr2, n);

    delete(arr1);
    delete(arr2);

    return 0;
}