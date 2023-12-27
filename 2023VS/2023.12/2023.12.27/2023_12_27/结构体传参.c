#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct S
{
	int a;
	char c;
	double d;
};
void Init(struct S* tmp)
{
	tmp->a = 100;
	tmp->c = 'w';
	tmp->d = 3.14;
}
int main()
{
	struct S s = { 0 };
	Init(&s);
	printf("%d %c %lf\n", s.a,s.c,s.d);
	return 0;
}