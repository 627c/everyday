#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<errno.h>
struct S
{
	int n;
	float score;
	char arr[10];
};
int main()
{
	struct S s = { 0 };
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}
	//��ʽ������������
	fscanf(pf, "%d %f %s", &(s.n), &(s.score), s.arr);
	printf("%d %f %s\n", s.n, s.score, s.arr);
	fclose(pf);
	pf = NULL;
	return 0;
}