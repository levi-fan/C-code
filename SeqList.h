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
void SeqListInit(SL* ps);//��ʼ��
void SeqListDestroy(SL* ps);//����
void SeqListPopBack(SL* ps);//βɾ
void SeqListPushBack(SL* ps, SLDataType x);//β��
void SeqListPopFront(SL* ps);//ͷɾ
void SeqListPushFront(SL* ps,SLDataType x);//ͷ��
void SeqListPrint(SL* ps);//��ӡ
void SeqListInsert(SL* ps,int pos,SLDataType x);
void SeqListDelete(SL* ps,int pos);
SLDataType SeqListFind(SL* ps,int pos);




