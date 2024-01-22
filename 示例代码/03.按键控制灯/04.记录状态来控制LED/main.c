//�Ϲٿγ���ϰ��03.4:��¼״̬λ������LED
//��ʱ��ҵ��״̬��Ը���,��ϣ���ڿ����ж�����ȥ���������Ҫ�õ���־λ
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

	
  //��ѯ����ⰴ���Ƿ񱻰���
	while(1){
		if(Key1 == 0){ //KEY1λ�ú�GND��ͨ,����Ϊ�͵�ƽ��ֵΪ0
			//�����������֪���Ƕ���������Ϊ���������ӳ�50ms���ж�һ��
			Delay50ms();
			if(Key1 == 0){
				//��ס״̬λ��key1�����£���ס���������ط����
				ledMark = ON_STATUS;
			
			}
		}
	if(Key2 == 0){//KEY2λ�ú�GND��ͨ,����Ϊ�͵�ƽ��ֵΪ0
			ledMark = OFF_STATUS;

		}
	if(ledMark == OFF_STATUS){
		ledOne = 1;
	}else{
		ledOne = 0;
	}
 }
	
}