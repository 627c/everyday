#define _CRT_SECURE_NO_WARNINGS
//һ��8��ĵ�����ÿһ��ĵ�������һ���2����һ��765յ�ƣ�������ײ�ĵ���
#include<stdio.h>
int main()
{
	int i,n;
	float m = 1.0, sum = 1.0;
	for (i = 1; i < 8; i++)
	{
		m = m / 2;
		sum += m;
	}
	n = 765 / sum;
	printf("%d", n);
	return 0;
}