#include <stdio.h>
#include <math.h>

int main() {
    int m;
    scanf("%d", &m);

    int prime[m + 1] = {0}; //! ����Ϊʲô����prime[m + 1] = {0}��ͷ��ᱨ��

    prime[0] = 1;
    prime[1] = 1;

    //����ɸ��ɸѡ����
    for (int i = 2; i <= sqrt(m); i++) //! ����Ϊʲô���ﲻ����m����Ӧ����sqrt(m)
    {
        if (!prime[i]) 
        {
            for (int j = i * i; j <= m; j += i) 
            {
                prime[j] = 1;
            }
        }
    }

    //��������Ѱ����������
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
