#include "direction.h"
#include "function.h"
#include "speed.h"
#include "gyroscope.h"


uint16  adc_date[6];                                                                         //储存电感采集值原始值
int16  Left_Adc=0,Right_Adc=0,Left_Xie_Adc=0,Right_Xie_Adc=0,Left_Shu_Adc=0,Right_Shu_Adc=0; //电感滤波后值
int16  left_ad_max=260,left_ad_min=0,shuleft_max=200,shuleft_min=0;

float cha,he;
float position,position_shizi,position_yuanhuan,last_position,last_position_shizi,last_position_yuanhuan; //error

uint8 shizi=0,circle1,circle2,circle3,jinhuan,chuhuanqian;
int16 duty,chuku_duty;
int16 yaw_angle,t_count;

uint8 chuku_flag=0,ruku_flag=0;

//【【【【【【【【【【【PID】】】】】】】】】】】】】】
float turn_kp=0.75;                 //（1）0.8
float turn_kd=5.5;                  //（1）5

float turn_heng=100;                //（1）120
float turn_shu=380;                //（1）380

float chasu_kp=0.0;
float chasu_kd=0.0;
float chasu=0;


//-------------------------------------------------------------------------------------------------------------------
// 函数简介     ADC初始化
// 返回参数     void ADC_Int
// 备注信息
//-------------------------------------------------------------------------------------------------------------------

void ADC_Int()
{

    adc_init(Left_ADC_Pin,ADC_8BIT);//初始化ADC功能
    adc_init(Right_ADC_Pin,ADC_8BIT);//初始化ADC功能
    adc_init(LeftXie_ADC_Pin,ADC_8BIT);//初始化ADC功能
    adc_init(RightXie_ADC_Pin,ADC_8BIT);//初始化ADC功能
    adc_init(LeftShu_ADC_Pin,ADC_8BIT);//初始化ADC功能
    adc_init(RightShu_ADC_Pin,ADC_8BIT);//初始化ADC功能

}


//-------------------------------------------------------------------------------------------------------------------
// 函数简介     电感循迹处理
// 返回参数     void AD_Date_Fitier
// 备注信息
//-------------------------------------------------------------------------------------------------------------------

