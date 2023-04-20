#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>//呵呵，投机取巧，通过15/24，匈牙利算法搞不懂,把数组分成奇数和偶数两个部分，然后遍历，看他们分别加起来等于素数的哪一种组合数最多，
#define N 101
int count = 0;
int oushu[N] = { 0 };
int jishu[N] = { 0 };
int flag[N] = { 0 };
int isjishu(int x) {
	if (x % 2 != 0) {
		return 1;
	}return 0;
}

int isPrime(int x) {
	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			return 0;//不是素数
		}
	}
	return 1;//是素数
}
int findmate(int ji[], int jinum, int ou[], int ounum) {
	int i, j;
	for (i = 0; i < jinum; i++) {
		for (j = 0; j < ounum; j++) {
			if (isPrime(ji[i] + ou[j]) && (flag[j] == 0)) {
				count++;
				flag[j] = 1;//flag[j]==0代表该偶数没有和奇数成功配对过
			}
		}
	}return count;

}
int main() {
	int n, j = 0,k=0;
	int i;
	scanf("%d", &n);
	int arr[N] = { 0 };
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	if (n == 1) {//只有一个数打印为0
		printf("%d", 0);
	}
	else if (n == 2) {//两个数就直接判断
		if (isPrime(arr[0] + arr[1])) {
			printf("%d", 1);
		}
		else {
			printf("%d", 0);
		}
	}
	else
	{

		//开始划分奇数还是偶数
		for (i = 0; i < n; i++) {
			if (isjishu(arr[i]))//是奇数
			{
				jishu[j++] = arr[i]; //printf("%d实际输", arr[i]);
			}
			else
			{
				oushu[k++] = arr[i];
			}
		}  printf("%d", findmate(jishu, j, oushu, k));
	}

	return 0;
}
