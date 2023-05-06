#include"List.h"
void test1()
{
	SL* plist = ListInit();
	ListPushBack(plist,1);
	ListPushBack(plist,2);
	ListPushBack(plist,3);
	ListPushBack(plist,4);
	ListPushBack(plist,5);
	ListPrint(plist);
	/*ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);*/
	//ListPopBack(plist);
	ListPrint(plist);
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPushFront(plist, 5);
	/*ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);*/
	//ListPopFront(plist);


	ListPrint(plist);
	ListDestroy(plist);
	plist = NULL;


}
void test2()
{
	SL* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPushFront(plist, 5);
	ListPrint(plist);

	//ListPopFront(plist);

	SL* cur = ListFind(plist,5);
	printf("%d\n", cur->data);
	ListErase(cur);
	ListPrint(plist);

	//ListDestroy(plist);
	//plist = NULL;


}
int main()
{
	test1();
	//test2();
	return 0;
}