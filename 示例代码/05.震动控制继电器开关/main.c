//�𶯴��������Ƽ̵�������
#include <intrins.h>
#include "reg52.h"

sbit vibrate = P3^3;//�𶯴�������DO�ӵ���3.3��
sbit swicher = P1^1;
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
			//��������ʱ�򣬵�ͨ�̵��������̵���һ���͵�ƽ
		swicher = 0;
			Delay2000ms();
			swicher = 1;//�ߵ�ƽ���̵���NO��COM��ͨ
		}else{
		swicher = 1;
		}
		
	}
}