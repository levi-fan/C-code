#include"SeqList.h"
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
void SeqListCheckCapacity(SL* ps)
{
	if (ps->capacity == ps->size)
	{
		int newcapacity = (ps->capacity==0) ? 5 : (ps->capacity) * 2;
		
		SLDataType* p1 = (SLDataType*)realloc(ps->a, newcapacity*sizeof(SLDataType));
		if (p1)
		{
			ps->a = p1;
			ps->capacity = newcapacity;
		}
		else
		{
			printf("%s\n", strerror(errno));
			exit(-1);
		}
	 }
}
void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
}
void SeqListPrint(SL* ps)//打印
{
	int i;
	for (i=0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	putchar('\n');
}
void SeqListPushBack(SL* ps, SLDataType x)//test传参数过来，通过指针对test中的结构体进行尾插
{
	//SeqListCheckCapacity(ps);//ps和上面的ps所指向的都是尾插函数里面的ps所指向的那个结构体，因此可以对结构体进行扩容，插入数值等
	//ps->a[ps->size] = x;
	//ps->size++;
	SeqListInsert(ps, ps->size, x);
}
void SeqListPushFront(SL* ps, SLDataType x)
{
	SeqListInsert(ps,0, x);

	/*SeqListCheckCapacity(ps);
	int end = ps->size;
	for (; end >= 1; end--)
	{
		ps->a[end] = ps->a[end - 1];
	}
	ps->a[0] = x;
	ps->size++;*/
}
void SeqListPopFront(SL* ps)
{
	SeqListDelete(ps, 0);
	/*assert(ps->size);
	int i;
	for (i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;*/
}//头删
void SeqListPopBack(SL* ps) 
{
	SeqListDelete(ps, ps->size-1);

	/*assert(ps->size);
	ps->size--;*/
}//尾删
SLDataType SeqListFind(SL* ps, int pos)
{
	assert(ps->size);
	if (pos >= 0 && pos <= ps->size - 1)
	{
		return ps->a[pos];
	}
	else
		return -1;
}
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	SeqListCheckCapacity(ps);
	int i = ps->size;
	while (i > pos)
	{
		ps->a[i] = ps->a[i - 1];
		i--;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SeqListDelete(SL* ps, int pos)
{
	assert(ps->size);
	int i = pos;
	while (i < ps->size)
	{
		ps->a[i] = ps->a[i + 1];
		i++;
	}
	ps->size--;
}




