#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void sub(char s[], char t[])
{
	int i, d;
	d = strlen(s);
	for (i = 0; i < d; i++)
		t[i] = s[d - i - 1];
	for (i = 0; i < d; i++)
		t[d + i] = s[i];
	t[2 * d] = '\0';
}
int main()
{
	char s[100], t[100];
	printf("please enter string s:");
	scanf("%s", s);
	sub(s, t);
	printf("\nthe result is:%s\n", t);
	return 0;
}