#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int FirstNotRepeatingChar(char* str) {
    // write code here
    int sz = (sizeof(str)) / (sizeof(str[0]));
    int i = 0, j = 0, t,x=0;
    char tmp = str[0];
    for (i = 0; i < sz; i++)
    {
        for (j = i + 1; j < sz; j++)
        {
            if (str[j] == str[i])
            {
                for (t = j; t < sz - 1; t++) str[t] = str[t + 1];
                sz = sz - 1;
                x++;
                break;
            }
        }
        if (j == sz) return (i+x);
    }
    return -1;
}
int main()
{
    char str[] = "clock";
    printf("%d\n", FirstNotRepeatingChar(str));
    return 0;
}