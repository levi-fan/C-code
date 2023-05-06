#include"List.h"

SL* ListInit()
{
	SL* head = (SL*)malloc(sizeof(SL));//创建头节点
	head->next = head->prev = head;//带头双向循环链表
	return head;
}
void ListPrint(SL* head)
{
	assert(head);
	SL* cur = head->next;
	while (cur!=head)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");

}
SL* buyListNode(STDataType x)
{
	SL* newNode = (SL*)malloc(sizeof(SL));
	newNode->data = x;
	newNode->next = newNode->prev = NULL;
	return newNode;
}


void ListPushBack(SL* head, STDataType x)
{
	//assert(head);
	//SL*newtail= buyListNode(x);
	//SL* tail = head->prev;
	//head->prev = newtail;
	//newtail->next = head;
	//newtail->prev = tail;
	//tail->next = newtail;
	ListInsert(head->prev, x);

}
void ListPopBack(SL* head)
{
	/*assert(head);
	assert(head->prev != head);
	SL* tail = head->prev->prev;
	free(head->prev);
	tail->next = head;
	head->prev = tail;*/
	ListErase(head->prev);
	
}
void ListPushFront(SL* head, STDataType x)
{
	/*assert(head);
	SL* tmp = head->next;
	SL* newNode = buyListNode(x);
	head->next = newNode;
	newNode->prev = head;
	newNode->next = tmp;
	tmp->prev = newNode;*/
	ListInsert(head, x);
}
void ListPopFront(SL* head)
{
	//assert(head);
	//assert(head->next != head);
	//SL* tmp = head->next->next;//
	//free(head->next);
	//head->next = tmp;
	//tmp->prev = head;
	ListErase(head->next);
}


SL* ListFind(SL* head, STDataType x)
{
	assert(head);
	SL* cur = head->next;
	while (cur != head)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
		
	}
	return NULL;
}
void ListErase(SL* pos)
{
	assert(pos);
	assert(pos->next != pos);//不为头节点
	SL* pospre = pos->prev;
	SL* posnext = pos->next;
	free(pos);
	pospre->next = posnext;
	posnext->prev = pospre;
}  
void ListInsert(SL* pos, STDataType x)
{
	assert(pos);
	SL* newNode = buyListNode(x);
	SL* tmp = pos->next;
	pos->next = newNode;
	newNode->prev = pos;
	newNode->next = tmp;
	tmp->prev = newNode;
}
void ListDestroy(SL* head)
{
	assert(head);
	SL* cur = head;
	while (cur != head)
	{
		free(cur);
		cur = cur->next;
	}
	free(head);
	head = NULL;
}