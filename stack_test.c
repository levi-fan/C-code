#include"stack.h"
void test1()
{
	ST pStack;
	StackInit(&pStack);

	StackPush(&pStack, 1);
	StackPush(&pStack, 2);
	StackPush(&pStack, 3);
	StackPush(&pStack, 4);
	StackPush(&pStack, 5);
	StackPush(&pStack, 7);
	StackPush(&pStack, 7);
	StackPush(&pStack, 7);
	StackPush(&pStack, 7);
	
	StackPush(&pStack, 88);
	StackPush(&pStack, 99);
	StackPush(&pStack,1000);

	StackPrint(&pStack);
	StackPop(&pStack);
	StackPop(&pStack);
	StackPop(&pStack);
	StackPop(&pStack);
	StackPop(&pStack);
	StackPrint(&pStack);
	/*int top=StackTop(&pStack);
	printf("%d", top);*/
	int num = StackSize(&pStack);
	while (num--)
	{
		printf("%d ", StackTop(&pStack));
		StackPop(&pStack);

	}
	printf("%d", StackSize(&pStack));
	StackDestroy(&pStack);

}
void test2()
{
	ST pStack;
	StackInit(&pStack);
	StackPush(&pStack, 1);
	StackPush(&pStack, 2);
	StackPush(&pStack, 3);
	StackPush(&pStack, 5);
	StackPush(&pStack, 7);
	StackPush(&pStack, 88);
	/*StackPush(&pStack, 99);
	StackPush(&pStack, 1000);*/
	StackPrint(&pStack);

}
int main()
{
	test1();
	//test2();
	return 0;
}