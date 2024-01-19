#include "gyroscope.h"
#include "math.h"

extern int16 imu660ra_gyro_x, imu660ra_gyro_y, imu660ra_gyro_z;
extern int16 imu660ra_acc_x, imu660ra_acc_y, imu660ra_acc_z;
//����������������ٶȼƺ�������ٶȼ�
float dt = 0.005f;     //�ж�����
float Filter_Weight = 0.0035f;    //�˲�Ȩ�أ�ֵԽ�����ٶȼƵĿ��Ŷ�Խ��
float alpha = 0.4;
int gyroscope_time = 0;
float gyro_x = 0, gyro_y = 0, gyro_z = 0; //���ٶȼƲɼ�����ԭʼ���ݻ��㵥λ��
float Angle_gz = 0;
float acc_x = 0, acc_y = 0, acc_z = 0, acc_x_last = 0, acc_y_last = 0, acc_z_last = 0; //���ٶȼƲɼ�����ԭʼ���ݻ��㵥λ��
float Angle_pitch = 0;
float pit = 0, pittch = 0;                               // pitch:������  yaw:ƫ����   �ںϺ�ĽǶ�
int16 Pitch = 0, Yaw = 0;                                 //���սǶ�
int16 GX = 0, GY = -6, GZ = 0;                            //���ٶȼ���Ư
int16 AX = -220, AY = 0, AZ = -160;                       // -220 -160               //���ٶȼ���Ư
int16 gyroz_filter;
void data_change()  //�����ǲɼ��ص�ԭʼ���ݴ���
{

    //һ�׵�ͨ�˲�
    if (imu660ra_acc_x < 32764)
        acc_x = imu660ra_acc_x / 4096.0; //����x����ٶ�
    else
        acc_x = 1 - (imu660ra_acc_x - 49152) / 4096.0;
    if (imu660ra_acc_y < 32764)
        acc_y = imu660ra_acc_y / 4096.0; //����y����ٶ�
    else
        acc_y = 1 - (imu660ra_acc_y - 49152) / 4096.0;
    if (imu660ra_acc_z < 32764)
        acc_z = imu660ra_acc_z / 4096.0; //����z����ٶ�
    else
        acc_z = (imu660ra_acc_z - 49152) / 4096.0;


    gyro_x = (float)imu660ra_gyro_x;
    gyro_y = (float)(imu660ra_gyro_y / 16.4);
    imu660ra_gyro_z /= 16.4;


}

void Angle_add()
{
    data_change();
    Angle_pitch = (float)(((atan2((acc_x), (acc_z)) * 57.296)));                     //����ת��Ϊ�Ƕ�
    pit = (1 - Filter_Weight) * (pit - (gyro_y * dt)) + Angle_pitch * Filter_Weight; //һ�׻����˲���ʽ
    Angle_gz = Angle_gz + imu660ra_gyro_z * 0.005;                                       //���ٶȻ��ֵõ���б�Ƕ�,Խ����ֳ����ĽǶ�Խ��
    pittch = Complementary(Angle_pitch, gyro_y);
}
void Angle_Get()
{
    Angle_add();
    if (gyroscope_time > 600)   //�ϵ�3s��Ż�ȡ������
    {
        Pitch = (int16)pit;
    }
    Yaw = (int16)Angle_gz;
}
float Complementary(float newAngle, float newRate)   //���׻����˲�
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
    imu660ra_get_acc();                                                         // ��ȡ IMU660RA �ļ��ٶȲ�����ֵ
    imu660ra_get_gyro();                                                        // ��ȡ IMU660RA �Ľ��ٶȲ�����ֵ
    Angle_Get();
    gyroz_filter = imu660ra_gyro_z*0.5 + (1-0.5)*gyroz_filter;//Z�˲�
}

