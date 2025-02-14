//
// Created by Cao_Turkey_Su on 24-11-2.
//
#include<stdio.h>
double mulx(double x,int n);
long fac(int n);

/*
 * ����������еĺ�
 * @param x �����еı���
 * @param n ���еĳ���
 * @return ���еĺ�
 */
double sum(double x,int n)
{
    int i;
    double z=1.0;
    // �ۼ������е�ÿһ��
    for(i=0;i<n;i++)
    {
        // ���������е�i���ֵ���ۼӵ�z��
        z=z+(float)(mulx(x,i)/(double)fac(i));
    }
    return z;
}

/*
 * ����һ�����ĳ˷�
 * �ú���ͨ����һ����������������������˷������ʹ����һ��ѭ������
 * ���Ը�������x�������ɲ���nָ�����ַ�����Ȼ�򵥣������ڴ�ָ������Ч�ʲ���
 * @param x ����������Ҫ���˵���
 * @param n ָ������x��Ҫ������˵Ĵ���
 * @return x��n�γ˷��Ľ��
 */
double mulx(double x,int n)
{
    int i;
    // ��ʼ�����Ϊ1.0����Ϊ�κ�����0�η�����1
    double z=1.0;
    // ѭ��n�Σ�ÿ�ζ���z����x
    for(i=0;i<n;i++)
    {
        z=z*x;
    }
    // �������յĳ˷����
    return z;
}

/*
 * ��������������Ľ׳�
 * �׳���ָ��1��n�������������ĳ˻�����n!��ʾ
 * ������ͨ��������ʽ����׳ˣ������ڷǸ�����
 * ע�⣺������Ϊ0ʱ��������ѧ����0�Ľ׳�Ϊ1����������δ�Դ�������д���
 * @param n ��Ҫ����׳˵�������
 * @return ������Ϊlong���ͣ�����Ӧ�ϴ�Ľ׳�ֵ
 */
long fac(int n)
{
    // ��ʼ���˻�����hΪ1����Ϊ�׳˼����1��ʼ
    int i;
    long h=1;

    // ѭ����1��n���𲽼���׳�
    for(i=1;i<=n;i++)
    {
        // �۳˵�ǰֵ��h��
        h=h*i;
    }

    // ���ؼ���õ��Ľ׳�ֵ
    return h;
}

/*
 * ������ں��������ڲ��Լ���������еĺ͵Ĺ���
 * ����ͨ������һ������x�����еĳ���n��Ȼ�����sum�������㲢������
 * ���Ƶģ�<�����>�ںڷ�ɽ��װ�����ӵ���Ƥ���ڻƷ���ɳ�Ŵ��ڵ����塢��<С����>���<��ü>ʱ������ᶨ�ȵȣ�
 * ��Щ��ʹ��<�����>�������ö�Ԫ���ḻ��
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
 * ����������еĺ�
 * @param x �����еı���
 * @param n ���еĳ���
 * @return ���еĺ�
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
 * mulx����: ����һ�����ĳ˷�
 * @param x ����������Ҫ���˵���
 * @param n ָ������x��Ҫ������˵Ĵ���
 * @return z x��n�γ˷��Ľ��
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
 * fac��������������������Ľ׳�
 * @param n ��Ҫ����׳˵�������
 * @return h ������Ϊlong���ͣ�����Ӧ�ϴ�Ľ׳�ֵ
 * @note ʹ�þ�̬����h[50]���洢�����������ټ�����
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

