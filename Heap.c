#include"Heap.h"
void HeapInit(HP* p)
{
	assert(p);
	p->a = NULL;
	p->capacity = 0;
	p->size = 0;
}
void HeapDestroy(HP* p)
{
	assert(p);
	free(p->a);
	p->capacity = 0;
	p->size = 0;
}
void HeapPrint(HP* p)
{
	assert(p);
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		printf("%d ", p->a[i]);
	}
	printf("NULL\n");
}
void Swap(HpDataType* p1, HpDataType* p2)
{
	HpDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HpDataType* a, int child)//传递结构体的数组指针和插入的元素的位置下标
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child] < a[parent])//小根堆
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(HP* p, HpDataType x)
{
	assert(p);//先判断空间是否充足，然后申请新的节点，然后插入数组中，然后向上调整
	if (p->capacity == p->size)//申请新的空间
	{
		int newcapacity = p->capacity == 0 ? 4 : p->capacity * 2;
		HpDataType* tmp = (HpDataType*)realloc(p->a,newcapacity * sizeof(HpDataType));
		if (tmp)
		{
			p->a = tmp;
			p->capacity = newcapacity;
		}
		else
		{
			printf("realloc failed\n");
			exit(-1);
		}
	}
	//插入新的节点，尾插
	p->a[p->size] = x;
	p->size++;
	//向上调整成大堆或者小堆
	AdjustUp(p->a, p->size-1);

}
void AdjustDown(HpDataType* a, int heap_num,int i)
{
	assert(a);
	int parent = i;
	int child = parent * 2 + 1;//左孩子
	while (child <heap_num)//是叶子节点就退出,只有当孩子下标在数组范围内时才循环
	{
		if (child + 1 < heap_num && a[child+1] > a[child])//右孩子更小，调整
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;//不需要向下调整，直接退出，说明满足小根堆
		}
	}

}
void HeapPop(HP* p)
{//删除堆顶的节点，把该节点和尾节点交换，然后尾删，然后向下调整个堆
	assert(p);
	assert(!HeapEmpty(p));
	Swap(&p->a[0], &p->a[p->size - 1]);
	p->size--;
	AdjustDown(p->a, p->size,0);
}
bool HeapEmpty(HP* p)
{
	assert(p);
	return p->size == 0;

}
int HeapSize(HP* p)
{
	assert(p);
	return p->size;
}
HpDataType HeapTop(HP* p)
{
	assert(p);
	assert(!HeapEmpty(p));
	return p->a[0];
}