#include "gyroscope.h"
#include "math.h"

extern int16 imu660ra_gyro_x, imu660ra_gyro_y, imu660ra_gyro_z;
extern int16 imu660ra_acc_x, imu660ra_acc_y, imu660ra_acc_z;
//陀螺仪内置三轴角速度计和三轴加速度计
float dt = 0.005f;     //中断周期
float Filter_Weight = 0.0035f;    //滤波权重，值越大表加速度计的可信度越高
float alpha = 0.4;
int gyroscope_time = 0;
float gyro_x = 0, gyro_y = 0, gyro_z = 0; //角速度计采集到的原始数据换算单位后
float Angle_gz = 0;
float acc_x = 0, acc_y = 0, acc_z = 0, acc_x_last = 0, acc_y_last = 0, acc_z_last = 0; //加速度计采集到的原始数据换算单位后
float Angle_pitch = 0;
float pit = 0, pittch = 0;                               // pitch:俯仰角  yaw:偏航角   融合后的角度
int16 Pitch = 0, Yaw = 0;                                 //最终角度
int16 GX = 0, GY = -6, GZ = 0;                            //角速度计零漂
int16 AX = -220, AY = 0, AZ = -160;                       // -220 -160               //加速度计零漂
int16 gyroz_filter;
void data_change()  //陀螺仪采集回的原始数据处理
{

    //一阶低通滤波
    if (imu660ra_acc_x < 32764)
        acc_x = imu660ra_acc_x / 4096.0; //计算x轴加速度
    else
        acc_x = 1 - (imu660ra_acc_x - 49152) / 4096.0;
    if (imu660ra_acc_y < 32764)
        acc_y = imu660ra_acc_y / 4096.0; //计算y轴加速度
    else
        acc_y = 1 - (imu660ra_acc_y - 49152) / 4096.0;
    if (imu660ra_acc_z < 32764)
        acc_z = imu660ra_acc_z / 4096.0; //计算z轴加速度
    else
        acc_z = (imu660ra_acc_z - 49152) / 4096.0;


    gyro_x = (float)imu660ra_gyro_x;
    gyro_y = (float)(imu660ra_gyro_y / 16.4);
    imu660ra_gyro_z /= 16.4;


}

void Angle_add()
{
    data_change();
    Angle_pitch = (float)(((atan2((acc_x), (acc_z)) * 57.296)));                     //弧度转换为角度
    pit = (1 - Filter_Weight) * (pit - (gyro_y * dt)) + Angle_pitch * Filter_Weight; //一阶互补滤波公式
    Angle_gz = Angle_gz + imu660ra_gyro_z * 0.005;                                       //角速度积分得到倾斜角度,越大积分出来的角度越大
    pittch = Complementary(Angle_pitch, gyro_y);
}
void Angle_Get()
{
    Angle_add();
    if (gyroscope_time > 600)   //上电3s后才获取俯仰角
    {
        Pitch = (int16)pit;
    }
    Yaw = (int16)Angle_gz;
}
float Complementary(float newAngle, float newRate)   //二阶互补滤波
{
    float x1=0, y1=0, x2=0, pitch_angle=0;
    float k = 0.8;
    float dt2 = 0.005f;
    x1 = (newAngle - pitch_angle) * k * k;
    y1 = dt2 * x1 + y1;
    x2 = y1 + (newAngle - pitch_angle) * 2 * k + newRate;
    pitch_angle = dt2 * x2 + pitch_angle;
    return pitch_angle;
}

void imu_open()
{
    imu660ra_get_acc();                                                         // 获取 IMU660RA 的加速度测量数值
    imu660ra_get_gyro();                                                        // 获取 IMU660RA 的角速度测量数值
    Angle_Get();
    gyroz_filter = imu660ra_gyro_z*0.5 + (1-0.5)*gyroz_filter;//Z滤波
}

