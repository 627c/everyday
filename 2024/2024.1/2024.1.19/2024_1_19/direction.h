#ifndef DIRECTION_H_
#define DIRECTION_H_
#include "zf_common_headfile.h"

//舵机相关值
#define Steer_Duty_Max  815
#define Steer_Duty_Midle 737   //中值
#define Steer_Duty_Min  665
//--全局变量声明---

//---------变量声明-----------
extern uint16  adc_date[6];                //储存电感采集值
extern uint16  adc_max[6];               //最大值
extern  int16  Left_Adc,Right_Adc,Left_Xie_Adc,Right_Xie_Adc,Left_Shu_Adc,Right_Shu_Adc;//电感值
extern int16 duty,chuku_duty;
extern uint8 shizi,circle1,circle2,circle3,jinhuan,chuhuanqian;
//电磁部分结构体变量
extern float he;
extern uint8 chuku_flag,ruku_flag;
extern int16 yaw_angle,t_count;

//-----函数声明---
void init_Steer_PWM(void);
void Steering_Control_Out(int16 duty);

void ADC_Int();    //电磁ADC通道初始化
void AD_Date_Fitier();/////////电感滑动滤波
void Electromagnetism_Control();

#endif /* DIRECTION_H_ */
