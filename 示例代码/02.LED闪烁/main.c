//�Ϲٿγ���ϰ��02.����LED��˸
#include "reg52.h"
#include <intrins.h>

sbit ledOne = P3^7;
sbit ledSecond = P3^6;
//��ʱ�����������ʱ���������ɵ�
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
	//���𣬸�һ���ߵ�ƽ
	//�ظ�ִ��
	while(1){
	  //��������һ��P3.7�͵�ƽ
		ledOne = 0;
	  //�����������ڼ䣬ά�ֵ͵�ƽ������,�ӳ�
		Delay500ms();
	  //���𣬸�һ���ߵ�ƽ
		ledOne = 1;
		//�����������ڼ䣬ά�ָߵ�ƽ�������ӳ�
		Delay500ms();
	
	
	}
  

}