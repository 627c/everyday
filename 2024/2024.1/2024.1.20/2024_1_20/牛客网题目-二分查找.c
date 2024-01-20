#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int search(int* nums, int numsLen, int target) {
    // write code here
    if (numsLen == 0) return -1;
    int left = 0;
    int right = numsLen - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (target < nums[mid])
        {
            right = mid - 1;
        }
        else if (target > nums[mid])
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}