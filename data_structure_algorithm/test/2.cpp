#if 0
#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

//进制转换
/*  int main(void)
{
	int a;
    while(cin>>hex>>a)
    {
    	cout<<a<<endl;
    }
    return 0;
} */

 

 
/* int main(void)
{
	long int input;
	while(cin>>input)
	{
		while(input != 1)
		{
			for(int i=2; i<=input; i++)
				if(input%i == 0)
				{
					input/=i;
					cout<<i<<" ";
					break;
				}
		}
	}
	return 0;
}	
  */
  
  
#include<iostream>
#include <stdio.h>
using namespace std;

struct ListNode
{
      int       m_nKey;
      ListNode* m_pNext;
};

struct ListNode * creat_node(int data)
{
	//struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *p = new (struct ListNode);
	if(NULL == p)
	{
		return NULL;
	}
	
	bzero(p,sizeof(struct ListNode));
	p->m_nKey = data;
	p->m_pNext = NULL;
	return p;
}

void insert_tail(struct ListNode *pHeader, struct ListNode *newnode)
{
	struct ListNode *p = pHeader;
	
	while(NULL != p->m_pNext)
	{
		p = p->m_pNext;
	}
	p->m_pNext = newnode;
}

void insert_head(struct ListNode *pHeader, struct ListNode *newnode)
{

	newnode->m_pNext=pHeader->m_pNext;
    pHeader->m_pNext = newnode;
}


void list_for_each(struct ListNode *pHeader)
{
	struct ListNode *p = pHeader;
	while(p->m_pNext != NULL)
	{
		p = p->m_pNext;
		cout<<p->m_nKey<<" ";
	}
	
}

int list_for_key1(struct ListNode *pHeader, int num, int k)
{
	struct ListNode *p = pHeader;
	if(k>num)
		return -1;
	if(p->m_pNext != NULL)
	{
		p = p->m_pNext;
		for(int i=0;i<k-1; i++)
			p = p->m_pNext;
		
		return p->m_nKey;
	} 
	else 
		return -1;
}

int list_for_key(struct ListNode *pHeader, int num, int k)
{
	struct ListNode *p = pHeader;
	if(k<num)
		return -1;
	if(p->m_pNext != NULL)
	{
		p = p->m_pNext;
		for(int i=0;i<num-k; i++)
			p = p->m_pNext;
		
		return p->m_nKey;
	} 
	return -1;
}

int main(void)
{
    int NodeNum;
	int inputData;
	int K;
	struct ListNode *ListHeader = creat_node(0);
    cin>>NodeNum;
	for(int i=0; i<NodeNum; i++)
	{
		cin>>inputData;
		insert_head(ListHeader, creat_node(inputData));
	}
	//list_for_each(ListHeader);
	//cout<<endl;	
	cin>>K;
	cout<<list_for_key1(ListHeader,NodeNum,K)<<endl;
    return 0;
}

 
  
#include <iostream>  
#include <stdlib.h>
using namespace std;  
typedef struct  node  
{  
    int nodevalue;  
    struct node *next;  
}node, linklist;  
//为了得到倒数第k个结点，很自然的想法是先走到链表的尾端，再从尾端回溯k步。  
//可是输入的是单向链表，只有从前往后的指针而没有从后往前的指针。  
//在遍历时维持两个指针，第一个指针从链表的头指针开始遍历，在第k-1步之前，第二个指针保持不动；在第k-1步开始，  
//第二个指针也开始从链表的头指针开始遍历。由于两个指针的距离保持在k-1，  
//当第一个（走在前面的）指针到达链表的尾结点时，第二个指针（走在后面的）指针正好是倒数第k个结点。  
linklist *BuildList( int m)  
{  
    node *head = (node*)malloc(sizeof(node));  
    head->next = NULL;  
    head->nodevalue=m;//第一个存放结点个数  
    linklist *t = head;  
    if (head)  
    {  
        for (int i = 0; i < m ; i++)  
        {  
            node *nextnode = (node *)malloc(sizeof(node));  
            nextnode->next = NULL;//新建节点    
            cin >> nextnode->nodevalue;//    
            head->next = nextnode;  
            head = nextnode;  
        }  
    }  
    else  
    {  
        cout << "head new comes error!" << endl;  
    }  
    return t;  
  
}  
linklist* FindKthToTail_Solution2(linklist *pListHead, unsigned int k)  
{  
      
    if (pListHead == NULL)  
        return NULL;  
  
    linklist *pAhead = pListHead;  
    linklist *pBehind = NULL;  
      
    for (unsigned int i = 0; i < k; i++)  
    {  
        if (pAhead->next  != NULL)//尼玛，要从倒数第0个开始算起！！！！  
            pAhead = pAhead->next;  
        else  
        {  
            // if the number of nodes in the list is less than k,   
            // do nothing  
            return NULL;  
        }  
    }  
  
    pBehind = pListHead;  
  
    // the distance between pAhead and pBehind is k  
    // when pAhead arrives at the tail, p  
    // Behind is at the kth node from the tail  
    while (pAhead->next!= NULL)  
    {  
        pAhead = pAhead->next;  
        pBehind = pBehind->next;  
    }  
    return pBehind;  
}  
int main()  
{  
    int nodenum;  
    cin >> nodenum;  
    linklist *p;  
    p = BuildList(nodenum);  
    int k;  
    cin >> k;  
    linklist *resu = FindKthToTail_Solution2(p->next,k);  
    cout << resu->nodevalue << endl;  
  
    return 0;  
}    
  
  
#endif 
  
#include<iostream>
using namespace std;
struct ListNode
{   
    int m_nKey;    
 	ListNode* m_pNext;    
 	ListNode(int a)
    {       
        m_nKey=a;        
      	m_pNext=NULL;    
    }
};

int main(void)
{    
 int num;    
 while(cin>>num)
 {       
     int val;       
     ListNode* head=new ListNode(0);      
     ListNode* p=head;      
     for(int i=0;i<num;i++)
     {            
         cin>>val;            
         ListNode* q=new ListNode(val);           
         p->m_pNext=q;           
         p=p->m_pNext;                  
     }       
     int pos;     
     cin>>pos;
     if(pos == 0)
        // cout<<0;
         return 0;
     if(pos == num)
         return p->m_nKey;
     ListNode* temp=head;                
     for(int i=0;i<=num-pos;i++)
     {          
         temp=temp->m_pNext;       
     }       
     cout<<temp->m_nKey<<endl;   
       
	}
  return 0;  
}
  
  
  
  
  
  
  
 