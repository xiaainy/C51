//上官课程练习：01.控制IO口来点亮一个LED
#include "reg52.h"

sbit Key1 = P2^1;
sbit ledOne = P3^7;

void main()
{
  //查询法检测按键是否被按下
	while(1){
		if(Key1 == 0){//KEY1位置和GND接通,表现为低电平，值为0
			ledOne = 0;
	//灯亮，给一个P3.7口低电平（口看电路图，LED1的悬空接单片的3.7口，给0是拉低悬空的那边线成低电平）
		}
	
	}
	
}