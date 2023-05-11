#include"Heap.h"
void test1()
{
	HP hp;
	HeapInit(&hp);
	//HeapDestroy(&hp);
	HeapEmpty(&hp);
	HeapPrint(&hp);
	HeapPush(&hp,88);
	HeapPush(&hp, 56);
	HeapPush(&hp, 78);
	HeapPush(&hp, 38);
	HeapPush(&hp, 60);
	HeapPush(&hp, 0);

	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapDestroy(&hp);

}
void test2()
{
	HP hp;
	HeapInit(&hp);
	HeapPush(&hp, 88);
	HeapPush(&hp, 56);
	HeapPush(&hp, 78);
	HeapPush(&hp, 38);
	HeapPush(&hp, 60);
	HeapPush(&hp, 0);
	HeapPush(&hp, 99);
	HeapPush(&hp, 100);
	HeapPush(&hp, 75);
	HeapPush(&hp, 90);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	printf("%d\n", HeapSize(&hp));
	int n = HeapSize(&hp);
	int i;
	for (i = 0; i <n; i++)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
		//printf("%d", i);
	}
	printf("%d", i);
	HeapDestroy(&hp);



}
void testTopK(HpDataType*a,int num,int k)
{
	//找出最大的前K个数，先把数组里面的前K个数存进一个小根堆里面，然后用剩下的num-k个数来和堆顶元素比较，如果大于就存进去然后调整
	HP hp;
	HeapInit(&hp);
	int i;
	for (i = 0; i < k; i++)
	{
		HeapPush(&hp, a[i]);//存进小根堆里面
	}
	for (i = k; i < num - k; i++)
	{
		if (a[i] > HeapTop(&hp))
		{
			HeapPop(&hp);//删除堆顶元素，插入新的数
			HeapPush(&hp, a[i]);
			//hp.a[0] = a[i];
			//AdjustDown(hp.a, hp.size);
		}
	}
	HeapPrint(&hp);
	HeapDestroy(&hp);
}
void test_sort()
{
	HP hp;
	HeapInit(&hp);
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	int i;
	for (i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		HeapPush(&hp,a[i]);
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	HeapDestroy(&hp);
}
void test3()
{
	int a[] = {70,56,30,25,15,10,75};
	int i = 0;
	while (i < 7)
	{
		AdjustUp(a, i);
		i++;
	}
	i = 0;
	while (i < 7)
	{
		printf("%d ", a[i]);
		i++;
	}
}
void HeapSort()
{
	int a[] = { 2,7,5,12,22,17,25,19,11,36,99,23,28,46,92 };
	int n = sizeof(a) / sizeof(a[0]);
	int i;
	/*for (i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}*/
	int parent = (n - 1 - 1) / 2;//构建小堆，降序
	while (parent >= 0)
	{
		AdjustDown(a, n, parent);
		parent--;
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
		
	}
	putchar('\n');
	for (i = n-1; i >0 ; i--)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);
	}	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
typedef char BTDataType;
typedef struct BinaryTree
{
	struct BinaryTree* left;
	struct BinaryTree* right;
	BTDataType data;
}BT;
BT* buyTree(BTDataType ch)
{
	BT* node = (BT*)malloc(sizeof(BT*));
	node->data = ch;
	node->left = node->right = NULL;
	return node;
}
BT* TreeCreate()
{
	//BT* ret;
	BT* TreeA = buyTree('A');
	BT* TreeB = buyTree('B');
	BT* TreeC = buyTree('C');
	BT* TreeD = buyTree('D');
	BT* TreeE = buyTree('E');
	BT* TreeF = buyTree('F');
	BT* TreeG = buyTree('G');
	TreeA->left = TreeB;
	TreeA->right = TreeC;
	TreeB->left = TreeD;
	TreeB->right = TreeG;

	TreeC->left = TreeE;
	TreeC->right = TreeF;
	//TreeD->right = TreeG;

	return TreeA;
}

