//震动传感器控制继电器开关
#include <intrins.h>
#include "reg52.h"

sbit vibrate = P3^3;//震动传感器的DO接到了3.3口
sbit swicher = P1^1;
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
			//当发生震动时候，导通继电器，给继电器一个低电平
		swicher = 0;
			Delay2000ms();
			swicher = 1;//高电平，继电器NO和COM不通
		}else{
		swicher = 1;
		}
		
	}
}