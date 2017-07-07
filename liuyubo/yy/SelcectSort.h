#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

//ģ�庯��
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