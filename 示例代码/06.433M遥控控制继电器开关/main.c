//433M遥控器控制继电器开关

#include "reg52.h"

sbit swicher = P1^1;
sbit D0_ON = P1^2;
sbit D1_OFF = P1^3;



void main()
{
	//查询哪个按下
	while(1){
		 //收到遥控信号A，D0表现为低电平
		if(D0_ON == 1){ 
			//A被按下，导通继电器，给继电器IN口一个低电平
		swicher = 0;		 
		}
		if(D1_OFF == 1){  //收到信号B，D1表现为高电平
					//B被按下，不导通继电器，给继电器IN口一个高电平
			swicher = 1;
		}
		
	}
}