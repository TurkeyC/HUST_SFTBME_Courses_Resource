#include <stdio.h>
int main() 
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) 
    {
        // 打印前面的空格
        for (int k = 0; k <= n - i - 1; k++) 
        {
            printf("  ");
        }

        int num = 1;
        for (int j = 0; j <= i; j++) 
        {
            if (j == 0) 
            {
                printf("%d   ", num);
            } 
            else 
            {
                num = num * (i - j + 1) / j; // 计算下一个数
                if (num < 10) 
                {
                    printf("%d   ", num);
                } 
                else if (num < 100) 
                {
                    printf("%d  ", num);
                } 
                else 
                {
                    printf("%d ", num);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
