#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct S
{
	int n;
	int arr[0]; //δ֪��С��-���������Ա-����Ĵ�С�ǿ��Ե�����
};
int main()
{
	//printf("%d\n", sizeof(struct S));  //4
	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));//���ٵĿռ�����
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