#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void fun(char a[], int n)
{
	//int m = strlen(a);
	//int i = 0;
	//char a1[20];
	//char a2[20];
	//for (i = 0; i < n; i++)
	//{
	//	a1[i] = a[i];
	//}
	//for (i = n; i < m; i++)
	//{
	//	a2[i - n] = a[i];
	//}
	//for (i = 0; i < m - n; i++)
	//{
	//	a[i] = a2[i];
	//}
	//for (i = m - n ; i < m; i++)
	//{
	//	a[i] = a1[i + n - m ];
	//}
	int i, j;
	char t;
	for (i = 0; i < n; i++)
	{
		t = a[0];
		for (j = 1; a[j] != '\0'; j++)
		{
			a[j - 1] = a[j];
		}
		a[j - 1] = t;
	}
}
int main()
{
	char a[20] = "ABCDEFGHIJK";
	int n = 3;
	fun(a, n);
	printf("%s\n", a);
	return 0;
}