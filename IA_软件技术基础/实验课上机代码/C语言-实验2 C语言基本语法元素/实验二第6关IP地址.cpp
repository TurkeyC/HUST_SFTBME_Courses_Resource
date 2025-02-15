#include<stdio.h>

int main(){
	unsigned long num;
	int IP0,IP1,IP2,IP3;

	//进入循环，直到输入Ctrl+Z即EOF结束
	while (scanf("%lu",&num) != EOF)
	{
		// 用位运算的方式将num转换为IP地址
		IP0 = num >> 24; // 将 num 右移24位，提取最高8位。
		IP1 = (num >> 16) & 0x00ff; // 将 num 右移16位，然后与掩码 0x00ff 进行按位与操作，提取第17到24位。
		IP2 = (num >> 8) & 0x0000ff; // 将 num 右移8位，然后与掩码 0x0000ff 进行按位与操作，提取第9到16位。
		IP3 = num & 0x000000ff; // 将 num 与掩码 0x000000ff 进行按位与操作，提取最低8位

		printf("%d.%d.%d.%d\n",IP0,IP1,IP2,IP3);
	}

	return 0;  
}