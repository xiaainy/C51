#include "reg52.h"

sbit led1 = P3^7;//����ԭ��ͼ����·ͼ���豸����led1ָ��P3��IO�ڵĵ�7��
sbit led2 = P3^6;//����ԭ��ͼ����·ͼ���豸����led2ָ��P3��IO�ڵĵ�6��

void main()
{
  led1 = 0;//���ݵ�·ͼ���͵�ƽ����led
  led2 = 0;
  while(1);
}