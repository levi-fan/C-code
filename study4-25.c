#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>//
#include<assert.h>
char* my_strstr(const char* des, const char* src)
{
	
	assert(des && src);//���߲���Ϊ��ָ��
	char* p1 = des;
	char* p2 = src;
	char* cur = des;//��ǰ��ָ��
	while (*cur)//�жϵ�ǰָ��ָ����ַ�����0
	{
		p1 = cur;
		p2 = src;
		while (*p1 && *p2 && *p1 == *p2)//Ŀ���ַ�����Դ�ַ����������ַ���������0���Ҷ������
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')//��������Դ�ַ���Ϊ0˵���Ѿ���Ŀ���ַ������ҵ����ַ���
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