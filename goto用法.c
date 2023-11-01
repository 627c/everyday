//#include<stdio.h>
//int main()
//{
//	again:
//		printf("hello jiangnan\n");
//		goto again;               //goto的用法，死循环
//}
//#include<stdio.h>
//int main()
//{
//	printf("hello jiangnan\n");
//	goto again;                  //跳过你好，可能会导致程序逻辑混乱
//	printf("你好\n");
//	again:
//		printf("hehe\n");
//}
//goto终止多层循环，直接跳到最外层
//for(...)
//	for(...)
//		for(...)
//			...
//			{
//				if(disaster)
//					goto error;
//			}
//error:
//	if(disaster)
//	处理错误情况



//关机程序
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char input[20]={0};
	//shutdown -s-t 60  命令，60秒后关机，  cmd，command 命令行   shutdown -a  取消关机
	//system()   执行系统命令
	system("shutdown -s -t 60");
again:
	printf("请注意你的电脑在一分钟内关机，如果输入：我是猪，就取消关机\n请输入>:");
	scanf("%s",input);
	if(strcmp(input,"我是猪")==0)     //比较两个字符串 strcmp()
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
}