#define FILTER_N 10 //滤波深度
void AD_Date_Fitier()
{
    uint8 i;
    int16 filter_buf_L[FILTER_N];       //左横电感储存数组
    int16 filter_buf_LS[FILTER_N];      //左竖电感储存数组
    int16 filter_buf_LC[FILTER_N];      //左斜电感储存数组
    int16 filter_buf_R[FILTER_N];       //右横电感储存数组
    int16 filter_buf_RS[FILTER_N];      //右竖电感储存数组
    int16 filter_buf_RC[FILTER_N];      //右斜电感储存数组


    //--------滑动滤波--------------
    for(i = 0; i <FILTER_N; i++)//采值
    {
        filter_buf_L[i]  =   adc_convert (Left_ADC_Pin);   //左横
        filter_buf_LS[i]  =   adc_convert  (LeftShu_ADC_Pin);   //左竖
        filter_buf_LC[i] =   adc_convert  (LeftXie_ADC_Pin); //左斜

        filter_buf_RC[i] =  adc_convert  (RightXie_ADC_Pin);    //右斜
        filter_buf_RS[i]  =   adc_convert  (RightShu_ADC_Pin);   //右竖
        filter_buf_R[i]  =  adc_convert  (Right_ADC_Pin);   //右横
    }
    //--------冒泡排序去极值求平均---------
    adc_date[0] = I_Median_Average_Filter(filter_buf_L);//左      3600
    adc_date[1] = I_Median_Average_Filter(filter_buf_R);//右      3600
    adc_date[2] = I_Median_Average_Filter(filter_buf_LC);//左斜  3000
    adc_date[3] = I_Median_Average_Filter(filter_buf_RC);//右斜
    adc_date[4] = I_Median_Average_Filter(filter_buf_LS);//左竖
    adc_date[5] = I_Median_Average_Filter(filter_buf_RS);//右竖



    Left_Adc = adc_date[0];//左电感最终值
    Right_Adc = adc_date[1];//右电感最终值
    Left_Xie_Adc = adc_date[2];//左斜电感最终值
    Right_Xie_Adc = adc_date[3];//右斜电感最终值
    Left_Shu_Adc = adc_date[4];//中间电感最终值
    Right_Shu_Adc = adc_date[5];//右斜电感最终值

    if(Left_Adc> left_ad_max) Left_Adc=left_ad_max;
    if(Right_Adc> left_ad_max) Right_Adc=left_ad_max;
    if(Right_Shu_Adc> shuleft_max) Right_Shu_Adc=shuleft_max;
    if(Left_Shu_Adc> shuleft_max) Left_Shu_Adc=shuleft_max;
    if(Right_Xie_Adc> shuleft_max) Right_Xie_Adc=shuleft_max;
    if(Left_Xie_Adc> shuleft_max) Left_Xie_Adc=shuleft_max;

    Left_Adc=200*(Left_Adc - left_ad_min)/(left_ad_max-left_ad_min);
    Right_Adc=200*(Right_Adc - left_ad_min)/(left_ad_max-left_ad_min);
    Right_Shu_Adc=100*(Right_Shu_Adc - shuleft_min)/(shuleft_max-shuleft_min);
    Left_Shu_Adc=100*(Left_Shu_Adc - shuleft_min)/(shuleft_max-shuleft_min);
    Right_Xie_Adc=100*(Right_Xie_Adc - shuleft_min)/(shuleft_max-shuleft_min);
    Left_Xie_Adc=100*(Left_Xie_Adc - shuleft_min)/(shuleft_max-shuleft_min);

    if(Right_Shu_Adc<=5) Right_Shu_Adc=0;
    else Right_Shu_Adc=Right_Shu_Adc-2;
    if(Left_Shu_Adc<=5) Left_Shu_Adc=0;
    else Left_Shu_Adc=Left_Shu_Adc-2;
    if(Right_Xie_Adc<=5) Right_Xie_Adc=0;
    else Right_Xie_Adc=Right_Xie_Adc-2;
    if(Left_Xie_Adc<=5) Left_Xie_Adc=0;
    else Left_Xie_Adc=Left_Xie_Adc-2;

    cha = Left_Adc - Right_Adc;
    he = Left_Adc + Right_Adc;

    if(he>30)
    {
        if(Left_Shu_Adc>=Right_Shu_Adc)
            position =(turn_heng* (Left_Adc -Right_Adc)+turn_shu*(Left_Shu_Adc-Right_Shu_Adc))/((Left_Adc + Right_Adc+1)+0.5*(Left_Shu_Adc -Right_Shu_Adc));
        else
            position =(turn_heng* (Left_Adc -Right_Adc)+turn_shu*(Left_Shu_Adc-Right_Shu_Adc))/((Left_Adc + Right_Adc+1)+0.5*(Right_Shu_Adc -Left_Shu_Adc));

//        position_shizi = (100* (Left_Adc -Right_Adc)+300*(Left_Shu_Adc-Right_Shu_Adc))/((Left_Adc + Right_Adc+1)+0.5*(Right_Shu_Adc -Left_Shu_Adc));

        position_shizi = (cha*150)/(he+1);   //（1） 150

        if(Left_Shu_Adc>=Right_Shu_Adc)
            position_yuanhuan =(50* (Left_Adc -Right_Adc)+900*(Left_Shu_Adc-Right_Shu_Adc))/((Left_Adc + Right_Adc+1)+0.5*(Left_Shu_Adc - Right_Shu_Adc));
        else   //（1）800
            position_yuanhuan =(50* (Left_Adc - Right_Adc)+900*(Left_Shu_Adc-Right_Shu_Adc))/((Left_Adc + Right_Adc+1)+0.5*(Right_Shu_Adc -Left_Shu_Adc));
    }
//    else lose_flag=1;

    if(Left_Shu_Adc>70&&Right_Shu_Adc>70&&Left_Adc<120&&Right_Adc<120&&circle1==0&&circle2==0&&circle3==0&&jinhuan==0&&shizi==0)
    {
        shizi=1;
        cnt=0;
        cnt_star=1;
        cnt_dir=1;
    }

    if(cnt>8000&&shizi==1)
    {
        shizi=0;
        cnt=0;
        cnt_star=0;
    }



    if(Left_Adc>150&&Right_Adc>150&&shizi==0&&circle2==0&&circle3==0&&chuhuanqian==0)    //进环前
    {
        circle1=1;
        cnt=0;
        cnt_star=1;
        cnt_dir=1;
    }

    if(cnt>0&&circle1==1&&circle2==0&&circle3==0&&shizi==0)    //进环
    {
        circle1=0;
        circle2=1;
        yaw_angle = Yaw;
        cnt=0;
        cnt_star=0;
    }

    if(abs(Yaw - yaw_angle) > 35&&circle1==0&&circle2==1&&circle3==0&&shizi==0)    //进环完成，圆环循迹
    {
        circle2=0;
        circle3=1;
        cnt=0;
        cnt_star=0;
    }

    if(abs(Yaw - yaw_angle) > 270&&circle1==0&&circle2==0&&circle3==1&&shizi==0)    //出环
    {
        circle3=0;
        chuhuanqian=1;
        cnt=0;
        cnt_star=1;
        cnt_dir=1;
    }

    if(chuhuanqian==1&&cnt>7000)    //出环
    {
        chuhuanqian=0;
        cnt=0;
        cnt_star=0;
    }


    if(shizi==0&&circle1==0&&circle2==0&&circle3==0&&jinhuan==0)         //直道
    {
        duty=turn_kp*position+turn_kd*(position-last_position);
        Steering_Control_Out(duty);
     }
    else if(shizi==1&&circle2==0)                                       //十字圆环
    {
        duty=turn_kp*position_shizi+turn_kd*(position_shizi-last_position_shizi);
        Steering_Control_Out(duty);
    }
    else if(circle1==1&&circle2==0&&circle3==0&&shizi==0&&jinhuan==0&&chuhuanqian==0)       //进圆环前
    {
//        duty=turn_kp*position+turn_kd*(position-last_position);
//        Steering_Control_Out(duty);
        duty=turn_kp*position_yuanhuan+turn_kd*(position_yuanhuan-last_position_yuanhuan);
        duty=0.6*turn_kp*position+turn_kd*(position-last_position);
        duty=turn_kp*position_yuanhuan+turn_kd*(position_yuanhuan-last_position_yuanhuan);
        Steering_Control_Out(duty);

    }
    else if(circle2==1&&circle3==0&&shizi==0&&chuhuanqian==0)
    {
        duty=turn_kp*position_yuanhuan+turn_kd*(position_yuanhuan-last_position_yuanhuan);
        duty=0.6*turn_kp*position+turn_kd*(position-last_position);
        duty=turn_kp*position_yuanhuan+turn_kd*(position_yuanhuan-last_position_yuanhuan);
        Steering_Control_Out(duty);

    }
    else if(circle2==0&&circle3==1&&shizi==0&&chuhuanqian==0)
    {
        duty=turn_kp*position+turn_kd*(position-last_position);
        Steering_Control_Out(duty);
    }
    else if(circle3==0&&shizi==0&&chuhuanqian==1)
    {
        duty=turn_kp*position_shizi+turn_kd*(position_shizi-last_position_shizi);
        Steering_Control_Out(duty);

    }


    if(position>10)
        chasu=0.01*chasu_kp*(position)+0.01*chasu_kd*(position-position);
    else
        chasu=0;

    last_position=position;
    last_position_shizi=position_shizi;
    last_position_yuanhuan=position_yuanhuan;
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     电感循迹总处理
// 返回参数     void Electromagnetism_Control
// 备注信息
//-------------------------------------------------------------------------------------------------------------------

void Electromagnetism_Control()
{
   AD_Date_Fitier();                  //电感采集处理 冒泡排序滑动滤波 循迹处理
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     舵机初始化
// 返回参数     void init_Steer_PWM
// 备注信息
//-------------------------------------------------------------------------------------------------------------------

void init_Steer_PWM(void)
{
    pwm_init(TIM2_PWM_MAP1_CH1_A15, 50, 0);
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     舵机转向控制
// 返回参数     void Steering_Control_Out
// 备注信息
//-------------------------------------------------------------------------------------------------------------------

void Steering_Control_Out(int16 duty)
{
     duty = Steer_Duty_Midle + duty ;//在舵机中值的基础上进行偏移
     if (duty >= Steer_Duty_Max) duty = Steer_Duty_Max;
     else if(duty <= Steer_Duty_Min) duty = Steer_Duty_Min;
     pwm_set_duty(TIM2_PWM_MAP1_CH1_A15, (uint32)duty);
}


