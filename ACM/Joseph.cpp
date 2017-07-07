#include <iostream>
#include <stdlib.h>
using namespace std;

#define N			9
#define OK			1
#define OVERFLOW	0
int KeyWord[N] = {4, 7, 5, 9, 3, 2, 6, 1, 8};

typedef struct LNode{
	int  keyword;
	struct LNode *next;
}LNode, *LinkList;

void joseph(LinkList pHead, int startPos, int num)
{
	
	if (num == 0 || pHead == NULL)
		return;
	LinkList p = pHead;
	startPos %= num;
	if (startPos == 0)
		startPos = num;
	for (int i = 1; i <= startPos; i++)
	{
		pHead = p;
		p = pHead->next;
	}

	pHead->next = p->next;
	int data = p->keyword;
	cout << data << " ";
	free(p);
	joseph(pHead, data, num - 1);
}


int main_joseph()
{
	int startPost;
	LinkList pLHead, p, q;
	pLHead = new LNode;
	if(!pLHead)
		return OVERFLOW;
	pLHead->keyword = KeyWord[0];
	pLHead->next = NULL;
	p = pLHead;
	for (int i = 1; i < N; i++)
	{
		if(!(q = new LNode))
			return OVERFLOW;
		q->keyword = KeyWord[i];
		p->next = q;
		p = q;
	}
	p->next = pLHead;
	cout << " please input the first record startPos: "<<endl;
	cin >> startPost;

	joseph(p, startPost, N);

	system("pause");
	return 0;
}
