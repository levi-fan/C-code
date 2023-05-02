#include"SList.h"
void test1()
{
	SL* slist;
	SListPushBack(&slist, 1);
	SListPushBack(&slist, 2);
	SListPushBack(&slist, 3);
	SListPushBack(&slist, 4);
	SListPushBack(&slist, 5);
	//SListPrint(slist);
}
int main()
{
	test1();
	return 0;
}