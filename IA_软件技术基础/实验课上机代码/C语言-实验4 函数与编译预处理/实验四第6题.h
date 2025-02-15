//
// Created by Cao_Turkey_Su on 24-11-10.
//

#ifndef GOLDBACH_H
#define GOLDBACH_H

#include<stdio.h>
/*
 * isPrime�����������ж��Ƿ�Ϊ����
 * @param n ���жϵ���
 * @return ��Ϊ����������1�����򷵻�0
 */
int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

void goldbach(int n)
//�����goldbach�����������ڵ���4��ż��n��ʾ�����������ĺ͡�
{
    /**********   Begin   **********/
    if(n>=4 && n%2==0)
    {
        int n1, n2;
        for(n1=2; n1<=n/2; n1++)
        {
            if(isPrime(n1))
            {
                n2=n-n1;
                if(isPrime(n2))
                {
                    printf("%d=%d+%d\n", n, n1, n2);
                    return;
                }
            }
        }

    }


    /**********    End    **********/

}

#endif //GOLDBACH_H
