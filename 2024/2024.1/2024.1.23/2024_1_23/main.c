#define _CRT_SECURE_NO_WARNINGS
#include "headfile.h"

uint8 z = 50;


// 关于内核频率的设定，可以查看board.h文件
// 在board_init中,已经将P54引脚设置为复位
// 如果需要使用P54引脚,可以在board.c文件中的board_init()函数中删除SET_P54_RESRT即可

void main()
{
	clock_init(SYSTEM_CLOCK_52M);	// 初始化系统频率,勿删除此句代码。
	board_init();					// 初始化寄存器,勿删除此句代码。
	ips114_init();
	servo_init();
	motor_init();
	Adv_init();

	seekfree_wireless_init();  //初始化无线串口
	pit_timer_ms(TIM_4, 5);	   //定时器4  5ms中断
	EnableGlobalIRQ();		//开启总中断

	// 此处编写用户代码 例如外设初始化代码等

	// 此处编写用户代码 例如外设初始化代码等


	while (1)
	{
		// 此处编写需要循环执行的代码

		// 此处编写需要循环执行的代码
			//	 ANODT_SendF1(80,Left_Encoder,Right_Encoder);   //上位机调试
		display();                                      //ips屏显示函数
		////	 control();   
		//P52 = 0;
		//if(Hall==0)	 
		//{
		//Buzz=1;
		//}
	}
}