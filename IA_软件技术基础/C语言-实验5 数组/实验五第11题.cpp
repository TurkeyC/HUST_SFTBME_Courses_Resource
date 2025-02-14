#include <stdio.h>

/*
 * gen函数用于生成顺转方阵
 * @param n 矩阵阶数
 */
void gen(int n)
{
    int mat[n][n];// 定义一个n阶的矩阵
    int a = 1;// 用于记录当前要填充的值
    int t = 0, b = n - 1, l = 0, r = n - 1;// 用于记录当前要填充的位置

    // 循环填充矩阵
    while (a <= n * n)
    {
        // 填充顶行
        for (int i = l; i <= r; i++)
        {
            mat[t][i] = a++;
        }
        t++;

        // 填充右列
        for (int i = t; i <= b; i++)
        {
            mat[i][r] = a++;
        }
        r--;

        // 填充底行
        if (t <= b)
        {
            for (int i = r; i >= l; i--)
            {
                mat[b][i] = a++;
            }
            b--;
        }

        // 填充左列
        if (l <= r)
        {
            for (int i = b; i >= t; i--)
            {
                mat[i][l] = a++;
            }
            l++;
        }
    }

    // 输出矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", mat[i][j]);
            if(j != n-1) printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    gen(n);
    return 0;
}