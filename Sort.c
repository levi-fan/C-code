#include"Sort.h"
#include"stack.h"
#include<string.h>
void PrintArray(int* a, int n)
{
	assert(a);
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void InsertSort(int* a, int n)
{
	assert(a);
	int end;
	int x;
	int i;
	for (i = 0; i < n - 1; i++)//有那么一丢丢混乱，日
	{
		x = a[i+1];
		for (end =i; end >= 0; end--)//每一次把x前面的数都分别看作一个数组，也就是一趟排序，内部就是单趟排序的实现了,每一次都把X和数组里面的值进行
			//对比并决定是否插入
		{
			if (x < a[end])
			{
				a[end + 1] = a[end];
			}
			else
			{
				break;
			}
		}
		a[end + 1] = x;
	}
	
}
void ShellSort(int* a, int n)
{
	assert(a);//分成gap组再插入排序
	int gap = 3;
	int i, j;
	while (gap > 1)
	{
		gap=((gap / 3) + 1);
	/*	for (i = 0; i < 3; i++)
		{
			for (j = i; j < n - gap; j += gap)
			{
				int end = j;
				int x = a[j + gap];
				for (end; end >= 0; end -= gap)
				{
					if (x > a[end])
					{
						a[end + gap] = a[end];
					}
					else
					{
						break;
					}
				}
				a[end + gap] = x;

			}
		}*/
		for (j = 0; j < n - gap; j++)//一锅炖
		{
			int end = j;
			int x = a[j + gap];
			for (end; end >= 0; end -= gap)
			{
				if (x > a[end])
				{
					a[end + gap] = a[end];
				}
				else
				{
					break;
				}
			}
			a[end + gap] = x;
		}
	}

}
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void SelectSort(int* a, int n)
{
	assert(a);
	int begin, end;
	begin = 0;
	end = n-1;
	int i;
	
	while (begin < end)
	{
		int maxi = begin, mini = begin;
		for (i = begin; i < end+1; i++)
		{
			if (a[i] < a[mini])//找到最大值和最小值的下标
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		begin++;
		
		Swap(&a[end], &a[maxi]);
		end--;
	}
}

void AdjustDown(int* a, int n, int i)
{
	assert(a);
	int parent = i;//需要调整的堆的根节点
	int child = parent * 2 + 1;
	while (child < n)//孩子属于二叉树
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{//右孩子更小
			child++;
		}
		if (a[child] < a[parent])//小于是小堆
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;//不需要调整
		}
	}
}
void HeapSort(int* a, int n)
{
	int parent = (n - 1 - 1) / 2;
	int i;
	for (i=parent; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	for (i = n - 1; i >0; i--)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);
	}
}

void BubbleSort(int* a, int n)
{
	/*assert(a);
	int i, j;
	for (i = 1; i < n; i++)
	{
		int flag = 0;
		for (j = 0; j < n - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				flag = 1;
				Swap(&a[j], &a[j + 1]);
			}
		}
		if (flag == 0)
		{
			break;
		}
	}*/
	assert(a);
	int i, j;
	for (i = n-1; i >0; i--)
	{
		int flag = 0;
		for (j = 0; j <i; j++)
		{
			if (a[j] < a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[right] < a[left])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[right] < a[mid])

		{
			return mid;
		}
		else if (a[right] > a[left])
		{
			return left;
		}
		else
		{
			return right;
		}
	}

}
int partion1(int* a, int left, int right)
{
	assert(a);
	//三数取中，防止最坏的时间复杂度
	int midi = GetMidIndex(a, left, right);//这里稍微还是有一点不太懂
	Swap(&a[left], &a[midi]);
	int keyi =left;
	while (left < right)
	{
		while (left <right&&a[right] <=a[keyi])//再次判断左右边界防止下标越界，右下标一直寻找小于key的值，找到就跳出去
		{
			right--;//分别找到大于key和小于key的数进行交换
		}
		while (left <right&&a[left] >= a[keyi])//这里的等于很重要，是找大于kye的值，那么相反继续的条件就是小于等于
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);
	return left;
}

