#include <stdio.h>
#include <math.h>

// ����һ�صĴ���ĳɺ���,��������������1,��������0
int prime(int x) {
    int flag=0;
    for(int i=2, k=x-1; i<=k; i++)
    {
        if(!(x%i))
        {
            flag=1;
            break;
        }
    }
    if(!flag) return 1;
    else return 0;
}

int main() 
{
    int m, number;
    printf("������һ������3������: ");
    scanf("%d", &m);


    for (int p = 2; ; p++) 
    {
        number = ((int)pow(2, p)) - 1;
        if (number > m) 
            {break;}

        if (prime(p) && prime(number)) 
            {printf("M(%d)=%d\n", p, number);}
    }

    return 0;
}