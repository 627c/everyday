#include<stdio.h>
int main()
{
	int num[26],i=0;
	char s[20]={'v','A','F','b','F','t','e','G','H','P','#','\0'};
	for(i=0;i<26;i++)  num[i]=0;
	i=0;
	while(s[i])
	{
		if((s[i]>=65)&&(s[i])<=90)
			num[s[i]-65]+=1;
		i++;
	}
	for(i=0;i<26;i++)
		if(num[i]) printf("%c:%d,",(char)(i+65),num[i]);
}