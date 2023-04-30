#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<errno.h>
#define N 100
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;
void SeqListCheckCapacity(SL* ps);
void SeqListInit(SL* ps);//初始化
void SeqListDestroy(SL* ps);//销毁
void SeqListPopBack(SL* ps);//尾删
void SeqListPushBack(SL* ps, SLDataType x);//尾插
void SeqListPopFront(SL* ps);//头删
void SeqListPushFront(SL* ps,SLDataType x);//头插
void SeqListPrint(SL* ps);//打印
void SeqListInsert(SL* ps,int pos,SLDataType x);
void SeqListDelete(SL* ps,int pos);
SLDataType SeqListFind(SL* ps,int pos);




