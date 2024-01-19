#ifndef GYROSCOPE_H_
#define GYROSCOPE_H_

#include "zf_common_headfile.h"

extern int gyroscope_time;
extern int16 Yaw ,gyroz_filter;

void data_change() ;
void Angle_add();
void Angle_Get();
float Complementary(float newAngle, float newRate);
void imu_open();

#endif /* GYROSCOPE_H_ */
