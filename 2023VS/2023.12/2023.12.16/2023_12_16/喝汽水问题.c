#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�������������ˮ
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	//���������ˮ�ȵ�
	total = money;
	empty = money;
	//����������ˮ
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("total=%d\n", total);
	return 0;
	//�ܽ�total=2*money-1,һ����ƿ0.5Ԫ���ȼ۽�����1Ԫ����һƿ��ˮ��һ����ƿ��
	// �൱����ˮֵ0.5Ԫ��������������ʣ��һ����ƿ��20-0.5=19.5��19.5/0.5=39
}