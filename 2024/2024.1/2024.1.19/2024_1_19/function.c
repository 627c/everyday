#include "function.h"
#include "gyroscope.h"
/**********ֱ��PID����******/


/********�ٶ�PID����********/
PID SpeedPID;//�ٶ�PID���棨ֻ�Ǵ�����м�����������ģ�
PID L_SpeedPID;//�ٶ�PID���棨ֻ�Ǵ�����м�����������ģ�
PID R_SpeedPID;//�ٶ�PID���棨ֻ�Ǵ�����м�����������ģ�

float Speed_Pid[4]  = {5,0.001,0,400};      // �ٶȻ�PID ����
/*******ת��PID************/
PID DirectVelPID;//ת���ڻ�PID���棨ֻ�Ǵ�����м�����������ģ�
float DirectVel_Pid[4]  = {0.006,0, 0.01, 100}; // ת���ڻ�PID λ��   0.017   0.02
PID TurnPID;//ת��PID���棨ֻ�Ǵ�����м�����������ģ�
float Turn_Pid[][4]  = {  {0.8,0.2,0,200},       // ���һ��Ϊ�����޷�
                          {100,1,0,150},         //���ת�� {8,1,0,150},
                          {0.7,2,0,150},       //Բ����PID
                          {40,5.3,0.1,100},        //�ٶ���΢��  40,5.3,0,100
                        };

uint8 Turn_Suquence = 0;//ת��PIDѡ��


// PID������ʼ��
void PID_Parameter_Init(PID *sptr)
{
    sptr->SumError  = 0;
    sptr->LastError = 0;    //Error[-1]
    sptr->PrevError = 0;    //Error[-2]
    sptr->LastData  = 0;
}


// ********************λ��ʽ��̬PID����************************************
/*
������int32 PlacePID_Control(PID *sprt, float *PID, int32 NowPiont, int32 SetPoint)
���ܣ�λ��ʽ��̬PID����
������
PID *sprt��      �ṹ��ָ��
float *PID��     PID����  ��ͨ�����鶨��PIDֵ��
int32 NowPiont�� ��ǰֵ  ����ʹ�ýṹ�嶨�������
int32 SetPoint�� �趨Ŀ��ֵ   ת��������趨ֵΪ0��

˵����  �ú����ο��������򡣶�̬����һ������ת�����
����ֵ�� int32 Realize
eg��Radius = PlacePID_Control(&Turn_PID, Turn[Fres], Difference, 0);// ��̬PID����ת��
���ڣ� 2��1��
���ߣ�  �Ǹ�����     */
// λ��ʽ��̬PID����
int32 PlacePID_Control(PID *sprt, float *PID, int32 NowPiont, int32 SetPoint)
{
    //����Ϊ�Ĵ���������ֻ���������ͺ��ַ��ͱ�������������ٶ�
    int32 iError,   //��ǰ���
          Actual;   //���ó���ʵ�����ֵ
    float Kp;       //��̬P
    iError = SetPoint - NowPiont;   //���㵱ǰ���
    sprt->SumError += iError*0.01;
    if (sprt->SumError >= PID[KT])
    {
        sprt->SumError = PID[KT];
    }
    else if (sprt->SumError <=-PID[KT])
    {
        sprt->SumError = -PID[KT];
    }

    Kp = 1.414 * (iError*iError)/PID[KP] + PID[KI]; //Pֵ���ֵ�ɶ��κ�����ϵ���˴�P��I����PID���������Ƕ�̬PID������Ҫע�⣡����

    Actual = Kp * iError
           - PID[KD] * (gyroz_filter);//ֻ��PD
    sprt->LastError = iError;       //�����ϴ����


    return Actual;
}

//************************* λ��ʽPID����*****���ٶ�PID��*********************
/*
������int32 PID_Realize(PID *sptr, float *PID, int32 NowData, int32 Point)
���ܣ�λ��ʽPID����
������
PID *sprt��      �ṹ��ָ��
float *PID��     PID����  ��ͨ�����鶨��PIDֵ��
int32 NowData  ��ǰֵ  ����ʹ�ýṹ�嶨�������
int32 Point    �趨Ŀ��ֵ  ����ʹ�ýṹ�嶨�������

˵����  �ú����ο���������
����ֵ�� int32 Realize
eg��Tar_Ang_Vel.Y = PID_Realize(&Angle_PID, Angle, (int32)(Attitude_Angle.Y*100), (int32)Target_Angle.Y);    // ���Ϊ�Ŵ�10����Ŀ����ٶ�
���ڣ� 2��1��
���ߣ� �Ǹ�����     */
  ////////////
