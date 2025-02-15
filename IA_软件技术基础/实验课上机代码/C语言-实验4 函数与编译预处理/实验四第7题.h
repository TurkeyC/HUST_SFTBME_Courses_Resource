//
// Created by Cao_Turkey_Su on 24-11-10.
//

#ifndef GOLDBACH_H
#define GOLDBACH_H


#include<stdio.h>
void isPerfect(int n)
//请完成isPerfect函数，判断整数n是否为完全数
{
    /**********   Begin   **********/
    int f[30]={0};
    int t=0,sum=0;
    for(int i=1;i<=n/2;i++)
    {
        if(n%i==0)
        {
            if(!f[t])
            {
                f[t]=i;
                t++;
            }
        }
    }
    for(int i=0;i<t;i++)
        sum = sum+f[i];

    if(sum==n)
    {
        printf("%d=1",n);

        for(int i=1;i<t;i++)
            printf("+%d",f[i]);
    }

    else
        printf("%d is not a perfect number",n);

    /**********    End    **********/
}


#endif //GOLDBACH_H
