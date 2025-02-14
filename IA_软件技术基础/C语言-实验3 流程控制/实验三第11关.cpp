#include <stdio.h>
#include <math.h>

int main() {
    int m;
    scanf("%d", &m);

    int prime[m + 1] = {0}; //! 想想为什么这里prime[m + 1] = {0}在头歌会报错？

    prime[0] = 1;
    prime[1] = 1;

    //利用筛法筛选素数
    for (int i = 2; i <= sqrt(m); i++) //! 想想为什么这里不能用m，而应该用sqrt(m)
    {
        if (!prime[i]) 
        {
            for (int j = i * i; j <= m; j += i) 
            {
                prime[j] = 1;
            }
        }
    }

    //遍历素数寻找孪生素数
    for (int i = 3; i <= m - 2; i++) 
    {
        if (!(prime[i] || prime[i + 2])) 
        {
            printf("(%d,%d) ", i, i + 2);
        }
    }

    printf("\n");
    return 0;
}
