#define _CRT_SECURE_NO_WARNINGS
#include "headfile.h"

uint8 z = 50;


// �����ں�Ƶ�ʵ��趨�����Բ鿴board.h�ļ�
// ��board_init��,�Ѿ���P54��������Ϊ��λ
// �����Ҫʹ��P54����,������board.c�ļ��е�board_init()������ɾ��SET_P54_RESRT����

void main()
{
	clock_init(SYSTEM_CLOCK_52M);	// ��ʼ��ϵͳƵ��,��ɾ���˾���롣
	board_init();					// ��ʼ���Ĵ���,��ɾ���˾���롣
	ips114_init();
	servo_init();
	motor_init();
	Adv_init();

	seekfree_wireless_init();  //��ʼ�����ߴ���
	pit_timer_ms(TIM_4, 5);	   //��ʱ��4  5ms�ж�
	EnableGlobalIRQ();		//�������ж�

	// �˴���д�û����� ���������ʼ�������

	// �˴���д�û����� ���������ʼ�������


	while (1)
	{
		// �˴���д��Ҫѭ��ִ�еĴ���

		// �˴���д��Ҫѭ��ִ�еĴ���
			//	 ANODT_SendF1(80,Left_Encoder,Right_Encoder);   //��λ������
		display();                                      //ips����ʾ����
		////	 control();   
		//P52 = 0;
		//if(Hall==0)	 
		//{
		//Buzz=1;
		//}
	}
}