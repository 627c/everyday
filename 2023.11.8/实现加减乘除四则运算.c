#include<stdio.h>
int main()
{
	int a,b,d;
	char ch;
	printf("please input a expression:");
	scanf("%d%c%d",&a,&ch,&b);
	switch(ch)
	{
		case '+':d=a+b;printf("%d+%d=%d\n",a,b,d);break;
		case '-':d=a-b;printf("%d-%d=%d\n",a,b,d);break;
		case '*':d=a*b;printf("%d*%d=%d\n",a,b,d);break;
		case '/':if(b==0) printf("除数为0了\n");
				 else printf("%d/%d=%f\n",a,b,(float)(a/b));break;
		default :printf("input operator error!\n");
	}
}