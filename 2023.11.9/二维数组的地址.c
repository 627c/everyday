#include<stdio.h>
int main()
{
	int arr[3][4]={{1,2,3},{4.5}};
	int i;
	for(i=0;i<3;i++)
	{
		int j;
		for(j=0;j<4;j++)
		{
			printf("&arr[%d][%d] = %p\n",i,j,&arr[i][j]);
		}
	}
}