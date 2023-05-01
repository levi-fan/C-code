#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int removeDuplicates(int* nums, int numsSize) {
    int* dst = nums;
    int* begin = nums;
    int* end = nums + 1;
    while (end < nums + numsSize)
    {
        while (*begin == *end)
        {
            end++;
        }
        *dst = *begin;
        begin = end;
        end++;
        dst++;
    }
    *dst = *begin;
    return (dst - nums + 1);
}
int main()
{
    int arr[] = {1,1,2};
    int k= removeDuplicates(arr,3);
    printf("%d", k);
   // memmove(arr, arr + 2, 9);
    return 0;
}