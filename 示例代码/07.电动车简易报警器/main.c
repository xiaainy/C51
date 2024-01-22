//433Mң�������Ƽ̵�������
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
		//1.���A���������£��趨Ϊ��������ģʽ
		if(D0_ON == 1){
		//���죬��ʾ���뾯��ģʽ
			swicher = 0;
			Delay2000ms();
			swicher = 1;
		//�趨����ģʽ���
		mark = J_ON;
		}
		
		//2.���B���������£��趨Ϊ�رվ���ģʽ
		if(D1_OFF == 1){
		//���죬��ʾ����Ӵ�����ģʽ
			swicher = 0;
			Delay500ms();
			swicher = 1;
		//�趨�����Ӵ�ģʽ���
			mark = J_OFF;
		}
		
		//3.�ھ���ģʽ��
		if(mark == J_ON){
		//3.1����������𶯣�������
			if(vibrate == 0){
				//�����죬���̵����͵�ƽ����ͨ
				swicher = 0;
				Delay5000ms();
			}else{//3.2����������𶯣���һ���ߵ�ƽ�����Ȳ���
				swicher = 1;
			}
			
		}
	}
}