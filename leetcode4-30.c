#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;
    int j = n - 1;
    int dst = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] >= nums2[j])
        {
            nums1[dst] = nums1[i];
            dst--;
            i--;
            //j--;
        }
        else
        {
            nums1[dst] = nums2[j];
            dst--;
            // i--;
            j--;
        }
    }
    while (j >= 0)
    {
        nums1[j] = nums2[j];
        j--;
    }

}
int main()
{
    int arr[] = {1,2,3,0,0,0};
    int arr2[] = { 4,5,6 };
    merge(arr, 4, 3, arr2, 4, 3);
    for (int i = 0; i < 6; i++)
        printf("%d", arr[i]);
   // int k= removeDuplicates(arr,2);
  //  printf("%d", k);
   // memmove(arr, arr + 2, 9);
    return 0;
}