#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SLNodeDataType;
typedef struct SLNode
{
	SLNodeDataType data;
	struct SLNode* next;
}SL;
void SListPrint(SL* phead);
void SListPushBack(SL** phead, SLNodeDataType x);
void SListPushFront(SL** phead, SLNodeDataType x);
void SListPopBack(SL** phead);
void SListPopFront(SL** phead);
SL* SlistFind(SL* phead, SLNodeDataType x);
void SListInsert(SL** phead, SL* pos, SLNodeDataType x);
void SListErase(SL** phead, SL* pos);
void SListDestroy(SL** phead);
void SListInsertAfter(SL** phead, SL* pos, SLNodeDataType x);

