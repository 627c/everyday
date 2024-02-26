#define _CRT_SECURE_NO_WARNINGS
#include <STC89C5xRC.H>

void Delay1ms(unsigned int xms)	//@12.000MHz
{
	unsigned char data i, j;
	while (xms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}

void main()
{
	while (1)
	{
		//		P20=0;
		//		Delay1ms(500);
		//		P20=1;
		//		Delay1ms(500);
		if (P31 == 0)
		{
			Delay1ms(20);
			while (P31 == 0);
			Delay1ms(20);

			P20 = ~P20;
		}
	}
}