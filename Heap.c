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

void AdjustUp(HpDataType* a, int child)//���ݽṹ�������ָ��Ͳ����Ԫ�ص�λ���±�
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child] < a[parent])//С����
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
	assert(p);//���жϿռ��Ƿ���㣬Ȼ�������µĽڵ㣬Ȼ����������У�Ȼ�����ϵ���
	if (p->capacity == p->size)//�����µĿռ�
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
	//�����µĽڵ㣬β��
	p->a[p->size] = x;
	p->size++;
	//���ϵ����ɴ�ѻ���С��
	AdjustUp(p->a, p->size-1);

}
void AdjustDown(HpDataType* a, int heap_num,int i)
{
	assert(a);
	int parent = i;
	int child = parent * 2 + 1;//����
	while (child <heap_num)//��Ҷ�ӽڵ���˳�,ֻ�е������±������鷶Χ��ʱ��ѭ��
	{
		if (child + 1 < heap_num && a[child+1] > a[child])//�Һ��Ӹ�С������
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
			break;//����Ҫ���µ�����ֱ���˳���˵������С����
		}
	}

}
void HeapPop(HP* p)
{//ɾ���Ѷ��Ľڵ㣬�Ѹýڵ��β�ڵ㽻����Ȼ��βɾ��Ȼ�����µ�������
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