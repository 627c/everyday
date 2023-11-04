//链式访问
#include<stdio.h>
int main()
{
	printf("%d",printf("%d",printf("%d",43)));      //printf返回值是打印字符个数，最内层打印43，向外是2，然后是1
}