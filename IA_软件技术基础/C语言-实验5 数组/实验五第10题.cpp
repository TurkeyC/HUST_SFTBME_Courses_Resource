#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * input�����������̵�����
 * @param n: ����
 * @param m: ����
 * @param chess: ����
 * @param mark: ���
 */
void input(int n, int m, int **chess, int **mark)
{
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &chess[i][j]);
            mark[i][j] = 0;
        }

    }
}

/*
 * output�����������̵����
 * @param n: ����
 * @param m: ����
 * @param chess: ����
 */
void output(int n, int m, int **chess)
{
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", chess[i][j]);
        }
        printf("\n");
    }
}

/*
 * markfunc�������ڱ������жϲ���ǳ�����������
 * @param n: ����
 * @param m: ����
 * @param chess: ����
 * @param mark: ���
 */
void markfunc(int n, int m, int **chess, int **mark)
{
    int cons, count;
    //���н����ж�
    for(int i = 0; i < n; i++)
    {
        count = 0; //���ü���
        for(int j = 0; j < m; j++)
        {
            //�жϴ�ʱ�����Ƿ���ڵ���3
            if(count >= 3)
            {
                //�ж��Ƿ�Ϊ���һ��,���ҵ�ǰֵ������ֵ���
                if(j == m-1 && chess[i][j] == cons)
                {
                    for(int k = j; k > j-count; k--)
                    {
                        mark[i][k-1] = 1; //���
                    }
                    mark[i][j]=1;
                }

                //�ж��Ƿ�ǰֵ������ֵ�����
                else if(chess[i][j] != cons)
                {
                    cons = chess[i][j]; //����ֵ����cons
                    for(int k = j; k > j-count; k--)
                    {
                        mark[i][k-1] = 1; //���
                    }
                    count = 0; //���ü���
                }
            }


            //�ж�����ڵ�һ��,��ôȡ��ֵΪ����ֵ,������Ϊ1
            if(j == 0)
            {
                cons = chess[i][j];
                count = 1;
            }
            //����,���жϸ�ֵ�Ƿ���ǰһ��ֵ���
            else
            {
                //������,������һ
                if(chess[i][j] == chess[i][j-1]) count++;
                //����,����ǰֵ��������ֵ,�����ü���Ϊ1
                else
                {
                    cons = chess[i][j];
                    count = 1;
                }
            }

            //����������򲹶�
            if(j == m-1 && chess[i][j] == cons && count == 3)
            {
                for(int k = j; k > j-count; k--)
                {
                    mark[i][k] = 1; //���
                }
                //mark[i][j]=1;
            }
        }
    }
}

/*
 * markfcon�������ڱ������жϲ���ǳ�����������
 * @param n: ����
 * @param m: ����
 * @param chess: ����
 * @param mark: ���
 */
void markfcon(int n, int m, int **chess, int **mark)
{
    int cons, count;
    //���н����ж�
    for(int i = 0; i < n; i++)
    {
        count = 0; //���ü���
        for(int j = 0; j < m; j++)
        {
            //�жϴ�ʱ�����Ƿ���ڵ���3
            if(count >= 3)
            {
                //�ж��Ƿ�Ϊ���һ��,���ҵ�ǰֵ������ֵ���
                if(j == m-1 && chess[j][i] == cons)
                {
                    for(int k = j; k > j-count; k--)
                    {
                        mark[k-1][i] = 1; //���
                    }
                    mark[j][i]=1;
                }

                //�ж��Ƿ�ǰֵ������ֵ�����
                else if(chess[j][i] != cons)
                {
                    cons = chess[j][i]; //����ֵ����cons
                    for(int k = j; k > j-count; k--)
                    {
                        mark[k-1][i] = 1; //���
                    }
                    count = 0; //���ü���
                }
            }


            //�ж�����ڵ�һ��,��ôȡ��ֵΪ����ֵ,������Ϊ1
            if(j == 0)
            {
                cons = chess[j][i];
                count = 1;
            }
            //����,���жϸ�ֵ�Ƿ���ǰһ��ֵ���
            else
            {
                //������,������һ
                if(chess[j][i] == chess[j-1][i]) count++;
                //����,����ǰֵ��������ֵ,�����ü���Ϊ1
                else
                {
                    cons = chess[j][i];
                    count = 1;
                }
            }

            //����������򲹶�
            if(j == m-1 && chess[j][i] == cons && count == 3)
            {
                for(int k = j; k > j-count; k--)
                {
                    mark[k][i] = 1; //���
                }

            }
        }
    }
}


/*
 * examine���������жϲ�����
 * @param n: ����
 * @param m: ����
 * @param chess: ����
 * @param mark: ���
 */
void examine(int n, int m, int **chess, int **mark)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(mark[i][j] == 1) chess[i][j] = 0;
        }
}



int main()
{

    int n, m; //��n��m�н��ж���

    scanf("%d %d", &n, &m); //����n��m��ȷ�����̴�С

    int **chess= (int **)malloc(n * sizeof(int *)); //����һ����άָ������ʾ���̶�̬������

    int **mark= (int **)malloc(n * sizeof(int *)); //����һ����άָ������ʾ��Ƕ�̬������

    for (int i = 0; i < n; i++) {chess[i] = (int *)malloc(m * sizeof(int));} //��̬������
    for (int i = 0; i < n; i++) {mark[i] = (int *)malloc(m * sizeof(int));}

    input(n,m,chess,mark); //����input������������

    markfunc(n,m,chess,mark);//�����б������������
    markfcon(m,n,chess,mark);//�����б������������
    examine(n,m,chess,mark);//����examine������markΪ1��chess����

    output(n,m,chess);//����output�����������

    return 0;
}