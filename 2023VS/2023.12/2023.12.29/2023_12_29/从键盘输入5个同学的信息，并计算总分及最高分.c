#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct stu
{
	char num[20];
	char name[10];
	float math;
	float engl;
	float clan;
}s[5];
int main()
{
	int i = 0;
	float sum[5];
	for (i = 0; i < 5; i++)
	{
		scanf("%s%s%f%f%f", s[i].num, s[i].name, &s[i].math, &s[i].engl, &s[i].clan);
		sum[i] = s[i].math + s[i].engl + s[i].clan;
	}
	int imax = 0;
	int imin = 0;
	for (i = 0; i < 5; i++)
	{
		if (sum[i] > sum[imax])
			imax = i;
		else
			imin = i;
	}
	printf("总分最高的同学学号：%s，姓名：%s，总分：%.2f\n", s[imax].num, s[imax].name, sum[imax]);
	printf("总分最低的同学学号：%s，姓名：%s，总分：%.2f\n", s[imin].num, s[imin].name, sum[imin]);
	return 0;
}