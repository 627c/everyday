#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10
void menu()
{
	printf("**********************\n");
	printf("*******1.  play*******\n");
	printf("*******0.  exit*******\n");
	printf("**********************\n");
}
void DisplayBoard(char board[ROWS][COLS],int row,int col)
{
	int i=0,j=0;
	//打印列号
	for(i=0;i<=col;i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	printf("%c",board[1][1]);
	for(i=1;i<=row;i++)
	{
		printf("%d ",i);
		for(j=1;j<=col;j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)
{
	int i=0,j=0;
	for(i=0;j<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			board[i][j]=set;
		}
	}
}
void SetMine(char board[ROWS][COLS],int row,int col)
{
	int count=EASY_COUNT;
	while(count)
	{
		int x=rand()%row+1;       //rand()%9  范围为0-8，+1为1-9
		int y=rand()%col+1;
		if(board[x][y]=='0')
		{
			board[x][y]='1';
			count--;
		}
	}
}
void game()
{
//	printf("lei\n");
	//雷的信息存储
	//1.布置好雷的信息
	char mine[ROWS][COLS]={0};   //11*11
	//2.排查出雷的信息
	char show[ROWS][COLS]={0};
	//初始化
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
	//打印棋盘
	DisplayBoard(mine,ROW,COL);
	DisplayBoard(show,ROW,COL);
	//布置雷
	SetMine(mine,ROW,COL);
	DisplayBoard(mine,ROW,COL);
}
void test()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：\n");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误，重新选择\n");
				break;
		}
	}while(input);
}
int main()
{
	test();
}