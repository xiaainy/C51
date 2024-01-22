#include "reg52.h"

sbit led1 = P3^7;//根据原理图（电路图）设备变量led1指向P3组IO口的第7口
sbit led2 = P3^6;//根据原理图（电路图）设备变量led2指向P3组IO口的第6口

void main()
{
  led1 = 0;//根据电路图，低电平点亮led
  led2 = 0;
  while(1);
}