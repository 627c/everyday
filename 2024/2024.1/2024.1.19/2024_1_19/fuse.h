#ifndef FUSE_H_
#define FUSE_H_
#include "zf_common_headfile.h"

extern unsigned char   int_OK;//��ʼ���ɹ���־λ
extern int16   Turn_PWM ;   //����ת��PWM
extern uint8 time_count_star;
//���Ĺؼ��ı�־λ�ṹ�嶨��
typedef struct
{
      unsigned char start_go;           //��ʼ������

      unsigned char T_Inmost;           //���ڻ���������
      unsigned char T_Turn ;           //ת���������
      unsigned char T_Speed ;            //�ٶȿ�������
      unsigned char  STOP ;            //ͣ������
        unsigned char OUT_Garage;     //�����־λ
    unsigned char Game;

}Body;
extern Body Flag;
extern uint8 lose_flag,charge_over;
/*********��������**************/
void Fuse_result(void)  ;



#endif /* FUSE_H_ */
