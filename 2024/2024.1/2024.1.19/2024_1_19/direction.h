#ifndef DIRECTION_H_
#define DIRECTION_H_
#include "zf_common_headfile.h"

//������ֵ
#define Steer_Duty_Max  815
#define Steer_Duty_Midle 737   //��ֵ
#define Steer_Duty_Min  665
//--ȫ�ֱ�������---

//---------��������-----------
extern uint16  adc_date[6];                //�����вɼ�ֵ
extern uint16  adc_max[6];               //���ֵ
extern  int16  Left_Adc,Right_Adc,Left_Xie_Adc,Right_Xie_Adc,Left_Shu_Adc,Right_Shu_Adc;//���ֵ
extern int16 duty,chuku_duty;
extern uint8 shizi,circle1,circle2,circle3,jinhuan,chuhuanqian;
//��Ų��ֽṹ�����
extern float he;
extern uint8 chuku_flag,ruku_flag;
extern int16 yaw_angle,t_count;

//-----��������---
void init_Steer_PWM(void);
void Steering_Control_Out(int16 duty);

void ADC_Int();    //���ADCͨ����ʼ��
void AD_Date_Fitier();/////////��л����˲�
void Electromagnetism_Control();

#endif /* DIRECTION_H_ */
