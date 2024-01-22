//定时器学习练习，定时器控制led每隔1秒亮灭，这里不用查询的方式，改用中断的方式
#include "reg52.h"

sbit led = P3^6;
sbit led1 = P3^7;
int cnt = 0;

void Time0Init()
{
	//1. 配置定时器0工作模式位16位计时
	TMOD = 0x01;
	//2. 给初值，定一个10ms出来
	TL0=0x00;
	TH0=0xDC;
	//3. 开始计时
	TR0 = 1;
	TF0 = 0;
	//4.打开定时器0中断
	ET0 = 1;
	//5.打开总中断EA
	EA = 1;
}

void Delay300ms()		//@11.0592MHz
{
	unsigned char i, j, k;


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
	led = 1;
	Time0Init();
	while(1){
		led1 = 0;
		Delay300ms();
		led1 = 1;
		Delay300ms();
		
	}
}

void Time0Handler () interrupt 1//定时器0的中断查询的序号是1，见手册第6章
{

				cnt++;//统计爆表次数
				//重新给初值
				TL0=0x00;
				TH0=0xDC;
				if(cnt == 100){//爆表100次，经过了1秒
					cnt = 0;//当爆表100次表示1s，重新让cnt从0开始计算下一次的1s
					led = !led;//每经过一秒翻转一下led的状态
				}
		}

