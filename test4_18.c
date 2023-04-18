//求素数，2算法（试除法）
//1到100之间出现多少个数字9（华为机试题做过类似的）取10的模，看看模值取9的模等于0不，华为机试题那个比这个难多了，服了，十位忘记考虑了
//1/1-1/2+1/3........到1/100的和（flag控制正负)
//游戏生成随机数，srand只需要在主函数中调用一次，这样可保证每一次终端运行时，随机数的起点值不一样，
//但是srand中调用的是时间函数，这样每次srand的起点值都不一样，如果srand放到游戏函数里面，
//那么随机数就是严格递增的，因为每一次调用srand函数，该函数根据时间戳来确定起始位置，导致随机数增大
//放外面相当于每次终端的起始数字都不一样，达到目的。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
//素数
//int main() 
//{
//
//	int i;
//	int count=0;
//	for (i = 101; i <= 200; i+=2) 
//		{int j;
//		for (j = 2; j <=sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (j >sqrt(i) ){
//			printf("%d\n", i);
//			count++;
//		}
//
//		}
//		printf("%d\n", count);
//		return 0;
//	}
//1到100之间出现多少个数字9
//int main() {
//	int i = 1;
//	
//	for (i = 1; i <= 100; i++) {
//		if (i % 10 == 9) {
//			printf("%d\n", i);
//		}
//		if (i / 10 == 9) {
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}
//int main() {
//	int i=1;
//	double sum = 0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++) {
//		sum +=(1.0 / i)*flag;
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}
//猜数字随机数游戏
//void game() {
//	int ret = 0;
//	int guess = 0;
//	ret = rand()%100+1;
//	//printf("%d\n", ret);
//
//	while (1) {
//		printf("请输入一个数字->\n");
//		scanf("%d", &guess);
//		if (guess < ret)
//		{
//			printf("猜的数太小了\n");
//		}
//		else if (guess > ret)
//		{
//			printf("猜的数太大了\n");
//		}
//		else
//		{
//			printf("恭喜答对了！\n"); break;
//		}
//		
//	}
//}
//int main() {
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do {
//		printf("########################\n");
//		printf("##1->paly    0->exit####\n");
//		printf("########################\n");
//		
//		scanf("%d", &input);
//		switch (input) {
//		case 1:printf("开始游戏！\n"); game(); break;
//		case 0:printf("游戏结束！\n"); break;
//		default:printf("输入出错！\n"); break;
//
//		}
//	} while (input);
//
//
//
//	return 0;
//}
//关机小程序
//int main() {
//	system("shutdown -s -t 120");
//	char str[20];
//	again:
//	printf("你的电脑将在120秒之后关机，不想关机请打印“我是猪”\n");
//	gets(str);
//	if (strcmp(str, "我是猪") == 0) {
//		system("shutdown -a");
//	}
//	else
//	{
//		goto  again;
//	}
//
//	return 0;
//}

