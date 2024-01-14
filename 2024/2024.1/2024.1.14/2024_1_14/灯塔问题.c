#define _CRT_SECURE_NO_WARNINGS
//一个8层的灯塔，每一层的灯数是上一层的2倍，一共765盏灯，求灯塔底层的灯数
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