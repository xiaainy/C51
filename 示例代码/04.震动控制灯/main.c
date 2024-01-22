//震动传感器控制灯
#include <intrins.h>
#include "reg52.h"


sbit led1 = P3^7;//根据原理图（电路图）设备变量led1指向P3组IO口的第7口
sbit vibrate = P3^3;//震动传感器的DO接到了3.3口



void Delay2000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 15;
	j = 2;
	k = 235;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main()
{
	//用查询的方式判断是否发生震动
	while(1){
		 //模块说明，震动的话DO输出低电平
		if(vibrate == 0){ 
				led1 = 0;	//亮灯
			  Delay2000ms();
			led1 = 1;
		}else{
			led1 = 1;
		}
		
	}
}