#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = 0, j = 0, k = 0;
    int* p = (int*)malloc(4 * (m+n));
    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            p[k] = nums1[i];
            i++; k++;
        }
        else
        {
            p[k] = nums2[j];
            j++; k++;
        }
    }while (i < m)
    {
        p[k++] = nums1[i++];
    }
    while (j < n)
    {
        p[k++] = nums2[j++];
    }
       
    int t = 0;
    int tt = 0;
    while (tt < m + n)
    {
        nums1[t] = p[t];
        tt++; t++;
    }free(p);
    p = NULL;
   
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