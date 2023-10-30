#include<stdio.h>
#include<string.h>
int main()
{
	int i=0;
	char password[20]={};
	for(i=0;i<3;i++)
	{
		printf("请输入密码:");
		scanf("%s",password);
		if(strcmp(password,"123456")==0)   //库函数，用来判断字符串是否相同，不能直接关系等，==比较指针，也就是比较两个字符串的首地址
		{
			printf("登陆成功\n");
			break;
		}
		else
		{
			printf("密码错误\n");
		}
	}
	if(i==3) printf("三次密码均错误，退出程序\n");
}