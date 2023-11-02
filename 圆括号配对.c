#include<stdio.h>
int main()
{
	int left,right;char c;
	printf("输入一个算术表达式\n");
	left=0;right=0;
	for(c=0;(c=getchar())!='\n';)
	{
		if(c=='(')  left++;
		if(c==')')  right++;
		if(right>left)  break;
	}
	if(left==right)  printf("圆括号配对正确\n");
	else  printf("圆括号配对不正确\n");
}