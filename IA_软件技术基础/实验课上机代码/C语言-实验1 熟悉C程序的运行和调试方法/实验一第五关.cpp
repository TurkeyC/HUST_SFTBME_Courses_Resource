#include<stdio.h>
int main()
{
    int count, max, t;
    long long x;
    printf("������һ��������");
    scanf("%lld", &x);
    count = max = 0;
    while(x)
    {
        t = x % 10;
        if(t == 0)
        count++;
        if(t > max)
        max= t;
        x = x/10;
    }
    printf("������%d����,���������%d\n", count, max);
    return 0;
}