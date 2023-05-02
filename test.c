#include"SList.h"
void test1()
{
	SL* slist=NULL;
	SListPushBack(&slist, 1);
	SListPushBack(&slist, 2);
	SListPushBack(&slist, 3);
	SListPushBack(&slist, 4);
	SListPushBack(&slist, 5);
	SListPrint(slist);
	SL* pos = SlistFind(slist, 1);
	SListInsertAfter(&slist, pos, 88);
	SListPrint(slist);
	/*SListPrint(slist);
	SListPushFront(&slist, 3);
	SListPushFront(&slist, 5);
	SListPushFront(&slist, 3);
	SListPushFront(&slist, 5);
	SListPrint(slist);
	SL* pos = SlistFind(slist, 5);
	SListPopFront(&slist);
	SListPopFront(&slist);
	SListPopFront(&slist);
	SListPopFront(&slist);
	SListPrint(slist);*/
	//SListDestroy(&slist);
	if (slist == NULL)
		printf("NULL");
	//SListInsert(&slist, pos, 33);
	//SListPrint(slist);
	//SListInsert(&slist, slist, 1000);
	//SListPrint(slist);

	//int i = 1;
	//
	//
	//	printf("第%d个节点：%p->%d\n", i++, pos, 3);
	//	//printf("插入之后：\n");
	//	SListErase(&slist, pos);
	//	SListPrint(slist);
       // pos = SlistFind(pos->next, 3);
	

	/*SListPopBack(&slist);
	SListPopBack(&slist);
	SListPopBack(&slist);
	SListPopBack(&slist);
	SListPrint(slist);
	SListPopFront(&slist);
	SListPopFront(&slist);
	SListPopFront(&slist);
	SListPopFront(&slist);*/
	//SListPopFront(&slist);

	/*SListPopFront(&slist);
	SListPopFront(&slist);
	SListPopFront(&slist);
	SListPopFront(&slist);*/
	//SListPrint(slist);

}
int main()
{
	test1();
	return 0;
}
