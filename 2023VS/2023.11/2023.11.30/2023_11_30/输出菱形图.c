#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void a(int i)
{
	int j, k;
	for (j = 1; j < 30 - i; j++) printf("%c", ' ');
	for (k = 1; k <= 2 * i - 1; k++) printf("%d", i);
	printf("\n");
}
int main()
{
	int i;
	for (i = 1; i <= 7; i++) a(i);      //ÉÏ°ë²¿·Ö
	for (i = 6; i >= 1; i--) a(i);
	return 0;
}