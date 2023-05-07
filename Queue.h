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
	struct QueueNode* next;//���еĽڵ㣬����������
}QueueNode;


typedef struct Queue//���ƶ��е�ͷβָ�뱻��װ��һ���ṹ������
{
	QueueNode* head;
	QueueNode* tail;
}Queue;
//˳�������һ��ָ�룬�������ݶ���ָ�룬��ͷ˫��ѭ��������һ��ָ�룬ջ����һ��ָ�룬���д���һ��ָ�룬
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