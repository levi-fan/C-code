#define _CRT_SECURE_NO_WARNIGS 1
#include<stdio.h>
#include<string.h>//字符串拷贝函数，不追加\0，不足的补0
//char* my_strncpy(char* str1, char* str2,int n)
//{
//	char* ret = str1;
//	while (n && (*str1 = *str2))
//
//	{
//		n--;
//		str1++;
//		str2++;//n--代表拷贝的目标字符串的字符数，第二个判定条件代表如果拷贝过去的字符为0，那么跳出这个循环，开始补0
//	}
//	if (n)//如果目标字符串数目不足，开始补0
//	{
//		while (n--)
//		{
//			*(++str1) = '\0';
//		}
//	}
//	//}
//	//	if (n)
//	//	{
//	//		while (--n)
//	//		{
//	//			*str1++ = '\0';
//	//		}
//	//	}
//	return ret;
//		
//	
//}
//
//int main()
//{
//	char str1[30] = { "hello world" };
//	char str2[] = { "bits" };
//	my_strncpy(str1, str2,6);
//	puts(str1);
//	return 0;
//}
//字符串追加函数,需要追加\0
char* my_strncat(char* des, char* src, int n)
{
	char* ret = des;
	while (*des)
	{
		des++;//跳出来的时候刚好是\0
		}
		//while (n && (*des = *src))//跳出循环时，指针已经指到需要被添加\0的目标字符串那个位置，
		//{
		//	n--;
		//	des++;
		//	src++;
		//}
		//*des = '\0';
		//return ret;
		while (n-- && (*des++ = *src++))
		{
			;
		}
		*des = '\0';
		return ret;
	}

int main()
{
	char str1[40] = { "hello world\0#############" };
	char str2[] = "bits";
	puts(my_strncat(str1, str2, 8));
	return 0;
}

