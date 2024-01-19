#include "speed.h"

/***********�ٶȸ���������**************/
int16 aim_speed,Set_Speed ;         //Ŀ���ٶ�
int16 R_aim_speed, L_aim_speed;


int16 real_speed;        //ʵʱ�ٶ�
int16 Speed_Min;

int16 right_speed;       //�����ٶ�
int16 left_speed;        //�����ٶ�
int16 last_speed;        //��һ���ٶ�
int16 Last_right_speed;//�����ϴ��ٶ�
int16 Last_left_speed;//�����ϴ��ٶ�
int32 distance=0;          //�������ߵ�·��
int32 cnt;
int8 cnt_star,cnt_dir;

int16 Speed_PWM=0;         //�ٶȻ�PWM
int16 L_Speed_PWM=0;         //�ٶȻ�PWM
int16 R_Speed_PWM=0;         //�ٶȻ�PWM
int16 All_PWM_left=0;     //����PWM
int16 All_PWM_right=0;    //����PWM




/*****************��������ʼ��*****************
������void encoder_init(void)
���ܣ���������ʼ��
������  ��
˵����ctimer_count_init(CTIM0_P34);
      ������ʹ��TIM3��TIM4�����������ֻ���޸ĺ궨�弴��
      ������ʹ�ô�����ı�����������֧���������룩
����ֵ��
���ڣ� 2021-3-25��00:59
�޸����ڣ�2023-6-25  */
void encoder_init(void)
{
    encoder_dir_init(ENCODER_L, ENCODER_L_DIR, ENCODER_L_LSB);                  // ��ʼ��������ģ�������� ������������ģʽ
    encoder_dir_init(ENCODER_R, ENCODER_R_DIR, ENCODER_R_LSB);                  // ��ʼ��������ģ�������� ������������ģʽ
}
/*****************�ٶȲ���*****************
������void speed_measure(void)
���ܣ�����ʵʱ�ٶȣ������ֵ�ƽ���ٶ� �������ɼ�ֵ��
������  ��
˵����  �ú������Բ���ٶȣ���ȡ�ٶȺ������ٴθ�λ���㣬�Ѱ�����
����ֵ��
���ڣ� 2021-1-12-20:30
�޸����ڣ�2023-6-25 */
void speed_measure(void)
{
    ////////////////////////���ֲ���//////////Right//////
    right_speed = -encoder_get_count(ENCODER_R);
    encoder_clear_count(ENCODER_R);

    //////////////////// ���ֲ���/////////Left///////////////
    left_speed = encoder_get_count(ENCODER_L);
    encoder_clear_count(ENCODER_L);

    //////////////////////�����������ʹ�������ȡ����/////////////////

    real_speed = (right_speed+left_speed)/2;        // �ٶ�ƽ��ֵ
    last_speed = real_speed;

    distance +=(right_speed+left_speed)*0.1;    //�����  ��Ϊ����Ϊ��λ

    if(cnt_star)
    {
        if(cnt_dir)
        {
            cnt+=right_speed;
        }
        else
        {
            cnt+=left_speed;
        }

    }
}


/******************** �����ʼ��***************
������void init_PWM(void)
������  ��
˵����  ��ĸ10000
      pwm_init(PWMA_CH1P_P60, 10000, 0);     //��ʼ��PWM5  ʹ������P2.5  ���PWMƵ��10000HZ   ռ�ձ�Ϊ�ٷ�֮ pwm_duty / PWM_DUTY_MAX * 100
����ֵ����
���ڣ�2021-5-27
�޸����ڣ�2023-6-25  */
unsigned char MOTOR_MODE=0;//�����޸�ɾ��
void init_PWM(unsigned char Motor_Set)
{
    MOTOR_MODE = Motor_Set;
    if (MOTOR_MODE==0)      //����DRV
    {
        gpio_init(DIR_L, GPO, GPIO_HIGH, GPO_PUSH_PULL);                            // GPIO ��ʼ��Ϊ��� Ĭ�����������
        pwm_init(PWM_L, 17000, 0);                                                  // PWM ͨ����ʼ��Ƶ�� 17KHz ռ�ձȳ�ʼΪ 0

        gpio_init(DIR_R, GPO, GPIO_HIGH, GPO_PUSH_PULL);                            // GPIO ��ʼ��Ϊ��� Ĭ�����������
        pwm_init(PWM_R, 17000, 0);                                                  // PWM ͨ����ʼ��Ƶ�� 17KHz ռ�ձȳ�ʼΪ 0
    }
    else
    {
        gpio_init(DIR_L, GPO, GPIO_HIGH, GPO_PUSH_PULL);                            // GPIO ��ʼ��Ϊ��� Ĭ�����������
        pwm_init(PWM_L, 17000, 0);                                                  // PWM ͨ����ʼ��Ƶ�� 17KHz ռ�ձȳ�ʼΪ 0

        gpio_init(DIR_R, GPO, GPIO_HIGH, GPO_PUSH_PULL);                            // GPIO ��ʼ��Ϊ��� Ĭ�����������
        pwm_init(PWM_R, 17000, 0);                                                  // PWM ͨ����ʼ��Ƶ�� 17KHz ռ�ձȳ�ʼΪ 0
    }
}

