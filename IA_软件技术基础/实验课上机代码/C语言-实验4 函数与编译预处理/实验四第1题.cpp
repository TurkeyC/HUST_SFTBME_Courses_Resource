#include <stdio.h>


/***********************************************
���þ�̬������������ʽ�洢�����������������ظ����㡣
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

//     // ��¼��ʼʱ��
//     time(&start);

//     // ִ�г������
//     // ��������滻Ϊ��Ĵ���
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


//     // ��¼����ʱ��
//     time(&end);

//     // ��������ʱ��
//     cpu_time_used = difftime(end, start);

//     // �������ʱ��
//     printf("��������ʱ��: %f ��\n", cpu_time_used);

//     return 0;
// }