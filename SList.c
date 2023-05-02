#include"SList.h"
void SListPrint(SL* phead)
{
	assert(phead != NULL);
	SL* cur = phead;
	while (cur->next)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}
SL* buySLNode(SLNodeDataType x)
{
	SL* newSL = (SL*)malloc(sizeof(SL));
	assert(newSL);
	if (newSL)
	{
		newSL->data = x;
		newSL->next = NULL;
	}
	return newSL;
}
void SListPushBack(SL** phead, SLNodeDataType x)
{
	SL* newSL = buySLNode(x);
	//SL* cur = *phead;
	if (*phead)
	{
		*phead = newSL;
	}
	else
	{
		SL* tail = *phead;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newSL;
	}
}
