//上官课程练习：02.控制LED闪烁
#include "reg52.h"
#include <intrins.h>

sbit ledOne = P3^7;
sbit ledSecond = P3^6;
//延时代码是软件延时计算器生成的
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


void main()
{
	//灯灭，给一个高电平
	//重复执行
	while(1){
	  //灯亮，给一个P3.7低电平
		ledOne = 0;
	  //数数，数的期间，维持低电平，灯亮,延迟
		Delay500ms();
	  //灯灭，给一个高电平
		ledOne = 1;
		//数数，数的期间，维持高电平，灯灭，延迟
		Delay500ms();
	
	
	}
  

}