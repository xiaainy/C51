//上官课程练习：03.4:记录状态位来控制LED
//有时候业务状态相对复杂,不希望在控制判断里面去控制外设就要用到标志位
#include "reg52.h"
#include <intrins.h>

#define ON_STATUS 1
#define OFF_STATUS 0

sbit Key1 = P2^1;
sbit Key2 = P2^0;
sbit ledOne = P3^7;

void Delay50ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 3;
	j = 26;
	k = 223;
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
	int ledMark = OFF_STATUS;
	ledOne = 1;

	
  //查询法检测按键是否被按下
	while(1){
		if(Key1 == 0){ //KEY1位置和GND接通,表现为低电平，值为0
			//软件消抖，不知道是抖动还是人为按按键，延迟50ms再判断一次
			Delay50ms();
			if(Key1 == 0){
				//记住状态位，key1被按下，记住，在其他地方点灯
				ledMark = ON_STATUS;
			
			}
		}
	if(Key2 == 0){//KEY2位置和GND接通,表现为低电平，值为0
			ledMark = OFF_STATUS;

		}
	if(ledMark == OFF_STATUS){
		ledOne = 1;
	}else{
		ledOne = 0;
	}
 }
	
}