void prevOrder(BT*root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	prevOrder(root->left);
	prevOrder(root->right);
 }
void inOrder(BT* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	inOrder(root->left);
	printf("%c ", root->data);
	inOrder(root->right);

}
int pastOrder(BT* root,int*pi)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	pastOrder(root->left,pi);
	pastOrder(root->right,pi);
	printf("%c ", root->data);
	(*pi)++;
}

int BinarySize(BT* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinarySize(root->left) + BinarySize(root->right) + 1;
}
int BinaryTreeleafSize(BT* root)
{
	if (root == NULL)//是空节点就返回0
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)//是叶子节点
	{
		return 1;
	}
	return BinaryTreeleafSize(root->left) + BinaryTreeleafSize(root->right);//说明不是空节点也不是叶子节点，那么就把这个任务交给它左右孩子，让左右孩子
	//分别去算他们的叶子节点然后加起来就等于根节点的叶子节点数
}
int BinaryTreeLevelkSize(BT* root,BTDataType k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)//如果是求这个节点的第一层，那么只有一个元素，返回1
	{
		return 1;
	}
	return BinaryTreeLevelkSize(root->left, k - 1) + BinaryTreeLevelkSize(root->right, k - 1);

}
int BinaryTreeDeepth(BT* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	int leftdeep = BinaryTreeDeepth(root->left);
	
	int rightdeep = BinaryTreeDeepth(root->right);
	return leftdeep > rightdeep ? leftdeep+1 : rightdeep+1;

}
BT* BinaryTreeFind(BT* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTDataType* leftret = BinaryTreeFind(root->left , x);
	if (leftret)
	{
		return leftret;
	}
	BTDataType* rightret = BinaryTreeFind(root->right, x);
	if (rightret)
	{
		return rightret;
	}
	return NULL;

}
//int main()
//{
//	BT* root = TreeCreate();
//
//	int i = 0;
//	printf("%d", pastOrder(root,&i));
//	/* prevOrder(root);
//	 putchar('\n');
//	 inOrder(root);
//	 putchar('\n');
//	 pastOrder(root);*/
//	//HeapSort();
//	//test1();
//	//test2();
//	/*int n = 10000;
//	HpDataType* a = (HpDataType*)malloc(sizeof(HpDataType) * n);
//	srand((unsigned)time(NULL));
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		a[i] = rand() % n;
//	}
//	a[68] = 10001;
//	a[69] = 10002;
//	a[57] = 10005;
//	a[88] = 10006;
//	a[89] = 10007;
//	a[98] = 10008;
//	a[38] = 10009;
//	a[80] = 10003;
//	a[33] = 10004;
//	a[85] = 10000;*/
//	
//
//	//testTopK(a,n,10);
//	//test_sort();
//	//test3();
//
//	return 0;
//}
bool IsBinaryTree(BT*root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))//层序遍历
	{
		BT* tmp = QueueFront(&q);
		QueuePop(&q);
		//printf("%c ", tmp->data);
		/*if (tmp->left)
		{
			QueuePush(&q, tmp->left);
		}
		if (tmp->right)
		{
			QueuePush(&q, tmp->right);
		}*/
		if (tmp == NULL)
		{
			break;
		}
		QueuePush(&q, tmp->left);
		QueuePush(&q, tmp->right);
	}
	while (!QueueEmpty(&q))
	{
		BT* cur = QueueFront(&q);
		QueuePop(&q);
		if (cur != NULL)//如果队列里面发现空指针的后面出现了非空节点，就说明不是完全二叉树，
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
	QueueDestroy(&q);
}

void BinaryDestroy(BT* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryDestroy(root->left);
	BinaryDestroy(root->right);
	free(root);
}
int main()
{
	BT* root = TreeCreate();
	//bool ret= IsBinaryTree(root);
	BinaryDestroy(root);
	//printf("%d ", ret);
	return 0;
}