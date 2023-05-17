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
	for (i = 0; i < n - 1; i++)//����ôһ�������ң���
	{
		x = a[i+1];
		for (end =i; end >= 0; end--)//ÿһ�ΰ�xǰ��������ֱ���һ�����飬Ҳ����һ�������ڲ����ǵ��������ʵ����,ÿһ�ζ���X�����������ֵ����
			//�ԱȲ������Ƿ����
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
	assert(a);//�ֳ�gap���ٲ�������
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
		for (j = 0; j < n - gap; j++)//һ����
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
			if (a[i] < a[mini])//�ҵ����ֵ����Сֵ���±�
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
	int parent = i;//��Ҫ�����Ķѵĸ��ڵ�
	int child = parent * 2 + 1;
	while (child < n)//�������ڶ�����
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{//�Һ��Ӹ�С
			child++;
		}
		if (a[child] < a[parent])//С����С��
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;//����Ҫ����
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
	//����ȡ�У���ֹ���ʱ�临�Ӷ�
	int midi = GetMidIndex(a, left, right);//������΢������һ�㲻̫��
	Swap(&a[left], &a[midi]);
	int keyi =left;
	while (left < right)
	{
		while (left <right&&a[right] <=a[keyi])//�ٴ��ж����ұ߽��ֹ�±�Խ�磬���±�һֱѰ��С��key��ֵ���ҵ�������ȥ
		{
			right--;//�ֱ��ҵ�����key��С��key�������н���
		}
		while (left <right&&a[left] >= a[keyi])//����ĵ��ں���Ҫ�����Ҵ���kye��ֵ����ô�෴��������������С�ڵ���
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);
	return left;
}

int partion2(int* a, int left, int right)//�ڿӷ�
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
int partion3(int* a, int left, int right)//���������������
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
	{//ֻ��һ��ֵ����û��ֵ����Ϊ����
		return;
	}
	//С�����Ż�����������
	if (right - left + 1 < 10)
	{
		InsertSort(a + left, right - left + 1);//�������С��10���ǾͲ����еݹ����
	}

	else
	{
		int mid = partion3(a, left, right);//����˼�룬���������������˼�룬�ȰѸ�λ��ȷ����mid����С�������ұ�ȫ�����������ڶ���߽���
		//����ʹ����ߵ�ֵҲ����ͬ���ķ�ʽ�������
		QuickSort(a, left, mid - 1);
		QuickSort(a, mid + 1, right);
	}
	
	
	
}

void QuickSortNonR(int*a,int left,int right)//���ŵķǵݹ�
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
		StackPop(&st);//�ȴ���һ�ߣ�������һ�ߴ��ջ���棬�����������ֻ��һ��ֵ���߲����ھͲ���վ������ֵ�ʹ��ȥջ���棬Ȼ��ֻҪջ����
		//��Ϊ�վͰ�����ȡ����Ȼ���������
		int keyi = partion3(a, begin, end);//ÿ�ε��������˰�����������ջ
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
{//��������ұ�Ҳ����Ȼ�������������������������������˷Ž�ȥ�������������棬���εݹ�
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
void MergeSortNonR(int* a,int n)//�����Ƚϣ����ıȽϣ�����߽�ֵ
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