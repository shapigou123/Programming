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
        for(i=0; i<=k; i++)		//��ʼ������
        {
            C[i] = 0;
        }
        for(i=0; i< array_size; i++)	//ͳ��ԭ����A��ֵΪi��Ԫ�صĸ���
        {
            C[A[i]] ++;
        }
        for(i=1; i<=k; i++)			//ͳ��ԭ������С�ڵ���i��Ԫ�صĸ���
        {
            C[i] = C[i] + C[i-1];	//��ʱC�а���ÿ��Ԫ�������򼯺��е�ƫ����
        }
        for(i=array_size-1; i>=0; i--)	
        {
            value = A[i];
            pos = C[value];			
            B[pos-1] = value;		//С�����i�ĸ����У��������Լ�������Ҫ��һ
            C[value]--;			
        }
}

void count_sorting2(int pData[], int nLen)
{
	
    int* pCout = NULL;            //����������ݵ�ָ��
	int max = maximum(pData, nLen);	
	pCout = new int[max+1];
    //��ʼ������Ϊ0
    for (int i = 0; i <= max; ++i)
    {
        pCout[i] = 0;
    }

    //��¼����������������ֵ��Ӧ������1��
    for (int i = 0; i <nLen; ++i)
    {
        ++pCout[pData[i]];        //��
    }

    //ȷ�����ȸ�λ�ô�����ݸ�����
    for (int i = 1; i <= max; ++i)
    {
        pCout[i] += pCout[i - 1];    //������������ݸ���Ϊ���ĸ�������ǰһ���ļ�����
    }

    int* pSort = NULL;            //������������ָ��
	pSort = new int[nLen];

    for (int i = 0; i < nLen; ++i)
    {
        //�����ݷ���ָ��λ�á���ΪpCout[pData[i]]��ֵ���ǲ�����������ݵĸ�����
        //ΪʲôҪ�ȼ�һ����ΪpCout[pData[i]]������ǲ�����������ݵĸ����а�����
        //���Լ����ҵ��±��Ǵ��㿪ʼ��!����Ҫ�ȼ�һ��
       
		int pos =  pCout[pData[i]];    //��Ϊ����ͬ���ݵĿ��ܣ�����Ҫ�Ѹ�λ�����ݸ�����һ��
		
        pSort[pos -1] = pData[i]; 
		pCout[pData[i]]--;				//����Ҫ��1
      
    }

    //������������Ƶ�ԭ�������С�
    for (int i = 0; i < nLen; ++i)
    {
        pData[i] = pSort[i];
    }

    //���Ҫע���ͷ�����Ŀռ䡣
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
