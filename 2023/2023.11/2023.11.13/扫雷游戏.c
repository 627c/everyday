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
int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	//周围坐标里面值加起来就为雷的个数，‘1’-‘0’=1
	return mine[x-1][y]+
	mine[x-1][y+1]+
	mine[x][y+1]+
	mine[x+1][y+1]+
	mine[x+1][y]+
	mine[x+1][y-1]+
	mine[x][y-1]+
	mine[x-1][y-1]-8*'0';
}
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
	int x=0;
	int y=0;
	int win=0;
	//9*9-10
	while(win<row*col-EASY_COUNT)
	{
		printf("请输入排查雷的坐标：");
		scanf("%d%d",&x,&y);
		if(x>=1&&x<=row&&y>=1&&y<=col)
		{
			//坐标合法
			//1.踩雷
			if(mine[x][y]=='1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine,row,col);
				break;
			}
			else   //不是雷
			{
				//计算x，y坐标周围有几个雷
				int count=get_mine_count(mine,x,y);
				show[x][y]=count+'0';
				DisplayBoard(show,row,col);
				win++;
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入\n");
		}
	}
	if(win==row*col-EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine,row,col);
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
	//查找雷
	FindMine(mine,show,ROW,COL);
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