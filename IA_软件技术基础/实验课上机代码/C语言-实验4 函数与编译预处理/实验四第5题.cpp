//
// Created by Cao_Turkey_Su on 24-11-2.
//
#include<stdio.h>
double mulx(double x,int n);
long fac(int n);

/*
 * 计算给定序列的和
 * @param x 序列中的变量
 * @param n 序列的长度
 * @return 序列的和
 */
double sum(double x,int n)
{
    int i;
    double z=1.0;
    // 累加序列中的每一项
    for(i=0;i<n;i++)
    {
        // 计算序列中第i项的值并累加到z中
        z=z+(float)(mulx(x,i)/(double)fac(i));
    }
    return z;
}

/*
 * 计算一个数的乘方
 * 该函数通过将一个数连续乘以自身来计算乘方结果它使用了一个循环来逐步
 * 乘以给定的数x，次数由参数n指定这种方法虽然简单，但对于大指数可能效率不高
 * @param x 底数，即需要被乘的数
 * @param n 指数，即x需要被自身乘的次数
 * @return x的n次乘方的结果
 */
double mulx(double x,int n)
{
    int i;
    // 初始化结果为1.0，因为任何数的0次方都是1
    double z=1.0;
    // 循环n次，每次都将z乘以x
    for(i=0;i<n;i++)
    {
        z=z*x;
    }
    // 返回最终的乘方结果
    return z;
}

/*
 * 计算给定正整数的阶乘
 * 阶乘是指从1到n的所有正整数的乘积，用n!表示
 * 本函数通过迭代方式计算阶乘，适用于非负整数
 * 注意：当输入为0时，根据数学定义0的阶乘为1，但本函数未对此情况进行处理
 * @param n 需要计算阶乘的正整数
 * @return 计算结果为long类型，以适应较大的阶乘值
 */
long fac(int n)
{
    // 初始化乘积变量h为1，因为阶乘计算从1开始
    int i;
    long h=1;

    // 循环从1到n，逐步计算阶乘
    for(i=1;i<=n;i++)
    {
        // 累乘当前值到h中
        h=h*i;
    }

    // 返回计算得到的阶乘值
    return h;
}

/*
 * 程序入口函数，用于测试计算给定序列的和的功能
 * 函数通过输入一个变量x和序列的长度n，然后调用sum函数计算并输出结果
 * 类似的，<孙悟空>在黑风山下装作桃子的顽皮、在黄风岭沙门村内的仁义、在<小西天>面对<黄眉>时的信念坚定等等，
 * 这些都使得<孙悟空>的形象变得多元而丰富。
 */
int main()
{
    double x;
    int n;
    //scanf("%lf%d",&x,&n);
    x=1.0;n=2;
    printf("The result is %lf",sum(x,n));
    return 0;
}

#include<stdio.h>
double mulx(double x,int n);
long fac(int n);

/*
 * 计算给定序列的和
 * @param x 序列中的变量
 * @param n 序列的长度
 * @return 序列的和
 */
double sum(double x,int n)
{
    int i;
    double z=1.0;
    for(i=1;i<=n;i++)
        {
        z=z+(mulx(x,i)/fac(i));
        }
    return z;
}

/*
 * mulx函数: 计算一个数的乘方
 * @param x 底数，即需要被乘的数
 * @param n 指数，即x需要被自身乘的次数
 * @return z x的n次乘方的结果
 */
double mulx(double x,int n)
{
    double z[50]={1.0,1.0*x};
    if (z[n])
        return z[n];
    else
        {
        z[n]=z[n-1]*x;
        return z[n];
        }
}

/*
 * fac函数：计算给定正整数的阶乘
 * @param n 需要计算阶乘的正整数
 * @return h 计算结果为long类型，以适应较大的阶乘值
 * @note 使用静态数组h[50]来存储计算结果，减少计算量
 */
long fac(int n)
{
    static long h[50]={1,1};

    if (h[n])
        return h[n];
    else
        return h[n]=fac(n-1)*n;
}

int main()
{
    double x;
    int n;
    //printf("Imput x and n:");
    scanf("%lf%d",&x,&n);
    printf("The result is %lf",sum(x,n));
    return 0;
}

