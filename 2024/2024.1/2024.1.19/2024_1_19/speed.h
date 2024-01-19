#ifndef SPEED_H_
#define SPEED_H_
#include "zf_common_headfile.h"

 /********�ٶ�ȫ�ֱ���***********/
extern unsigned char MOTOR_MODE;
extern int16 right_speed;     //����
extern int16 left_speed;      //����
extern int16 real_speed;      //ʵʱ�ٶ�
extern int16 aim_speed,Set_Speed;    //Ŀ���ٶ�
extern int16 R_aim_speed, L_aim_speed;
extern int16 All_PWM_left;     //����PWM
extern int16 All_PWM_right;    //����PWM
extern int16 L_Speed_PWM;         //�ٶȻ�PWM
extern int16 R_Speed_PWM;         //�ٶȻ�PWM
extern int16 Speed_PWM;       //�ٶȻ�
extern int16 Last_Speed_PWM;


extern int32 distance,cnt;  //��������·��
extern float Speed_Pid[4];      // �ٶȻ�PID

extern int8 cnt_star,cnt_dir;

/******�ٶȺ�������*********/
void encoder_init(void);
void speed_measure(void);//����

void init_PWM(unsigned char Motor_Set);
void go_motor (int16 left_PWM,int16 right_PWM);     //�������
float Speed_P_I_Control(float *PID, int16 speed, int16 set_speed);//��Ϊ�Ƕȱ仯С����Ҫ�Ǹ�����

#endif /* SPEED_H_ */
