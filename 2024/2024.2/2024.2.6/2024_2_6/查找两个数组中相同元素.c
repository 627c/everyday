#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0;
    for (i = 0, j = 0; i < nums1Size && j < nums2Size; i++, j++)
    {
        if (nums1[i] == nums2[j])
        {
            return nums1[i];
        }
        else if (nums1[i] < nums2[j])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    return -1;
}
int main()
{
    int arr1[] = { 1,2,5,7,9 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = { 5,9,10 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n", getCommon(arr1, size1, arr2, size2));
    return 0;
}