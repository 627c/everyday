#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		//�ж�i�Ƿ�Ϊˮ�ɻ�������������
		//1.����i��λ��  ����λ��Ϊn
		int n = 1;
		int tmp = i;
		int sum = 0;
		while (tmp / 10)
		{
			n++;
			tmp /= 10;
		}
		//2.����i��ÿһλ��n�η�֮�ͣ�sum
		tmp = i;
		while (tmp)
		{
			sum += pow(tmp % 10, n);
			tmp /= 10;
		}
		//3.�Ƚ�i==sum
		if (i == sum)
		{
			printf("%d ", i);
		}
	}
	return 0;
}