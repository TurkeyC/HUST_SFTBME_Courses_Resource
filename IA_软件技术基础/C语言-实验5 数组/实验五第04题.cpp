//!�����Ŀǰ������



#include <stdio.h>
# define M 5
# define N 3
int main(void)
{
    int a[M], b[M];
    int i, j, k;
    for (i = 0; i < M; i++)
        a[i] = i + 1; // ��ʼ������a����ʾȦ���˵ı�ţ���1��M��
    for (i = M, j = 0; i > 1; i--)
    {
        for (k = 1; k <= N; k++)
            if (++j > i - 1) j = 0; // �ҵ���N���˵�λ��
        b[M - i] =j?(a[j]):(a[j] = a[i-1]); // ����N���˴�������b�� b[M-i] = a[j];
        
        if (j)
            for (k = --j; k < i - 1; k++)
                a[k] = a[k + 1]; // ������a�е�Ԫ����ǰ�ƶ�һλ�����ǵ��Ѿ���Ȧ����
    }
    for (i = 0; i < M - 1; i++)
        printf("%6d", b[i]); // �����Ȧ�˵ı��
    printf("\n%6d\n", a[0]); // ����������Ȧ�е��˵ı��
    return 0;
}
