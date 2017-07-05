#include <iostream>

using namespace std;

int maximum(int * array, int size){
 
  int curr = 0;
  int max = 0;
 
  for(curr = 0; curr < size; curr++){
    if(array[curr] > max){ max = array[curr]; }
  }
 
  return max;
}
 

void count_sorting(int *A, int *B, int array_size, int k)
{
        int C[k+1], i, value, pos;
        for(i=0; i<=k; i++)		//初始化数组
        {
            C[i] = 0;
        }
        for(i=0; i< array_size; i++)	//统计原数组A中值为i的元素的个数
        {
            C[A[i]] ++;
        }
        for(i=1; i<=k; i++)			//统计原数组中小于等于i的元素的个数
        {
            C[i] = C[i] + C[i-1];	//此时C中包含每个元素在有序集合中的偏移量
        }
        for(i=array_size-1; i>=0; i--)	
        {
            value = A[i];
            pos = C[value];			
            B[pos-1] = value;		//小与等于i的个数中，包含了自己本身，故要减一
            C[value]--;			
        }
}

void count_sorting2(int pData[], int nLen)
{
	
    int* pCout = NULL;            //保存记数数据的指针
	int max = maximum(pData, nLen);	
	pCout = new int[max+1];
    //初始化记数为0
    for (int i = 0; i <= max; ++i)
    {
        pCout[i] = 0;
    }

    //记录排序记数。在排序的值相应记数加1。
    for (int i = 0; i <nLen; ++i)
    {
        ++pCout[pData[i]];        //增
    }

    //确定不比该位置大的数据个数。
    for (int i = 1; i <= max; ++i)
    {
        pCout[i] += pCout[i - 1];    //不比他大的数据个数为他的个数加上前一个的记数。
    }

    int* pSort = NULL;            //保存排序结果的指针
	pSort = new int[nLen];

    for (int i = 0; i < nLen; ++i)
    {
        //把数据放在指定位置。因为pCout[pData[i]]的值就是不比他大的数据的个数。
        //为什么要先减一，因为pCout[pData[i]]保存的是不比他大的数据的个数中包括了
        //他自己，我的下标是从零开始的!所以要先减一。
       
		int pos =  pCout[pData[i]];    //因为有相同数据的可能，所以要把该位置数据个数减一。
		
        pSort[pos -1] = pData[i]; 
		pCout[pData[i]]--;				//计数要减1
      
    }

    //排序结束，复制到原来数组中。
    for (int i = 0; i < nLen; ++i)
    {
        pData[i] = pSort[i];
    }

    //最后要注意释放申请的空间。
    delete(pCout);
    delete(pSort);

}

int main()
{
	int len,i;
    int A[] = {2, 5, 3, 0, 9, 3, 1, 3, 90,88};
	len = sizeof(A)/sizeof(int);
	//int B[len];
    //count_sorting(A, B, 8, 5);
	count_sorting2(A, len);
     for(i = 0; i<len; i++)
	{
		cout<< A[i]<<' ';
	}
	cout<<endl;	
        return 0;
}