/****************************������**********************
������void go_motor (int16 left_PWM,int16 right_PWM)
������  int16 left_PWM,int16 right_PWM
˵����pwm_duty(PWMA_CH1P_P60, duty);
      ��ؽ����ӵĵ���߼��������һ������һ�����������������ڶ������������ҵ��
      ����Ĳ������Ϊ�����������ת����ֵ��ת����������
����ֵ����
���ڣ�2021-5-27-��23:00
�޸����ڣ�2023-6-25-��23:00 */
#define Duty_Max  2500   //�޷����ֵ9500

void go_motor (int16 left_PWM,int16 right_PWM)
{
    if  (MOTOR_MODE==0)
    {
        //-------MOS����--------
        if (left_PWM>0)           //����
        {
            left_PWM = left_PWM<=Duty_Max ? left_PWM : Duty_Max;
            gpio_set_level(DIR_L, GPIO_LOW);                                         // DIR����ߵ�ƽ
            pwm_set_duty(PWM_L, left_PWM);                                             // ����ռ�ձ�
        }
        else
        {
            left_PWM = left_PWM>=-Duty_Max ? (-left_PWM) : Duty_Max;
            gpio_set_level(DIR_L, GPIO_HIGH);                                         // DIR����ߵ�ƽ
            pwm_set_duty(PWM_L, left_PWM);                                             // ����ռ�ձ�
        }

        if (right_PWM>0)           //����
        {
            right_PWM = right_PWM<=Duty_Max ? right_PWM : Duty_Max;
            gpio_set_level(DIR_R, GPIO_LOW);                                         // DIR����ߵ�ƽ
            pwm_set_duty(PWM_R, right_PWM);                                             // ����ռ�ձ�
        }
        else
        {
            right_PWM = right_PWM>=-Duty_Max ? (-right_PWM) : Duty_Max;
            gpio_set_level(DIR_R, GPIO_HIGH);                                         // DIR����ߵ�ƽ
            pwm_set_duty(PWM_R, right_PWM);                                             // ����ռ�ձ�
        }
    }
    else
    {
        //-------MOS����--------
        if (left_PWM>0)           //����
        {
            left_PWM = left_PWM<=Duty_Max ? left_PWM : Duty_Max;
            gpio_set_level(DIR_L, GPIO_LOW);                                         // DIR����ߵ�ƽ
            pwm_set_duty(PWM_L, left_PWM);                                             // ����ռ�ձ�
        }
        else
        {
            left_PWM = left_PWM>=-Duty_Max ? (-left_PWM) : Duty_Max;
            gpio_set_level(DIR_L, GPIO_HIGH);                                         // DIR����ߵ�ƽ
            pwm_set_duty(PWM_L, left_PWM);                                             // ����ռ�ձ�
        }

        if (right_PWM>0)           //����
        {
            right_PWM = right_PWM<=Duty_Max ? right_PWM : Duty_Max;
            gpio_set_level(DIR_R, GPIO_LOW);                                         // DIR����ߵ�ƽ
            pwm_set_duty(PWM_R, right_PWM);                                             // ����ռ�ձ�
        }
        else
        {
            right_PWM = right_PWM>=-Duty_Max ? (-right_PWM) : Duty_Max;
            gpio_set_level(DIR_R, GPIO_HIGH);                                         // DIR����ߵ�ƽ
            pwm_set_duty(PWM_R, right_PWM);                                             // ����ռ�ձ�
        }
}

}
