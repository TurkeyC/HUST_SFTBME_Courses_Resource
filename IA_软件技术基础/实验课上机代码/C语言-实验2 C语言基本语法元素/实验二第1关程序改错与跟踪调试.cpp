#include<stdio.h>
#define PI 3.14159
int main(){
	int f;
	unsigned short p, k, new_int; //! unsigned short���Դ洢����ֵ��Χ�Ǵ� 0 �� 65535�������16λ��,��short���Դ洢����ֵ��Χ�Ǵ�-32768 �� 32767 .
	double c, r, s;

	// /*����1*/
	printf("Input Fahrenheit:");
	scanf("%d", &f);
	c=5.0/9.0*(f-32);
	printf("\n %d(F)=%.2f(C)\n\n",f,c);

	// /*����2*/
	printf("input the radius r:");
	scanf("%lf", &r); //! double ���Ͷ�Ӧ�� scanf ��ʽ���� %lf, ����� l ���� "long", ��ʾ����һ�������ͻ򳤸���������.
	s = PI * r * r;
	printf("\nThe acreage is %.2f\n\n", s);

	/*����3*/
	k=0xa1b2, p=0x8423;
	new_int = ((p&0xff00) | (k>>8));
	printf("new int = %x\n\n",new_int); //! %x�������������ʮ��������ǰ����κ�ǰ׺����%#x���������ʮ��������ǰ���һ�� 0x ǰ׺

	return 0;  
}