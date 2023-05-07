#include"Queue.h"
void QueueInit(Queue* p)
{
	assert(p);
	p->head = NULL;
	p->tail = NULL;
}
void QueueDestroy(Queue* p)
{
	assert(p);
	QueueNode* cur = p->head;
	while (cur!= NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	p->tail=p->tail = NULL;
	//free(p);//main函数里面的结构体变量所在的那片空间也变为空
	////p = NULL;
}
QueueNode* BuyNewnode(QDataType x)//返回一个包含next和data的节点
{
	QueueNode* tmp = (QueueNode*)malloc(sizeof(QueueNode));
	if (tmp)
	{
		tmp->data = x;
		tmp->next = NULL;
		return tmp;
	}
	else
	{
		printf("malloc failed\n");
		exit(-1);
	}
}



void QueuePush(Queue* p, QDataType x)
{
	assert(p);
	QueueNode* newnode= BuyNewnode(x);
	if (p->head == NULL)
	{
		p->head=p->tail = newnode;
	}
	else
	{
		p->tail->next = newnode;
		p->tail = newnode;
	}
}


void QueuePrint(Queue* p)
{
	assert(p);
	assert(p->head);
	QueueNode* cur = p->head;
	while (cur !=NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}




void QueuePop(Queue* p)
{
	assert(p);
	assert(p->head);
	QueueNode* next = p->head->next;
	free(p->head);
	p->head = next;
	if (p->head == NULL)
	{
		p->tail = NULL;
	}
}

QDataType QueueBack(Queue* p)
{
	assert(p);
	assert(p->head);
	return p->tail->data;
}
QDataType QueueFront(Queue* p)
{
	assert(p);
	assert(p->head);
	return p->head->data;

}
bool QueueEmpty(Queue* p)
{
	assert(p);
	return p->head == NULL;
}
int QueueSize(Queue* p)
{
	QueueNode* cur = p->head;
	int i = 0;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	return i;
}