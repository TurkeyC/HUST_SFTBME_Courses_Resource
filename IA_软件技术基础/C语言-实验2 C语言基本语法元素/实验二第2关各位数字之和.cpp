#include<stdio.h>
//����һ��ʮ����������n�������Ǽ�λ���������λ����֮��
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

    printf("%d��%dλ�����Ҹ�λ����֮��Ϊ%d��", n0, digit, sum);
    

	return 0;  
}