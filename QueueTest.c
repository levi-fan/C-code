#include"Queue.h"

void test1()
{
	Queue pq;//pq是一个包含头尾指针的结构体，把这个结构体的地址传递给p,那P就可以通过解引用对pq内部的头尾指针进行操作，也就是可以操作队列
	QueueInit(&pq);
	//QueueDestroy(&pq);
	QueuePush(&pq, 1);
	QueuePush(&pq, 2);
	QueuePush(&pq, 3);
	QueuePush(&pq, 4);
	QueuePush(&pq, 5);
	QueuePush(&pq, 6);
	QueuePrint(&pq);
	QueuePop(&pq);
	QueuePop(&pq);
	QueuePop(&pq);
	QueuePop(&pq);
	//QueuePop(&pq);
	//QueuePop(&pq);
	//QueuePop(&pq);

	QueuePrint(&pq);
	int num = QueueSize(&pq);
	printf("%d\n", num);
	while (num--)
	{
		printf("%d ", QueueBack(&pq));
		QueuePop(&pq);
	}


}


  
    MyStack* myStackCreate()
    {
        MyStack* ret = (MyStack*)malloc(sizeof(MyStack));
        QueueInit(&(ret->q1));
        QueueInit(&(ret->q2));
        return ret;
    }

    void myStackPush(MyStack * obj, int x) {
        if (!QueueEmpty(&obj->q1))
        {
            QueuePush(&obj->q1, x);
        }
        else
        {
            QueuePush(&obj->q2, x);

        }

    }

    int myStackPop(MyStack * obj) {
        Queue* empty = &obj->q1;
        Queue* nonempty = &obj->q2;
        if (!QueueEmpty(&obj->q1))
        {
            empty = &obj->q2;
            nonempty = &obj->q1;
        }
        while (QueueSize(nonempty) > 1)
        {
            QueuePush(empty, QueueFront(nonempty));
            QueuePop(nonempty);
        }
        int front = QueueFront(nonempty);
        QueuePop(nonempty);
        return front;

    }

    int myStackTop(MyStack * obj) {
        if (!QueueEmpty(&obj->q1))
        {
            return QueueBack(&obj->q1);
        }
        else
        {
            return QueueBack(&obj->q2);

        }

    }

    bool myStackEmpty(MyStack * obj) {
        return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);

    }

    void myStackFree(MyStack * obj) {
        QueueDestroy(&obj->q1);
        QueueDestroy(&obj->q2);
        free(obj);


    }

int main()
{
    MyStack* my = myStackCreate();
    myStackPush(my, 1);
    myStackPush(my, 2);
    myStackPush(my, 3);
    myStackPush(my, 4);
    myStackPop(my);
   // myStackFree(my);
	//test1();
	
	return 0;
}