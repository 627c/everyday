#ifndef FUNCTION_H_
#define FUNCTION_H_

#include "zf_common_headfile.h"
#include "math.h"
//PID
//�⼸�������������±�ţ����㿴
#define KP 0
#define KI 1
#define KD 2
#define KT 3   //�����޷���
//����


typedef struct PID   //����PID�����������
{
    float SumError; //����ۼ�
    int32 LastError;    // �ϴ����
    int32 PrevError;    // Ԥ�����
    int32 LastData; // �ϴ�����
} PID;

typedef struct
{
    float P;
    float I;
    float D;
    float D_GYRO;
    float Deviation;
    float Deviation_last;
    float Deviation_last_last;
    float Output;
    float Output_last;
    float Final;
}pid;

/********PID�м��������************/
extern PID SpeedPID,L_SpeedPID,R_SpeedPID;//�ٶ�PID���棨ֻ�Ǵ�����м�����������ģ�
extern PID TurnPID;//ת��PID���棨ֻ�Ǵ�����м�����������ģ�

/********PID���������ⲿ����******/
extern float Speed_Pid[4];      // �ٶȻ�PID
extern float Turn_Pid[][4];
extern uint8 Turn_Suquence ;//ת��PIDѡ��



//*******************��������***********************

// PID������ʼ��
void PID_Parameter_Init(PID *sptr);
int16 limit(int16 x, int y);                //�޷�

/**************�޷������˲�һ��ֵ*****/
//#define  limit_ab( x,  min,  max)  ( (x<min) ? min : ( (x>max) ? max : x ))
int32 range_protect(int32 duty, int32 min, int32 max);//�޷�����
void  soft_delay(long t);                         //��ʱ

int   myabs(int dat);                        //�����ֵ


int16  filter(int16 new_value,int16 value) ;     //һ�׵�ͨ�˲�

int16  Turn_Out_Filter(float turn_out)     ;         //��Ȩƽ���˲�

float Weights_Of_Filter(float Date,float value_1,float value_2,float value_3);//��Ȩ�˲�

float Cha_BI_He(float Date_1,float Date_2,int16 X);  //�������ݵĲ�Ⱥ�

float Cha_BI_He_Sqrt(int16 date_1,int16 date_2,int16 x);//��������1.5�η�

float Cha_BI_Ji(float date_1,float date_2,int16 x);  //��������Ȼ�

float Cha_Sqrt_BI_He(int16 date_1,int16 date_2,int16 x);

int16 Cubic_Function(int16 DATE,float A,float B);   //��һ�����������η�

// PID������ʼ��
void PID_Parameter_Init(PID *sptr);


// λ��ʽ��̬PID����
int32 PlacePID_Control(PID *sprt, float *PID, int32 NowPiont, int32 SetPoint);

// λ��ʽPID����
int32 PID_Realize(PID *sptr, float *PID, int32 NowData, int32 Point);

// ����ʽPID����
int32 PID_Increase(PID *sptr, float *PID, int32 NowData, int32 Point);
//ȥ��ֵ��ƽ��
int16 I_Median_Average_Filter(int16 *DATE);

#endif /* FUNCTION_H_ */
