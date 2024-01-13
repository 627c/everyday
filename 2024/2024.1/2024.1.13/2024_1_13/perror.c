#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	FILE* pf = fopen("test2.txt", "r");
	if (pf == NULL)
	{
		perror("hehe");
		return 0;
	}
	fclose(pf);
	pf = NULL;
	return 0;
}