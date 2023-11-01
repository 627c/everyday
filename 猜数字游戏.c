#include<stdio.h>
#include<stdlib.h>  //rand函数头文件
#include<time.h>    //头文件
void menu()
{
	printf("****************************\n");
	printf("****  1.play   0.exit   ****\n");
	printf("****************************\n");
}
void game()
{
	//生成随机数
	//拿时间戳设计随机数生成器
	//time_t time(time_t *timer)
	int ret=rand()%100+1;  //生成一个1~100随机数函数，无参，返回整型，rand()%n，生成0~n-1中的随机数字
	int guess=0;   //接收猜的数字
	printf("%d\n",ret);
	while(1)
	{
		printf("请猜数字：");
		scanf("%d",&guess);
		if(guess>ret)
		{
			printf("猜大了\n");
		}
		else if(guess<ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("猜对了\n");
			break;
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));         //NULL空指针
	int input;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				game();    //猜数字游戏的过程
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误\n");
				break;
		}
	}while(input);
}