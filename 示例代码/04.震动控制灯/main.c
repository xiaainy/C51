//�𶯴��������Ƶ�
#include <intrins.h>
#include "reg52.h"


sbit led1 = P3^7;//����ԭ��ͼ����·ͼ���豸����led1ָ��P3��IO�ڵĵ�7��
sbit vibrate = P3^3;//�𶯴�������DO�ӵ���3.3��



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

void main()
{
	//�ò�ѯ�ķ�ʽ�ж��Ƿ�����
	while(1){
		 //ģ��˵�����𶯵Ļ�DO����͵�ƽ
		if(vibrate == 0){ 
				led1 = 0;	//����
			  Delay2000ms();
			led1 = 1;
		}else{
			led1 = 1;
		}
		
	}
}