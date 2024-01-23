//��ʱ��ѧϰ��ϰ��
#include "reg52.h"

sbit sg90_con = P1^1;
int jd;
int cnt = 0;

void Time0Init()
{
	//1. ���ö�ʱ��0����ģʽλ16λ��ʱ
	TMOD = 0x01;
	//2. ����ֵ����һ��0.5ms(500΢��)����
	TL0=0x33;
	TH0=0xFE;
	//3. ��ʼ��ʱ
	TR0 = 1;
	TF0 = 0;
	//4.�򿪶�ʱ��0�ж�
	ET0 = 1;
	//5.�����ж�EA
	EA = 1;
}
void Delay2000ms()		//@11.0592MHz
{
	unsigned char i, j, k;


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
	Delay300ms();//��Ӳ���ȶ�һ��
	Time0Init();//��ʼ����ʱ��
	jd = 1;			//��ʼ�Ƕ���0�ȣ���ʱ�����1�ξ���0.5ms���ߵ�ƽ
	cnt = 0;
	sg90_con = 1;//һ��ʼ�Ӹߵ�ƽ��ʼ
	
	//ÿ�������л�һ�νǶ�
	while(1){
		jd = 3;//90�� 1.5ms�ߵ�ƽ
		cnt = 0;
		Delay2000ms();
		jd = 1; //0��
		cnt = 0;
		Delay2000ms();
		
	}
}

void Time0Handler () interrupt 1//��ʱ��0���жϲ�ѯ�������1�����ֲ��6��
{

				cnt++;//ͳ�Ʊ������
				//���¸���ֵ
				TL0=0x33;
				TH0=0xFE;
	
				//����PWM��
				if(cnt < jd){ //
					sg90_con = 1;
				}else{
					sg90_con = 0;
				}
				if(cnt == 40){//����40�Σ�������20ms
					cnt = 0;//������40�α�ʾ0.5ms��������cnt��0��ʼ������һ�ε�0.5ms
					sg90_con = 1;
				}
		}

