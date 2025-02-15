#include<stdio.h>
#define PI 3.14159
int main(){
	int f;
	unsigned short p, k, new_int; //! unsigned short可以存储的数值范围是从 0 到 65535（如果是16位）,而short可以存储的数值范围是从-32768 到 32767 .
	double c, r, s;

	// /*任务1*/
	printf("Input Fahrenheit:");
	scanf("%d", &f);
	c=5.0/9.0*(f-32);
	printf("\n %d(F)=%.2f(C)\n\n",f,c);

	// /*任务2*/
	printf("input the radius r:");
	scanf("%lf", &r); //! double 类型对应的 scanf 格式符是 %lf, 这里的 l 代表 "long", 表示这是一个长整型或长浮点型数据.
	s = PI * r * r;
	printf("\nThe acreage is %.2f\n\n", s);

	/*任务3*/
	k=0xa1b2, p=0x8423;
	new_int = ((p&0xff00) | (k>>8));
	printf("new int = %x\n\n",new_int); //! %x它不会在输出的十六进制数前添加任何前缀，而%#x会在输出的十六进制数前添加一个 0x 前缀

	return 0;  
}