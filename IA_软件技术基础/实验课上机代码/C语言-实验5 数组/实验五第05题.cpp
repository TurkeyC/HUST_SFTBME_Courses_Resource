//!这道题目前做不出
//!这道题用了AI，有时间重新思考

#include <stdio.h>

int main() {
    int N, M, num, tag = 0, count = 0; 
    scanf("%d %d", &N, &M);
    num = N;
    int a[N]; 
    for (int i = 0; i < N; i++)
        a[i] = 1;

    while (num > 1)
    {
        if (a[tag])
        { 
            count++;
            if (count == M)
            { 
                a[tag] = 0;
                count = 0;
                num--;
            }
        }
        tag = (tag + 1) % N;
    }
    
    for (int i = 0; i < N; i++)
    {
        if (a[i])
        {
            printf("%d\n", i + 1);
            break;
        }
    }

    return 0;
}