#include<stdio.h>
#define URL "https://www.fishc.com"
#define NAME  "��C������"
#define BOSS "С����"
#define YEAR 2010
#define MONTH 5
#define DAY  20
int main() {
	printf("%s������%d��%d��%d��\n", NAME, YEAR, MONTH, DAY);
	printf("%s��%s������\n", NAME, BOSS);
	printf("%s��������%s\n",NAME,URL);
	return 0;
}
