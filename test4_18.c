//��������2�㷨���Գ�����
//1��100֮����ֶ��ٸ�����9����Ϊ�������������Ƶģ�ȡ10��ģ������ģֵȡ9��ģ����0������Ϊ�������Ǹ�������Ѷ��ˣ����ˣ�ʮλ���ǿ�����
//1/1-1/2+1/3........��1/100�ĺͣ�flag��������)
//��Ϸ�����������srandֻ��Ҫ���������е���һ�Σ������ɱ�֤ÿһ���ն�����ʱ������������ֵ��һ����
//����srand�е��õ���ʱ�亯��������ÿ��srand�����ֵ����һ�������srand�ŵ���Ϸ�������棬
//��ô����������ϸ�����ģ���Ϊÿһ�ε���srand�������ú�������ʱ�����ȷ����ʼλ�ã��������������
//�������൱��ÿ���ն˵���ʼ���ֶ���һ�����ﵽĿ�ġ�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
//����
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
//1��100֮����ֶ��ٸ�����9
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
//�������������Ϸ
//void game() {
//	int ret = 0;
//	int guess = 0;
//	ret = rand()%100+1;
//	//printf("%d\n", ret);
//
//	while (1) {
//		printf("������һ������->\n");
//		scanf("%d", &guess);
//		if (guess < ret)
//		{
//			printf("�µ���̫С��\n");
//		}
//		else if (guess > ret)
//		{
//			printf("�µ���̫����\n");
//		}
//		else
//		{
//			printf("��ϲ����ˣ�\n"); break;
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
//		case 1:printf("��ʼ��Ϸ��\n"); game(); break;
//		case 0:printf("��Ϸ������\n"); break;
//		default:printf("�������\n"); break;
//
//		}
//	} while (input);
//
//
//
//	return 0;
//}
//�ػ�С����
//int main() {
//	system("shutdown -s -t 120");
//	char str[20];
//	again:
//	printf("��ĵ��Խ���120��֮��ػ�������ػ����ӡ��������\n");
//	gets(str);
//	if (strcmp(str, "������") == 0) {
//		system("shutdown -a");
//	}
//	else
//	{
//		goto  again;
//	}
//
//	return 0;
//}

