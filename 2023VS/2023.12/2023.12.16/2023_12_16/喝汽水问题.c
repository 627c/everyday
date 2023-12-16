#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以买多少汽水
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	//买回来的汽水喝掉
	total = money;
	empty = money;
	//换回来的汽水
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("total=%d\n", total);
	return 0;
	//总结total=2*money-1,一个空瓶0.5元，等价交换，1元能买到一瓶汽水和一个空瓶，
	// 相当于汽水值0.5元，而最后手里必须剩余一个空瓶，20-0.5=19.5，19.5/0.5=39
}