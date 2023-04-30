#include"SeqList.h"
void test1()
{
	SL p;
	SeqListInit(&p);
	SeqListPushBack(&p, 5);
	//SeqListPrint(&p);
	SeqListPushFront(&p, 1);
	SeqListPushFront(&p, 2);
	SeqListPushFront(&p, 3);
	SeqListPushFront(&p, 3);
	SeqListPushFront(&p, 3);
	SeqListPrint(&p);
	SeqListPopFront(&p);
	SeqListPopBack(&p);
	SeqListPrint(&p);
	SeqListDestroy(&p);
}
void test2()
{

	SL p;
	SeqListInit(&p);
	SeqListPushBack(&p, 5);
	//SeqListPrint(&p);
	SeqListPushFront(&p, 1);
	SeqListPushFront(&p, 2);
	SeqListPushFront(&p, 3);
	SeqListPushFront(&p, 3);
	SeqListPushFront(&p, 3);
	SeqListPrint(&p);
	SeqListPopBack(&p);
	SeqListPopBack(&p);
	SeqListPopFront(&p);
	SeqListPrint(&p);
	int n=SeqListFind(&p,3);
	//SeqListDestroy(&p);
	SeqListInsert(&p, 3, 11);
	SeqListPrint(&p);
	SeqListDelete(&p, 3);
	SeqListPrint(&p);
	SeqListDestroy(&p);

}
void menu()
{
	printf("*******************************\n");
	printf("***1->头删       2->尾删*******\n");
	printf("***3->头插       4->尾插*******\n");
	printf("***0->退出     ****************\n");
	printf("*******************************\n");

}
void test3()
{
	int input = 0;
	
	
	SL p;
	SeqListInit(&p);

	do
	{
		menu();
		printf("请输入您的操作：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:SeqListPopFront(&p); break;
		case 2:SeqListPopBack(&p); break;
		case 3: {int num = 0;
			printf("请输入您要插入的数据，以-1结尾：\n");
			while (num != -1)
			{
				scanf("%d", &num);
				if (num != -1)
					SeqListPushFront(&p, num);
			}
			break;
		}
		case 4: {int num1 = 0;
			printf("请输入您要插入的数据，以-1结尾：\n");
			while (num1 != -1)
			{
				scanf("%d", &num1);
				if (num1 != -1)

					SeqListPushFront(&p, num1);
			}
			break;
		default:break;
		}
		}
		SeqListPrint(&p);
	} while (input);
	
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}