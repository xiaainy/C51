//上官课程练习：01.控制IO口来点亮一个LED
#include "reg52.h"

sbit ledOne = P3^7;
sbit ledSecond = P3^6;

void main()
{
  
	ledOne = 0;
	//灯亮，给一个P3.7口低电平（口看电路图，LED1的悬空接单片的3.7口，给0是拉低悬空的那边线成低电平）
	ledSecond = 0;
	
}