int32 PID_Realize(PID *sptr, float *PID, int32 NowData, int32 Point)
{
    //��ǰ������Ϊ�Ĵ���������ֻ���������ͺ��ַ��ͱ�������������ٶ�
    int32 iError;   // ��ǰ���
    float    Realize;   // ���ó���ʵ������

    iError = Point - NowData;   // ���㵱ǰ���      �趨����ǰ
    sptr->SumError += PID[KI] * iError; // ������
    sptr->SumError = limit(sptr->SumError, PID[KT]);//�����޷�

    Realize = PID[KP] * iError
            + sptr->SumError
            + PID[KD] * (iError - sptr->LastError);     //P  I   D  ���
    sptr->PrevError = sptr->LastError;  // ����ǰ�����
    sptr->LastError = iError;           // �����ϴ����
    sptr->LastData  = NowData;          // �����ϴ�����    û�� */

    return Realize; // ����ʵ��ֵ
}

//-------------------------------------------------------------------------//
//************************����ʽPID�������*********************
/*
������int32 PID_Increase(PID *sptr, float *PID, int32 NowData, int32 Point)
���ܣ� ����ʽPID�������
������
PID *sprt��      �ṹ��ָ��
float *PID��     PID����  ��ͨ�����鶨��PIDֵ��
int32 NowData    ��ǰֵ  ����ʹ�ýṹ�嶨�������
int32 Point      �趨Ŀ��ֵ  ����ʹ�ýṹ�嶨�������

˵����  �ú����ο���������
����ֵ�� int32 Increase
eg��Theory_Duty += PID_Increase(&Ang_Vel_PID, Ang_Vel, (int32)(GYRO_Real.Y*10), (int32)(Tar_Ang_Vel.Y)); // ����ֱ��PWM
���ڣ� 2��1��
���ߣ� �Ǹ�����     */
int32 PID_Increase(PID *sptr, float *PID, int32 NowData, int32 Point)
{
    //��ǰ������Ϊ�Ĵ���������ֻ���������ͺ��ַ��ͱ�������������ٶ�
    int32 iError,   //��ǰ���
        Increase;   //���ó���ʵ������

    iError = Point - NowData;   // ���㵱ǰ���

    Increase =  PID[KP] * (iError - sptr->LastError)
              + PID[KI] * iError
              + PID[KD] * (iError - 2 * sptr->LastError + sptr->PrevError);

    sptr->PrevError = sptr->LastError;  // ����ǰ�����
    sptr->LastError = iError;           // �����ϴ����
    sptr->LastData  = NowData;          // �����ϴ�����

    return Increase;    // ��������
}

//*************************************************************************
/****************�޷�****************
//x���޷�����
//y���޷���Χ
//������


*/
int16 limit(int16 x, int y)
{
    if(x>y)             return y;
    else if(x<-y)       return -y;
    else                return x;
}

 /******** �޷����� *********/
int32 range_protect(int32 duty, int32 min, int32 max)//�޷�����
{
  if (duty >= max)
  {
    return max;
  }
  if (duty <= min)
  {
    return min;
  }
  else
  {
    return duty;
  }
}

/****************�����ֵ********/
int  myabs(int dat)
{
    if(dat>=0)  return dat;
    else        return -dat;
}

/***********��ʱ����************/
void soft_delay(long t)
{
    int i;
    while(t--)
   for(i=1000;i>0;i--);
}

/**********һ�׵�ͨ�˲�**********/
#define  a   0.1
/*
value �ϴ��˲����ֵ
new_value �µĲ���ֵ
out_value �������
�˲�ϵ��ԽС���˲����Խƽ�ȣ�����������Խ�͡��˲�ϵ��Խ��������Խ�ߣ������˲����Խ���ȶ�
*/
int16  filter(int16 new_value,int16 value)
{
  int16 out_value=0;
  out_value = (1-a)*new_value+a*value ;
return   out_value;
}
/******************����ƫ���˲�***********************
������ float  Turn_Out_Filter(float turn_out)
������  ��
˵����  ��
����ֵ����
���ڣ� 11��28��
����޸�ʱ�䣺2019-4-19
���ߣ�  �Ǹ�����     */
int16  Turn_Out_Filter(float turn_out)
{
  int16 Turn_Out_Filtered;
  static float Pre1_Error[4];
  Pre1_Error[3]=Pre1_Error[2];
  Pre1_Error[2]=Pre1_Error[1];
  Pre1_Error[1]=Pre1_Error[0];
  Pre1_Error[0]=turn_out;
  Turn_Out_Filtered=(int16)(Pre1_Error[0]*0.5+Pre1_Error[1]*0.3+Pre1_Error[2]*0.1+Pre1_Error[3]*0.1);
  return Turn_Out_Filtered;
}
/******************��Ȩ�˲�***********************
������ int16 Weights_Of_Filter(float Date,float value_1,float value_2,float value_3,float value_4)
������  float Date  //Ҫ�˲���ֵ   float value_1,float value_2,float value_3,float value_4//�˲���Ȩ��
˵����  ��
����ֵ����
���ڣ�2019-5-9
����޸�ʱ�䣺2019-5-9
���ߣ� ����     */
float Weights_Of_Filter(float Date,float value_1,float value_2,float value_3)
{
 float Filter_Out;
  static float Error[4];
  Error[3]=Error[2];
  Error[2]=Error[1];
  Error[1]=Error[0];
  Error[0]=Date;
 Filter_Out=(Error[0]*value_1+Error[1]*value_2+Error[2]*value_3);
  return Filter_Out;
}


