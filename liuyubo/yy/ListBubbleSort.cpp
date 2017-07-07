#include <iostream>
#include "SortTestHelper.h"
#include <string>

#define N  10

using namespace std;
typedef struct Node {
	int value;
	Node *next;
}Node;




void BubbleSort(Node *head)
{
	if (head == NULL)
		return;
	Node *p1 = head, *p2 = head;
	int a[N] = {0};
	int i = 0;
	while (p1->next != NULL)
	{
		cout << p1->next->value << " ";;
		a[i++] = p1->next->value;
		p1 = p1->next;
	}
	cout << endl;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}	
	int j = 0;
	while (p2->next != NULL)
	{
		p2->next->value = a[j++];
		cout << p2->next->value << " ";
		p2 = p2->next;
	}
	cout << endl;
}

void Sort(Node *head)
{
	Node* tail = NULL;

	while (tail != head->next)
	{
		Node* pre = head;
		Node* cur = pre->next;
		while (cur != tail && cur->next != tail)
		{
			if (cur->value > cur->next->value)
			{
				//交换当前节点和后一个节点  
				pre->next = cur->next;
				cur->next = cur->next->next;
				pre->next->next = cur;
			}
			pre = pre->next;
			cur = pre->next;
		}

		tail = cur;
	}
}


void BubbleSort1(Node *head)
{
	if (head == NULL)
		return;
	Node *cur = head->next;
	Node *tail = NULL;
	while (cur!= tail)
	{
		while (cur->next != tail)
		{
			if (cur->value > cur->next->value)
				swap(cur->value, cur->next->value);
			cur = cur->next;
		}
		tail = cur;
		cur = head->next;
	}
	return;
}


int main()
{
	
	int *arr = SortTestHelper::generateRandomArray(N, 0, 100);
	//创建带表头的链表
	Node *head = new Node();
	Node *cur = head; 
	
	for (int i = 0; i < N; i++)
	{
		Node *node = new struct Node();
		node->value = arr[i];
		cur->next = node;
		cur = node;
	}

	//Sort(head);
	BubbleSort1(head);
	Node *p = head;
	while (p->next != NULL)
	{
		//p2->next->value = a[j++];
		cout << p->next->value << " ";
		p = p->next;
	}
	cout << endl;
	system("pause");
	return 0;

}