//!这道题目前做不出



#include <stdio.h>
# define M 5
# define N 3
int main(void)
{
    int a[M], b[M];
    int i, j, k;
    for (i = 0; i < M; i++)
        a[i] = i + 1; // 初始化数组a，表示圈中人的编号（从1到M）
    for (i = M, j = 0; i > 1; i--)
    {
        for (k = 1; k <= N; k++)
            if (++j > i - 1) j = 0; // 找到第N个人的位置
        b[M - i] =j?(a[j]):(a[j] = a[i-1]); // 将第N个人存入数组b中 b[M-i] = a[j];
        
        if (j)
            for (k = --j; k < i - 1; k++)
                a[k] = a[k + 1]; // 将数组a中的元素向前移动一位，覆盖掉已经出圈的人
    }
    for (i = 0; i < M - 1; i++)
        printf("%6d", b[i]); // 输出出圈人的编号
    printf("\n%6d\n", a[0]); // 输出最后留在圈中的人的编号
    return 0;
}
