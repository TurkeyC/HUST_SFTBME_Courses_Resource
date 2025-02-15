//
// Created by Cao_Turkey_Su on 24-11-10.
//

#ifndef GOLDBACH_H
#define GOLDBACH_H

#include<stdio.h>
/*
 * isPrime函数：用于判断是否为素数
 * @param n 待判断的数
 * @return 若为素数，返回1，否则返回0
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
//请完成goldbach函数，将大于等于4的偶数n表示成两个素数的和。
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
