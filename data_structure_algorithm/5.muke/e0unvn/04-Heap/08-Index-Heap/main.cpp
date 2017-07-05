#include <iostream>
#include <cassert>
#include "SortTestHelper.h"

#define Priority int

using namespace std;

template<typename Item>
class IndexMaxHeap{

private:
    Item *data;
    int *indexes;

    int count;
    int capacity;
	//k在索引堆中描述的是索引数组的位置
	//先从k找到索引，再从索引找到data
    void shiftUp( int k ){

        while( k > 1 && data[indexes[k/2]] < data[indexes[k]] ){
			//交换的是indexes数组
            swap( indexes[k/2] , indexes[k] );
            k /= 2;
        }
    }

    void shiftDown( int k ){

        while( 2*k <= count ){
            int j = 2*k;
            if( j + 1 <= count && data[indexes[j+1]] > data[indexes[j]] )
                j += 1;

            if( data[indexes[k]] >= data[indexes[j]] )
                break;

            swap( indexes[k] , indexes[j] );
            k = j;
        }
    }

public:
    IndexMaxHeap(int capacity){

        data = new Item[capacity+1];
        indexes = new int[capacity+1];

        count = 0;
        this->capacity = capacity;
    }

    ~IndexMaxHeap(){
        delete[] data;
        delete[] indexes;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    // 传入的i对外部用户而言,是从0索引的
	//而我们实现堆的内部，是从1开始所索引的
	//时间复杂度为O(lgN)级别
    void insert(int i, Item item){
        assert( count + 1 <= capacity );
        assert( i + 1 >= 1 && i + 1 <= capacity );
		//让从0索引的i变成从1索引的i
        i += 1;
        data[i] = item;
        indexes[count+1] = i;
        count++;

        shiftUp(count);
    }
	
	//我们可以通过索引来找到data中的元素
    Item extractMax(){
        assert( count > 0 );

        Item ret = data[indexes[1]];
        swap( indexes[1] , indexes[count] );
        count--;
        shiftDown(1);
        return ret;
    }
	
	//时间复杂度为O(lgN)级别
    int extractMaxIndex(){
        assert( count > 0 );
		//使之对外部用户来说，索引是从0开始的
        int ret = indexes[1] - 1;
        swap( indexes[1] , indexes[count] );
        count--;
        shiftDown(1);
        return ret;
    }

    Item getMax(){
        assert( count > 0 );
        return data[indexes[1]];
    }

    int getMaxIndex(){
        assert( count > 0 );
        return indexes[1]-1;
    }
	//外部用户的i从0开始
    Item getItem( int i ){
        return data[i+1];
    }

	//把索引位置为i的元素修改成了新的newItem
	//时间复杂度为O(N)级别
    void change( int i , Item newItem ){

        i += 1;
        data[i] = newItem;

        // 找到indexes[j] = i, j表示data[i]在堆中的位置
        // 之后shiftUp(j), 再shiftDown(j)
        for( int j = 1 ; j <= count ; j ++ )
            if( indexes[j] == i ){
                shiftUp(j);
                shiftDown(j);
                return;
            }
    }

    // test reverse index
    bool testReverseIndex(){

        int *copyIndexes = new int[count+1];

        for( int i = 0 ; i <= count ; i ++ ){
            copyIndexes[i] = indexes[i];
        }

        copyIndexes[0] = 0;
        std::sort(copyIndexes, copyIndexes + count + 1);

        bool res = true;
        for( int i = 1 ; i <= count ; i ++ )
            if( copyIndexes[i-1] + 1 != copyIndexes[i] )
                res = res || false;

        delete[] copyIndexes;

        if( !res ){
            cout<<"Error 1"<<endl;
            return res;
        }

        return true;
    }
};

template<typename T>
void heapSortUsingIndexMaxHeap(T arr[], int n){

    IndexMaxHeap<T> indexMaxHeap = IndexMaxHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        indexMaxHeap.insert( i , arr[i] );
    assert( indexMaxHeap.testReverseIndex() );

    for( int i = n-1 ; i >= 0 ; i -- )
        arr[i] = indexMaxHeap.extractMax();
}

int main() {

    int n = 1000000;

    Priority* arr = new Priority[n];
    srand(time(NULL));
    for( int i = 0 ; i < n ; i ++ )
        arr[i] = rand()%n;
    SortTestHelper::testSort("Heap Sort Using Index-Max-Heap", heapSortUsingIndexMaxHeap, arr, n);
    delete[] arr;

    return 0;
}