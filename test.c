#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//int main()
//{ 
//	int i;
//	int ret = 1;
//	int sum = 0;  
//	int n;
//	scanf("%d", &n);//��n��n-1.n-2.......�Ľ׳˵ĺ�
//	/*for (i = 1; i <= n; i++)
//	{
//		ret = 1;
//		for (int j = 1; j <= i; j++) {
//			ret = ret * j;
//		}
//		sum = sum + ret;
//	}*/
//	for (i = 1; i <= n; i++) {//����һ���㷨������ࣩ
//		ret = ret * i;
//		sum = sum + ret;
//	}
//	printf("%d", sum);
//	return 0;
//} 
//
//int main() {
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };//�Լ�д�Ķ��ֲ����㷨
//	int k = 19;
//	int p=0, q=sizeof(arr)/sizeof(arr[0])-1;
//	
//	while (p<=q) {
//		int t = (p + q) / 2;
//		if (arr[t] == k) {
//			printf("�±���%d", t); break;
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