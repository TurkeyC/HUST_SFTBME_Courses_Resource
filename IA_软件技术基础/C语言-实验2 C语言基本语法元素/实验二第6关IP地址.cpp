#include<stdio.h>

int main(){
	unsigned long num;
	int IP0,IP1,IP2,IP3;

	//����ѭ����ֱ������Ctrl+Z��EOF����
	while (scanf("%lu",&num) != EOF)
	{
		// ��λ����ķ�ʽ��numת��ΪIP��ַ
		IP0 = num >> 24; // �� num ����24λ����ȡ���8λ��
		IP1 = (num >> 16) & 0x00ff; // �� num ����16λ��Ȼ�������� 0x00ff ���а�λ���������ȡ��17��24λ��
		IP2 = (num >> 8) & 0x0000ff; // �� num ����8λ��Ȼ�������� 0x0000ff ���а�λ���������ȡ��9��16λ��
		IP3 = num & 0x000000ff; // �� num ������ 0x000000ff ���а�λ���������ȡ���8λ

		printf("%d.%d.%d.%d\n",IP0,IP1,IP2,IP3);
	}

	return 0;  
}