#include <stdio.h>


/***********************************************
利用静态变量以数组形式存储函数计算结果，避免重复计算。
************************************************/
unsigned long long fabonacci(int n)
{
    static unsigned long long fib[90] = {0};

    if(n==1 || n==2)
        return 1;
    else if (fib[n] != 0)
        return fib[n];
    else
        return fib[n] = fabonacci(n-1)+fabonacci(n-2);
}

int main(void)
{
    int i, k;
    unsigned long long sum = 0;
    unsigned long long fabonacci(int n);
    //printf("Input n:");
    scanf("%d", &k);
    for(i=1; i<=k; i++)
    {
        sum += fabonacci(i);
        // printf("i=%d\tthe sum is %llu\n", i, sum);
    }
    printf("%llu", sum);
    return 0;
}





// #include <stdio.h>
// #include <time.h>

// int main() {
//     time_t start, end;
//     double cpu_time_used;

//     // 记录开始时间
//     time(&start);

//     // 执行程序代码
//     // 这里可以替换为你的代码
//     int i, k;
//     unsigned long long sum = 0;
//     unsigned long long fabonacci(int n);
//     printf("Input n:");
//     scanf("%d", &k);
//     for(i=1; i<=k; i++)
//     {
//         sum += fabonacci(i);
//         printf("i=%llu\tthe sum is %llu\n", i, sum);
//     }


//     // 记录结束时间
//     time(&end);

//     // 计算运行时间
//     cpu_time_used = difftime(end, start);

//     // 输出运行时间
//     printf("程序运行时间: %f 秒\n", cpu_time_used);

//     return 0;
// }