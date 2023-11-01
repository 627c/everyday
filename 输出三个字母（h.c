#include<stdio.h>
int main()
{
	char ch,c1,c2;
	printf("enter a character:");
	ch=getchar();
	if((ch>='a')&&(ch<='z'))  ch-=32;
	c1=ch-1;
	c2=ch+1;
	if(ch=='A') c1=ch+25,c2=ch+1;
	if(ch=='Z') c1=ch-1,c2=ch-25;
	putchar(c1);
	putchar(ch);
	putchar(c2);
}