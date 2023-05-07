#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;//队列的节点，与链表无异
}QueueNode;


typedef struct Queue//控制队列的头尾指针被封装在一个结构体里面
{
	QueueNode* head;
	QueueNode* tail;
}Queue;
//顺序表传的是一级指针，单链表传递二级指针，带头双向循环链表传递一级指针，栈传递一级指针，队列传递一级指针，
typedef struct {
	Queue q1;
	Queue q2;
} MyStack;

void QueueInit(Queue* p);
void QueueDestroy(Queue* p);
void QueuePush(Queue* p,QDataType x);
void QueuePop(Queue* p);

QDataType QueueBack(Queue* p);
QDataType QueueFront(Queue* p);
bool QueueEmpty(Queue* p);
int QueueSize(Queue* p);
void QueuePrint(Queue* p);