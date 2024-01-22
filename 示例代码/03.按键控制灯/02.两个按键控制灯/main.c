//上官课程练习：01.控制IO口来点亮一个LED
#include "reg52.h"
#include <intrins.h>

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
  //查询法检测按键是否被按下
	while(1){
		if(Key1 == 0){ //KEY1位置和GND接通,表现为低电平，值为0
			//软件消抖，不知道是抖动还是人为按按键，延迟50ms再判断一次
			Delay50ms();
			if(Key1 == 0){
	//灯亮，给一个P3.7口低电平（口看电路图，LED1的悬空接单片的3.7口，给0是拉低悬空的那边线成低电平）
			ledOne = 0;			
			}
		}
	if(Key2 == 0){//KEY2位置和GND接通,表现为低电平，值为0
			ledOne = 1;
	//灯亮，给一个P3.7口低电平（口看电路图，LED1的悬空接单片的3.7口，给0是拉低悬空的那边线成低电平）
		}
	}
	
}