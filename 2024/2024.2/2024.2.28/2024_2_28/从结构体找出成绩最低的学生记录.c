#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct S
{
	char num[20];
	float score;
};
void fun(struct S s[], struct S* p)
{
	int i = 0;
	*p = s[0];
	for (i = 0; i < 3; i++)
	{
		if (s[i].score < (*p).score)
		{
			*p = s[i];
		}
	}
}
int main()
{
	struct S s[] = {"111",89,"222",67,"333",99};
	struct S* p = &s;
	fun(s, p);
	printf("%f", p->score);
	return 0;
}