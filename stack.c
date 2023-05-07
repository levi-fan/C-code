#include"stack.h"
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
void StackDestroy(ST* ps)
{
	assert(ps);
	assert(ps->a);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
void CheckCapacity(ST* ps)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		int newCapacity = (ps->capacity == 0) ? 5 : ps->capacity * 2;
		ST*tmp= (STDataType*)realloc(ps->a,newCapacity*sizeof(STDataType));//很严重的错误，写成了malloc,导致申请新的空间的时候原有的数据丢失，谨记谨记！！！！！
		if (tmp)
		{
			ps->a = tmp;
		}
		else
		{
			printf("realloc failed\n");
			exit(-1);
		}
		ps->capacity = newCapacity;
	}
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPrint(ST* ps)
{
	
	assert(ps);
	assert(ps->top);
	int i = 0;
	while (i < ps->top)
	{
		printf("%d ", ps->a[i]);
		i++;
	}
	printf("\n");
}
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top);
	ps->top--;

}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top);
	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)
{
	assert(ps);
	
	return ps->top;
}
bool StackEmpty(ST* ps)
{
	assert(ps);
	/*if (ps->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return ps->top == 0;
}
