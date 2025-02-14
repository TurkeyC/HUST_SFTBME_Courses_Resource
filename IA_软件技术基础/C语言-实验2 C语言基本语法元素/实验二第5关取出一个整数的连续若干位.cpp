#include<stdio.h>
int main(){
	unsigned short x, m, n;
	//x以十六进制输入，m,n以十进制输入
	scanf("%hx %hu %hu", &x, &m, &n);
	//检查m,n的范围，0<=m<=15,1<=n<=16-m
	if (m <= 15 && m >= 0 && n <= 16 - m && n >= 1)
	//取出x从第m位开始向左的n位(注：m从右至左编号为0~15)，并使其向左端(第15位靠齐)，并以十六进制输出
	//printf("%hx", x << (16 - n - m));
	printf("%hx", x >> (m) << (16 - n));

	return 0;  
}

//? 为什么最后一个测试集是错的啊啊啊？