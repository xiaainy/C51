//433M遥控器控制继电器开关
#include <intrins.h>
#include "reg52.h"

#define J_ON 1
#define J_OFF 0

sbit swicher = P1^0;
sbit D0_ON = P1^1;
sbit D1_OFF = P1^2;
sbit vibrate = P1^3;

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

void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delay5000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 36;
	j = 5;
	k = 211;
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
	int mark = J_OFF;
	while(1){
		//1.如果A按键被按下，设定为开启报警模式
		if(D0_ON == 1){
		//长响，表示进入警报模式
			swicher = 0;
			Delay2000ms();
			swicher = 1;
		//设定报警模式标记
		mark = J_ON;
		}
		
		//2.如果B按键被按下，设定为关闭警报模式
		if(D1_OFF == 1){
		//短响，表示进入接触报警模式
			swicher = 0;
			Delay500ms();
			swicher = 1;
		//设定报警接触模式标记
			mark = J_OFF;
		}
		
		//3.在警报模式下
		if(mark == J_ON){
		//3.1如果发生了震动，喇叭响
			if(vibrate == 0){
				//喇叭响，给继电器低电平，导通
				swicher = 0;
				Delay5000ms();
			}else{//3.2如果不发生震动，给一个高电平，喇叭不响
				swicher = 1;
			}
			
		}
	}
}