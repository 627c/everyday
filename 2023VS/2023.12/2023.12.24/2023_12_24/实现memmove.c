#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
void* my_memmove(void* dest, void* src, size_t num)
{
	char* ret = dest;
	//dest<src,从前向后拷贝
	assert(dest != NULL);
	assert(src != NULL);
	if (dest < src)
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	//dest>src,从后向前拷贝
	else
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	my_memmove(arr, arr+2, 20);
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}