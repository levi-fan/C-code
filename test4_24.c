#define _CRT_SECURE_NO_WARNIGS 1
#include<stdio.h>
#include<string.h>//�ַ���������������׷��\0������Ĳ�0
//char* my_strncpy(char* str1, char* str2,int n)
//{
//	char* ret = str1;
//	while (n && (*str1 = *str2))
//
//	{
//		n--;
//		str1++;
//		str2++;//n--��������Ŀ���ַ������ַ������ڶ����ж������������������ȥ���ַ�Ϊ0����ô�������ѭ������ʼ��0
//	}
//	if (n)//���Ŀ���ַ�����Ŀ���㣬��ʼ��0
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
//�ַ���׷�Ӻ���,��Ҫ׷��\0
char* my_strncat(char* des, char* src, int n)
{
	char* ret = des;
	while (*des)
	{
		des++;//��������ʱ��պ���\0
		}
		//while (n && (*des = *src))//����ѭ��ʱ��ָ���Ѿ�ָ����Ҫ�����\0��Ŀ���ַ����Ǹ�λ�ã�
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

