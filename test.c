#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//int main()
//{ 
//	int i;
//	int ret = 1;
//	int sum = 0;  
//	int n;
//	scanf("%d", &n);//求n，n-1.n-2.......的阶乘的和
//	/*for (i = 1; i <= n; i++)
//	{
//		ret = 1;
//		for (int j = 1; j <= i; j++) {
//			ret = ret * j;
//		}
//		sum = sum + ret;
//	}*/
//	for (i = 1; i <= n; i++) {//另外一种算法（更简洁）
//		ret = ret * i;
//		sum = sum + ret;
//	}
//	printf("%d", sum);
//	return 0;
//} 
//
//int main() {
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };//自己写的二分查找算法
//	int k = 19;
//	int p=0, q=sizeof(arr)/sizeof(arr[0])-1;
//	
//	while (p<=q) {
//		int t = (p + q) / 2;
//		if (arr[t] == k) {
//			printf("下标是%d", t); break;
//		}
//		if (arr[t]<k) {
//			p = t + 1;
//		}
//		if (arr[t] > k) {
//			q = t - 1;
//		}
//	}
//	if (p > q)
//		printf("not found");
//	return 0;
//}
int main()   
{
	char str[] = { "welcome to bit!!!!!!!!" };
	char str2[] = { "######################" };
	int p = 0, q = strlen(str) - 1;
	printf("%s\n", str2);
	int i;
	while (p <= q) {
		str2[p] = str[p];
		str2[q] = str[q];
		printf("%s\n", str2);
		p++; q--;
	}





	return 0;
}