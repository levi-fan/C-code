#include"Sort.h"
#include"stack.h"
void InsertTest()
{
	int a[] = {9,1,2,5,7,4,8,6,3,5};
	int b[] = { 26,2,5,3,9,4,8,5,1,7 };
	
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int)); 
	/*SelectSort(b, sizeof(b) / sizeof(int));
	PrintArray(b, sizeof(b) / sizeof(int));*/

}
void HeapSortTest()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int b[] = { 26,2,5,3,9,4,8,5,1,7 };
	PrintArray(a, sizeof(a) / sizeof(int));
	PrintArray(b, sizeof(b) / sizeof(int));
	HeapSort(a, sizeof(a) / sizeof(int));
	HeapSort(b, sizeof(b) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	PrintArray(b, sizeof(b) / sizeof(int));


}
void BubbleSortTest()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int b[] = { 26,2,5,3,9,4,8,5,1,7 };
	PrintArray(a, sizeof(a) / sizeof(int));
	PrintArray(b, sizeof(b) / sizeof(int));
	BubbleSort(a, sizeof(a) / sizeof(int));
	BubbleSort(b, sizeof(b) / sizeof(int)); 
	PrintArray(a, sizeof(a) / sizeof(int));
	PrintArray(b, sizeof(b) / sizeof(int));
}
void QuickSortTest()
{
	int a[] = {10,6,7,1,3,9,4,2};
	int b[] = { 26,2,5,3,9,4,8,5,1,7 };
	PrintArray(a, sizeof(a) / sizeof(int));
	//PrintArray(b, sizeof(b) / sizeof(int));
	//partion(a, 0, (sizeof(a) / sizeof(int)) - 1);
	//QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	//QuickSort(a, 0, 9);
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	//QuickSort(a, 0, (sizeof(a) / sizeof(int)) - 1);
	
	//PrintArray(a, sizeof(a) / sizeof(int));

}

void QuickSortNonRTest()
{
	

}

void MergeSortNonRTest()
{
	int a[] = { 10,6,7,1,3,9,4,2,6 };
	int b[] = { 26,2,5,3,9,4,8,5,1,7 };
	PrintArray(a, sizeof(a) / sizeof(int));
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
int main()
{
	//InsertTest();
	//HeapSortTest();
	//BubbleSortTest();
	//QuickSortTest();
	//QuickSortNonRTest();
	MergeSortNonRTest();
	return 0;
}