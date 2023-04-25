#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>//
#include<assert.h>
char* my_strstr(const char* des, const char* src)
{
	
	assert(des && src);//两者不能为空指针
	char* p1 = des;
	char* p2 = src;
	char* cur = des;//当前的指针
	while (*cur)//判断当前指针指向的字符不是0
	{
		p1 = cur;
		p2 = src;
		while (*p1 && *p2 && *p1 == *p2)//目标字符串和源字符串被检查的字符都不等于0，且二者相等
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')//跳出来的源字符串为0说明已经在目标字符串中找到子字符串
		{
			return cur;
		}
		cur++;
	}

}
int main()
{
	/*char str1[] = "abcdefgh";
	char str2[] = "def";

	*/
	char str1[80] = { 0 };
	char str2[80] = { 0 };
	gets(str1);
	gets(str2);
	puts(my_strstr(str1, str2));
	return 0;
}