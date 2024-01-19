#include "speed.h"

/***********速度各变量声明**************/
int16 aim_speed,Set_Speed ;         //目标速度
int16 R_aim_speed, L_aim_speed;


int16 real_speed;        //实时速度
int16 Speed_Min;

int16 right_speed;       //右轮速度
int16 left_speed;        //左轮速度
int16 last_speed;        //上一次速度
int16 Last_right_speed;//右轮上次速度
int16 Last_left_speed;//左轮上次速度
int32 distance=0;          //车子行走的路程
int32 cnt;
int8 cnt_star,cnt_dir;

int16 Speed_PWM=0;         //速度环PWM
int16 L_Speed_PWM=0;         //速度环PWM
int16 R_Speed_PWM=0;         //速度环PWM
int16 All_PWM_left=0;     //左轮PWM
int16 All_PWM_right=0;    //右轮PWM




/*****************编码器初始化*****************
函数：void encoder_init(void)
功能：编码器初始化
参数：  无
说明：ctimer_count_init(CTIM0_P34);
      编码器使用TIM3和TIM4，如更改引脚只需修改宏定义即可
      编码器使用带方向的编码器（好像不支持正交解码）
返回值：
日期： 2021-3-25晚00:59
修改日期：2023-6-25  */
void encoder_init(void)
{
    encoder_dir_init(ENCODER_L, ENCODER_L_DIR, ENCODER_L_LSB);                  // 初始化编码器模块与引脚 方向解码编码器模式
    encoder_dir_init(ENCODER_R, ENCODER_R_DIR, ENCODER_R_LSB);                  // 初始化编码器模块与引脚 方向解码编码器模式
}
/*****************速度测量*****************
函数：void speed_measure(void)
功能：测量实时速度，两个轮的平均速度 编码器采集值，
参数：  无
说明：  该函数可以测出速度，获取速度后无需再次复位清零，已包括了
返回值：
日期： 2021-1-12-20:30
修改日期：2023-6-25 */
void speed_measure(void)
{
    ////////////////////////右轮测速//////////Right//////
    right_speed = -encoder_get_count(ENCODER_R);
    encoder_clear_count(ENCODER_R);

    //////////////////// 左轮测速/////////Left///////////////
    left_speed = encoder_get_count(ENCODER_L);
    encoder_clear_count(ENCODER_L);

    //////////////////////带方向编码器使用下面读取方向/////////////////

    real_speed = (right_speed+left_speed)/2;        // 速度平均值
    last_speed = real_speed;

    distance +=(right_speed+left_speed)*0.1;    //测距离  化为厘米为单位

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


/******************** 电机初始化***************
函数：void init_PWM(void)
参数：  无
说明：  分母10000
      pwm_init(PWMA_CH1P_P60, 10000, 0);     //初始化PWM5  使用引脚P2.5  输出PWM频率10000HZ   占空比为百分之 pwm_duty / PWM_DUTY_MAX * 100
返回值：无
日期：2021-5-27
修改日期：2023-6-25  */
unsigned char MOTOR_MODE=0;//请勿修改删除
void init_PWM(unsigned char Motor_Set)
{
    MOTOR_MODE = Motor_Set;
    if (MOTOR_MODE==0)      //都是DRV
    {
        gpio_init(DIR_L, GPO, GPIO_HIGH, GPO_PUSH_PULL);                            // GPIO 初始化为输出 默认上拉输出高
        pwm_init(PWM_L, 17000, 0);                                                  // PWM 通道初始化频率 17KHz 占空比初始为 0

        gpio_init(DIR_R, GPO, GPIO_HIGH, GPO_PUSH_PULL);                            // GPIO 初始化为输出 默认上拉输出高
        pwm_init(PWM_R, 17000, 0);                                                  // PWM 通道初始化频率 17KHz 占空比初始为 0
    }
    else
    {
        gpio_init(DIR_L, GPO, GPIO_HIGH, GPO_PUSH_PULL);                            // GPIO 初始化为输出 默认上拉输出高
        pwm_init(PWM_L, 17000, 0);                                                  // PWM 通道初始化频率 17KHz 占空比初始为 0

        gpio_init(DIR_R, GPO, GPIO_HIGH, GPO_PUSH_PULL);                            // GPIO 初始化为输出 默认上拉输出高
        pwm_init(PWM_R, 17000, 0);                                                  // PWM 通道初始化频率 17KHz 占空比初始为 0
    }
}

/****************************电机输出**********************
函数：void go_motor (int16 left_PWM,int16 right_PWM)
参数：  int16 left_PWM,int16 right_PWM
说明：pwm_duty(PWMA_CH1P_P60, duty);
      务必将车子的电机逻辑调像这个一样，第一个参数控制左电机，第二个参数控制右电机
      传入的参数如果为正数，电机正转，负值反转！！！！！
返回值：无
日期：2021-5-27-晚23:00
修改日期：2023-6-25-晚23:00 */
#define Duty_Max  2500   //限幅最大值9500

void go_motor (int16 left_PWM,int16 right_PWM)
{
    if  (MOTOR_MODE==0)
    {
        //-------MOS驱动--------
        if (left_PWM>0)           //左轮
        {
            left_PWM = left_PWM<=Duty_Max ? left_PWM : Duty_Max;
            gpio_set_level(DIR_L, GPIO_LOW);                                         // DIR输出高电平
            pwm_set_duty(PWM_L, left_PWM);                                             // 计算占空比
        }
        else
        {
            left_PWM = left_PWM>=-Duty_Max ? (-left_PWM) : Duty_Max;
            gpio_set_level(DIR_L, GPIO_HIGH);                                         // DIR输出高电平
            pwm_set_duty(PWM_L, left_PWM);                                             // 计算占空比
        }

        if (right_PWM>0)           //右轮
        {
            right_PWM = right_PWM<=Duty_Max ? right_PWM : Duty_Max;
            gpio_set_level(DIR_R, GPIO_LOW);                                         // DIR输出高电平
            pwm_set_duty(PWM_R, right_PWM);                                             // 计算占空比
        }
        else
        {
            right_PWM = right_PWM>=-Duty_Max ? (-right_PWM) : Duty_Max;
            gpio_set_level(DIR_R, GPIO_HIGH);                                         // DIR输出高电平
            pwm_set_duty(PWM_R, right_PWM);                                             // 计算占空比
        }
    }
    else
    {
        //-------MOS驱动--------
        if (left_PWM>0)           //左轮
        {
            left_PWM = left_PWM<=Duty_Max ? left_PWM : Duty_Max;
            gpio_set_level(DIR_L, GPIO_LOW);                                         // DIR输出高电平
            pwm_set_duty(PWM_L, left_PWM);                                             // 计算占空比
        }
        else
        {
            left_PWM = left_PWM>=-Duty_Max ? (-left_PWM) : Duty_Max;
            gpio_set_level(DIR_L, GPIO_HIGH);                                         // DIR输出高电平
            pwm_set_duty(PWM_L, left_PWM);                                             // 计算占空比
        }

        if (right_PWM>0)           //右轮
        {
            right_PWM = right_PWM<=Duty_Max ? right_PWM : Duty_Max;
            gpio_set_level(DIR_R, GPIO_LOW);                                         // DIR输出高电平
            pwm_set_duty(PWM_R, right_PWM);                                             // 计算占空比
        }
        else
        {
            right_PWM = right_PWM>=-Duty_Max ? (-right_PWM) : Duty_Max;
            gpio_set_level(DIR_R, GPIO_HIGH);                                         // DIR输出高电平
            pwm_set_duty(PWM_R, right_PWM);                                             // 计算占空比
        }
}

}
