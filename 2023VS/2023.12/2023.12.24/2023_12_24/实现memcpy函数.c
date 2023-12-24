#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
struct S
{
	char name[20];
	int age;
};
void* my_memcpy(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while(num--)
	{
		*(char*)dest = *(char*)src;
		++(char*)dest;
		++(char*)src;
	}
	return ret;
}
int main()
{
	struct S arr3[] = { {"张三",20},{"李四",30} };
	struct S arr4[3] = { 0 };
	my_memcpy(arr4, arr3, sizeof(arr3));
	int i = 0;
	for (i = 0; i < 2; i++)
		printf("%s,%d\n", arr4[i].name,arr4[i].age);
	return 0;
}