/*****************��Ⱥ�***********************
������ float Cha_BI_He(float Date_1,float Date_2,float Date_3,int16 X)
������  float Date_1--��һ������  float Date_2--�ڶ������� float Date_3���������ݣ���ĸ�� int16 X--�������Ŵ�ı���
˵����  ��
����ֵ����
���ڣ�2019-5-9
����޸�ʱ�䣺2019-5-9
���ߣ�  �Ǹ�����     */
float Cha_BI_He(float Date_1,float Date_2,int16 X)
{
  int16 Cha=0;
  float He=0;
  float Resault;
  Cha =  Date_1 - Date_2;   //��
  He =   Date_1 + Date_2;   //��
  Resault = (Cha/He)*X ; //��Ⱥ�

  return   Resault;
}
/*****************��Ȼ�***********************
������ float Cha_BI_He_Sqrt(int16 date_1,int16 date_2,int16 x)
������  float date_1--��һ������  float date_2--�ڶ�������  float x-�������Ŵ�ı���
˵����  ��
����ֵ����
���ڣ�2021-5-28
����޸�ʱ�䣺2021-5-28
���ߣ� �Ǹ�����    */
float Cha_BI_He_Sqrt(int16 date_1,int16 date_2,int16 x)
{
  int16 cha=0;
  float he=0;
  float resault;
  cha = date_1 - date_2;   //��
  he =  (float) ((date_1 + date_2)*sqrt((date_1 + date_2)));   //�͵�1.5�η�
  resault = (cha/he)*x ; //��Ⱥ�

  return   resault;
}

/*****************��sqrt�Ⱥ�***********************
������ float Cha_BI_He_Sqrt(int16 date_1,int16 date_2,int16 x)
������  float date_1--��һ������  float date_2--�ڶ�������  float x-�������Ŵ�ı���
˵����  ��
����ֵ����
���ڣ�2021-5-28
����޸�ʱ�䣺2021-5-28
���ߣ� �Ǹ�����    */
float Cha_Sqrt_BI_He(int16 date_1,int16 date_2,int16 x)
{
  int16 cha=0;
  float he=0;
  float resault;
  cha = sqrt(date_1) - sqrt(date_2);   //��
  he =  (float) (date_1 + date_2);   //�͵�1.5�η�
  resault = (cha/he)*x ; //��Ⱥ�

  return   resault;
}

/*****************��Ȼ�***********************
������ int16 Cubic_Function(int16 DATE,float A,float B)
������  int16 DATE--ԭʼ����  float A--����ϵ��  float B-һ��ϵ��
˵����  ��
����ֵ����
���ڣ�2019-5-30
����޸�ʱ�䣺2019-5-30
���ߣ�  �Ǹ�����  */
 int16 Cubic_Function(int16 DATE,float A,float B)
{
  int16 Final_Date;
  Final_Date = (DATE*DATE*DATE)*A+DATE*B;
  return   Final_Date;
}

////////ȥ����ֵ��ƽ��
int16 I_Median_Average_Filter(int16 *DATE)
{
    uint8 i;
    int16 max,min;  //���弫ֵ�Լ���
    int16 sum = 0;

    max = DATE[0];
    min = DATE[0];

    for(i=0;i<sizeof(DATE);i++)
    {
        if(max<DATE[i])max = DATE[i];
        if(min>DATE[i])min = DATE[i];
        sum += DATE[i];
    }

    sum =(sum-max-min)/(sizeof(DATE)-2);    //>>3
    return sum;
}

