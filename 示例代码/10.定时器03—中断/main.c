//��ʱ��ѧϰ��ϰ����ʱ������ledÿ��1���������ﲻ�ò�ѯ�ķ�ʽ�������жϵķ�ʽ
#include "reg52.h"

sbit led = P3^6;
sbit led1 = P3^7;
int cnt = 0;

void Time0Init()
{
	//1. ���ö�ʱ��0����ģʽλ16λ��ʱ
	TMOD = 0x01;
	//2. ����ֵ����һ��10ms����
	TL0=0x00;
	TH0=0xDC;
	//3. ��ʼ��ʱ
	TR0 = 1;
	TF0 = 0;
	//4.�򿪶�ʱ��0�ж�
	ET0 = 1;
	//5.�����ж�EA
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

void Time0Handler () interrupt 1//��ʱ��0���жϲ�ѯ�������1�����ֲ��6��
{

				cnt++;//ͳ�Ʊ������
				//���¸���ֵ
				TL0=0x00;
				TH0=0xDC;
				if(cnt == 100){//����100�Σ�������1��
					cnt = 0;//������100�α�ʾ1s��������cnt��0��ʼ������һ�ε�1s
					led = !led;//ÿ����һ�뷭תһ��led��״̬
				}
		}

