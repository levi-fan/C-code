#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int STDataType;

typedef struct List
{
	STDataType data;
	struct List* prev;
	struct List* next;
}SL;

SL* ListInit();
void ListPrint(SL* head);
SL* buyListNode(STDataType x);



void ListPushBack(SL* head,STDataType x);
void ListPopBack(SL* head);
void ListPushFront(SL* head,STDataType x);
void ListPopFront(SL* head);



SL* ListFind(SL* head,STDataType x);
void ListErase(SL*pos);
void ListInsert(SL*pos, STDataType x);
void ListDestroy(SL* head);