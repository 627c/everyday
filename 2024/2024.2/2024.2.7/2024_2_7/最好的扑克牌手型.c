#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
char* bestHand(int* ranks, int ranksSize, char* suits, int suitsSize) {
    int i = 0, j = 0;
    int count1[5] = { 0 };
    int count = 0;
    for (i = 0; i < ranksSize; i++)
    {
        for (j = 0; j < ranksSize; j++)
        {
            if (ranks[i] == ranks[j])
            {
                count1[i]++;
            }
        }
    }
    count = count1[0];
    for (i = 0; i < ranksSize; i++)
    {
        if (count1[i] > count)
        {
            count = count1[i];
        }
    }
    for (j = 1; j < suitsSize; j++)
    {
        if (suits[0] == suits[j])
        {
            continue;
        }
        break;
    }
    if (j >= 5)
    {
        return "Flush";
    }
    else if (count >= 3)
    {
        return "Three of a Kind";
    }
    else if (count == 2)
    {
        return "Pair";
    }
    else
    {
        return "High Card";
    }
}
int main()
{
    int str1[] = { 4,3,6,5,4 };
    int size1 = 5;
    char str2[] = {'a','a','a','a','a'};
    int size2 = 5;
    printf("%s\n", bestHand(str1, size1, str2, size2));
    return 0;
}