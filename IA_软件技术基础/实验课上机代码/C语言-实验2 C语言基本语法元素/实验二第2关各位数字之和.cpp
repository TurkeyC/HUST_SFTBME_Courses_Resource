#include<stdio.h>
//输入一个十进制正整数n，求它是几位数并计算各位数字之和
int main(){
    int n, n0, digit = 1, sum = 0;
    scanf("%d", &n);
    n0 = n;

    sum += n%10;
    while(n/10 != 0)
    {
        n = (n-n%10)/10;
        sum += n%10;
        digit++;
    }

    printf("%d是%d位数，且各位数字之和为%d。", n0, digit, sum);
    

	return 0;  
}