int partion2(int* a, int left, int right)//挖坑法
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midi]);
	int keyi = a[left];
	int pivot = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		Swap(&a[pivot], &a[right]);
		pivot = right;
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		Swap(&a[pivot], &a[left]);
		pivot = left;
	}
	a[pivot] = keyi;
	return pivot;
}
int partion3(int* a, int left, int right)//掌握这个，还不错，
{
	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		/*while (cur <= right && a[cur] >= a[keyi])
		{
			cur++;
		}
		Swap(&a[cur], &a[++prev]);
		cur++;*/
		if (a[cur] < a[keyi])
		{
			Swap(&a[cur], &a[++prev]);
		}cur++;
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
	/*int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[right]);
	int keyi = right;
	int  cur = left;
	int prev = cur - 1;
	while (cur < right)
	{
		if (a[cur] < a[keyi])
		{
			Swap(&a[cur], &a[++prev]);
		}
		cur++;
	}
	Swap(&a[prev + 1], &a[keyi]);
	return prev + 1;*/
}
void QuickSort(int* a, int left,int right)
{
	
	if (left >= right)
	{//只有一个值或者没有值，认为有序
		return;
	}
	//小区间优化！！！！！
	if (right - left + 1 < 10)
	{
		InsertSort(a + left, right - left + 1);//如果个数小于10，那就不进行递归调用
	}

	else
	{
		int mid = partion3(a, left, right);//分治思想，先序遍历，二叉树思想，先把根位置确定，mid的左小于它，右边全都大于它，在对左边进行
		//排序，使得左边的值也按照同样的方式变得有序
		QuickSort(a, left, mid - 1);
		QuickSort(a, mid + 1, right);
	}
	
	
	
}

void QuickSortNonR(int*a,int left,int right)//快排的非递归
{
	ST st;
	StackInit(&st);
	StackPush(&st, left);
	StackPush(&st, right);
	while (!StackEmpty(&st))
	{
		int end = StackTop(&st);
		StackPop(&st);
		int begin = StackTop(&st);
		StackPop(&st);//先处理一边，把另外一边存进栈里面，如果区间里面只有一个值或者不存在就不如站，存在值就存进去栈里面，然后只要栈里面
		//不为空就把数据取出来然后进行排序
		int keyi = partion3(a, begin, end);//每次单趟排完了把左右区间入栈
		if (keyi + 1 < end)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, end);
		}
		if (keyi - 1 > begin)
		{
			StackPush(&st, begin);
			StackPush(&st, keyi - 1);
		}
	}
	StackDestroy(&st);
}
void _MergeSort(int* a, int left, int right,int*tmp)
{//左边有序，右边也有序，然后借助第三方数组把左右数组排完序了放进去第三方数组里面，依次递归
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);
	int begin1 = left, end1 = mid;
	int i = left;
	int begin2 = mid + 1, end2 = right;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	for (int j = left; j <= right; j++)
	{
		a[j] = tmp[j];
	}
	
}
void MergeSort(int* a, int n)
{
	assert(a);
	
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc failed\n");
		exit(-1);
	}
	_MergeSort(a, 0,n-1,tmp);
	free(tmp);
	tmp = NULL;
}
void MergeSortNonR(int* a,int n)//两两比较，四四比较，处理边界值
{
	int gap = 1;
	int i  ;
	//int j = 0;
	int* tmp = (int*)malloc(sizeof(int) * n);
	//memset(tmp, 0, n * sizeof(int));
	for (gap;gap<n;gap*=2)
	{
		for (i = 0; i <n; i += 2 * gap)
		{
			int j = i;
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			if (end1 >= n)
			{
				end1 = n - 1;
			}
			if (begin2 >= n)
			{
				begin2 = n + 5;
				end2 = n + 2;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
		}
		for (int k = 0; k < n; k++)
		{
			a[k] = tmp[k];
		}
	}
	
	free(tmp);
	tmp = NULL;

}