#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int arr[10] = { 0 };
	int(*p)[10] = &arr;//ȡ������ĵ�ַ
	int(*pf)(int, int);//����ָ��
	int(*pfArr[4])(int, int);//pfArr��һ�����飬����ָ������
	int(*(*ppfArr)[4])(int, int) = &pfArr;
	//ppfArr��һ������ָ�룬ָ��ָ����������ĸ�Ԫ��
	//ָ�������ÿ��Ԫ�ص�������һ������ָ�� int(*)(int,int)
	return 0;
}