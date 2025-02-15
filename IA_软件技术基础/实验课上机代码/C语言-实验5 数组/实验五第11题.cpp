#include <stdio.h>

/*
 * gen������������˳ת����
 * @param n �������
 */
void gen(int n)
{
    int mat[n][n];// ����һ��n�׵ľ���
    int a = 1;// ���ڼ�¼��ǰҪ����ֵ
    int t = 0, b = n - 1, l = 0, r = n - 1;// ���ڼ�¼��ǰҪ����λ��

    // ѭ��������
    while (a <= n * n)
    {
        // ��䶥��
        for (int i = l; i <= r; i++)
        {
            mat[t][i] = a++;
        }
        t++;

        // �������
        for (int i = t; i <= b; i++)
        {
            mat[i][r] = a++;
        }
        r--;

        // ������
        if (t <= b)
        {
            for (int i = r; i >= l; i--)
            {
                mat[b][i] = a++;
            }
            b--;
        }

        // �������
        if (l <= r)
        {
            for (int i = b; i >= t; i--)
            {
                mat[i][l] = a++;
            }
            l++;
        }
    }

    // �������
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