//�Ϲٿγ���ϰ��01.����IO��������һ��LED
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
  //��ѯ����ⰴ���Ƿ񱻰���
	while(1){
		if(Key1 == 0){ //KEY1λ�ú�GND��ͨ,����Ϊ�͵�ƽ��ֵΪ0
			//�����������֪���Ƕ���������Ϊ���������ӳ�50ms���ж�һ��
			Delay50ms();
			if(Key1 == 0){
	//��������һ��P3.7�ڵ͵�ƽ���ڿ���·ͼ��LED1�����սӵ�Ƭ��3.7�ڣ���0���������յ��Ǳ��߳ɵ͵�ƽ��
			ledOne = 0;			
			}
		}
	if(Key2 == 0){//KEY2λ�ú�GND��ͨ,����Ϊ�͵�ƽ��ֵΪ0
			ledOne = 1;
	//��������һ��P3.7�ڵ͵�ƽ���ڿ���·ͼ��LED1�����սӵ�Ƭ��3.7�ڣ���0���������յ��Ǳ��߳ɵ͵�ƽ��
		}
	}
	
}