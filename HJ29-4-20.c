#define _CRT_SECURE_NO_WARNINGS 1//
#include<stdio.h>//呵呵，这么简单，太粗心了写这么久，细心一点，加油！！！！
#define N 1001
#include<string.h>
int main() {
	//加密 解密
	char str1[N];
	char str2[N];
	int i,len1,len2;
	gets(str1);
	//gets();
	gets(str2);
    len1 = strlen(str1);
    len2 = strlen(str2);
	for (i = 0; i < len1; i++) {
		if (str1[i] == '9') {
			str1[i] = '0';
		}
		else if(str1[i]=='z') {
			str1[i]='A';
		}
		else if (str1[i] == 'Z') {
			str1[i] = 'a';
		}
		else if (str1[i] < '9' && str1[i] >= '0') {
			str1[i] = str1[i] + 1;
		}
		else if (str1[i] < 'z' && str1[i] >= 'a') {
			str1[i] = str1[i] + 1-32;
		}
		else if (str1[i] < 'Z' && str1[i] >= 'A') {
			str1[i] = str1[i] + 1+32;
		}
		
	}
	for (i = 0; i < len2; i++) {
		if (str2[i] == '0') {
			str2[i] = '9';
		}
		else if (str2[i] == 'a') {
			str2[i] = 'Z';
		}
		else if (str2[i] == 'A') {
			str2[i] = 'z';
		}
		else if (str2[i] <= '9' && str2[i] > '0') {
			str2[i] = str2[i] -1;
		}
		else if (str2[i] <='z' && str2[i] > 'a') {
			str2[i] = str2[i] -33;
		}
		else if (str2[i] <= 'Z' && str2[i] > 'A') {
			str2[i] = str2[i] +31;
		}

	}
	printf("%s\n", str1);
	printf("%s", str2);

	return 0;
}
