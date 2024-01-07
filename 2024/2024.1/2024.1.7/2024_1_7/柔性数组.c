#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct S
{
	int n;
	int arr[0]; //未知大小的-柔性数组成员-数组的大小是可以调整的
};
int main()
{
	//printf("%d\n", sizeof(struct S));  //4
	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));//开辟的空间连续
	ps->n = 100;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	free(ps);
	ps = NULL;
	return 0;
}