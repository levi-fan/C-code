#define _CRT_SECURE_NO_WARINIGNS 1
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include"Queue.h"
typedef int HpDataType;
typedef struct Heap
{
	HpDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* p);
void HeapDestroy(HP* p);
void HeapPrint(HP* p);
void HeapPush(HP* p, HpDataType x);
void HeapPop(HP* p);
bool HeapEmpty(HP* p);
int HeapSize(HP* p);
HpDataType HeapTop(HP* p);
void AdjustUp(HpDataType* a, int child);//传递结构体的数组指针和插入的元素的位置下标
void AdjustDown(HpDataType* a, int heap_num,int i);
void AdjustUp(HpDataType* a, int child);//传递结构体的数组指针和插入的元素的位置下标

void AdjustDown(HpDataType* a, int heap_num, int i);
void Swap(HpDataType* p1, HpDataType* p2);

