//�Ϲٿγ���ϰ��01.����IO��������һ��LED
#include "reg52.h"

sbit ledOne = P3^7;
sbit ledSecond = P3^6;

void main()
{
  
	ledOne = 0;
	//��������һ��P3.7�ڵ͵�ƽ���ڿ���·ͼ��LED1�����սӵ�Ƭ��3.7�ڣ���0���������յ��Ǳ��߳ɵ͵�ƽ��
	ledSecond = 0;
	
}