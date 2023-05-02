#include"SList.h"
void SListPrint(SL* phead)
{
	assert(phead != NULL);
	SL* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
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
	if (*phead==NULL)
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
void SListPushFront(SL** phead, SLNodeDataType x)
{
	SListInsert(phead, *phead, x);
	/*
	SL* newSL = buySLNode(x);
	if(*phead==NULL)
		{
		*phead = newSL;
		}
	else
	{
		newSL->next = *phead;
	}
	*phead = newSL;*/
}
void SListPopBack(SL** phead)
{
	assert(*phead != NULL);
	if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		SL* tail = *phead;
		//SL* cur = NULL;
		while (tail->next->next != NULL)
		{
			//cur = tail;
			tail = tail->next;
		}
		//cur->next = NULL;
		free(tail->next);
		tail->next = NULL;

	}
}
void SListPopFront(SL** phead)
{
	SListErase(phead, *phead);
	/*assert(*phead != NULL);
	if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		SL* cur = *phead;
		*phead = (*phead)->next;
		free(cur);
		cur = NULL;
	}*/
}
SL* SlistFind(SL* phead, SLNodeDataType x)
{
	assert(phead != NULL);
	SL* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}
void SListInsert(SL** phead, SL* pos, SLNodeDataType x)
{
	assert(*phead);
	SL* newSL = buySLNode(x);
	SL* cur = *phead;
	if (pos == *phead)
	{
		newSL->next = *phead;
		*phead = newSL;
	}
	else
	{
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		newSL->next = cur->next;
		cur->next = newSL;
	}
}
void SListErase(SL** phead, SL* pos)
{
	assert(*phead);
	SL* prev = *phead;
	if (pos == *phead)
	{
		*phead = (*phead)->next;
		free(pos);
		pos = NULL;
	}
	else
	{//有多个节点

		while (prev!=NULL&&prev->next != pos)
		{
			prev = prev->next;
		}
		//SL* tmp = prev->next;
		if (prev->next == pos)
		{
			prev->next = pos->next;
			free(pos);
			pos = NULL;
		}
	}
}

void SListDestroy(SL** phead)
{
	assert(*phead);
	while (*phead != NULL)
	{
		/*free(*phead);
		*phead = (*phead)->next;*/
		SL* cur = *phead;
		*phead = (*phead)->next;
		free(cur);
		cur = NULL;
	}
}
void SListInsertAfter(SL** phead, SL* pos, SLNodeDataType x)
{
	SL* newSL = buySLNode(x);
	if (*phead == NULL)
	{
		*phead = newSL;
	}
	else
	{
		SL* cur = *phead;
		while (cur!=pos)
		{
			cur = cur->next;
		}
		newSL->next = cur->next;
		cur->next = newSL;

	}
}


