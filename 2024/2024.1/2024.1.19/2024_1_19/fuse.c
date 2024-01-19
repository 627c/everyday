#include "fuse.h"
#include "speed.h"
#include "function.h"
#include "direction.h"
#include "gyroscope.h"



Body Flag;                  //�ṹ�嶨�����ؼ���־λ
int16 Turn_PWM = 0;   //����ת��PWM
int16 ADC_Left_y,ADC_Right_y,ADC_LR_ADD,ADC_LR_SUB;
pid DirectionPID;
uint8 lose_flag=0;
uint8 charge_over=0,send_flag=0;
uint8 time_count_star=0;
uint8 i;
/*******************PIT��ʱ�ж�******************
������void Fuse_result(void)
���ܣ��ٶȻ���ת�򻷿���
������  ��
˵����
����ֵ����
���ڣ� 2023-6-26   */
unsigned char int_OK=0;//��ʼ���ɹ���־λ

#define chasu_max 200
uint8 servo_error;

void Fuse_result(void)
{
    if(int_OK)                //��ʼ���ɹ�
    {
        //5ms����
        if(1==Flag.T_Inmost)
        {
            Flag.T_Inmost = 0;
            Turn_PWM=duty;
            if(Turn_PWM>chasu_max) Turn_PWM=chasu_max;
            if(Turn_PWM<-chasu_max) Turn_PWM=-chasu_max;
            All_PWM_left = L_Speed_PWM-Turn_PWM*6.5;  //��1�� 4.5
            All_PWM_right = R_Speed_PWM+Turn_PWM*6.5;

            go_motor(All_PWM_left,All_PWM_right);          //�������
        }


        //10ms���� ����
        if(1==Flag.T_Turn)
        {
            Flag.T_Turn=0;
            if(chuku_flag==0)          //����
            {
                aim_speed=150;
                duty=200;
                Steering_Control_Out(35);
                yaw_angle=Yaw;
                chuku_flag=1;
                cnt=0;
            }
            else if(chuku_flag==1&&abs(Yaw - yaw_angle) > 79)  //����  abs(Yaw - yaw_angle) > 70
            {

                duty=0;
                aim_speed=-250;
                Steering_Control_Out(0);
                cnt_star=1;
                cnt_dir=1;
                time_count_star=1;
                chuku_flag=2;
            }
            else if(cnt<-2800&&chuku_flag==2)                 //tof���??��ײ����磬ֹͣ
            {
                gpio_set_level(B10, GPIO_HIGH);                  //��ʼ���
                chuku_flag=3;
                cnt_star=0;
                cnt=0;
                aim_speed=0;
                time_count_star=0;

            }

            else if(chuku_flag==3&&charge_over==1)               //�󳵻ظ��������رշ��䣬�����ش�������
            {
                send_flag=1;
                gpio_set_level(B10, GPIO_LOW);                  //�رճ��
                for(i=0;i<10;i++)
                {
                    bluetooth_ch9141_send_string("O");
                }
                chuku_flag=4;
            }
            else if(chuku_flag==4)                              //����ѭ��
            {
                aim_speed=500;
                Electromagnetism_Control();//��Ųɼ�����
            }


        }

        //50ms����     �ٶ�
        if(1==Flag.T_Speed)
        {
            Flag.T_Speed=0;
            L_Speed_PWM =  PID_Realize(&L_SpeedPID, Speed_Pid, left_speed,aim_speed);//�ٶ�λ��ʽPID
            R_Speed_PWM =  PID_Realize(&R_SpeedPID, Speed_Pid, right_speed,aim_speed);//�ٶ�λ��ʽPID
        }
      }

}

