#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//二维数组为每行升序，每列升序的数组
//下面为功能函数的实现
int Find(int target, int** array, int arrayRowLen, int* arrayColLen) {
    // write code here
    int row = 0, col = *arrayColLen - 1;
    while (row < arrayRowLen && col >= 0)
    {
        if (target == array[row][col])
        {
            return 1;
        }
        else if (target > array[row][col])
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    return 0;

}