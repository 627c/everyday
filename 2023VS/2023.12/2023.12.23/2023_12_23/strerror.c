#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
	//0.1.2.....���������룬ÿ���������Ӧһ��������Ϣ
	// errno,��һ��ȫ�ֵĴ�����ı���
	// ��C���ԵĿ⺯����ִ�й����У������˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����룬���ƴ�errno��
	//0-No error
	char* str = strerror(errno);
	printf("%s\n", str);
	char* str1 = strerror(0);
	printf("%s\n", str1);
	//1-Operation not permitted
	char* str2 = strerror(1);
	printf("%s\n", str2);
	//2-No such file or directory
	char* str3 = strerror(2);
	printf("%s\n", str3);
	return 0;
}