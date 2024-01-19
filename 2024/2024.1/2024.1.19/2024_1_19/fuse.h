#ifndef FUSE_H_
#define FUSE_H_
#include "zf_common_headfile.h"

extern unsigned char   int_OK;//初始化成功标志位
extern int16   Turn_PWM ;   //最终转向PWM
extern uint8 time_count_star;
//核心关键的标志位结构体定义
typedef struct
{
      unsigned char start_go;           //开始发车跑

      unsigned char T_Inmost;           //最内环控制周期
      unsigned char T_Turn ;           //转向控制周期
      unsigned char T_Speed ;            //速度控制周期
      unsigned char  STOP ;            //停车结束
        unsigned char OUT_Garage;     //出库标志位
    unsigned char Game;

}Body;
extern Body Flag;
extern uint8 lose_flag,charge_over;
/*********函数声明**************/
void Fuse_result(void)  ;



#endif /* FUSE_H_ */
