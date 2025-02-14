#include <stdio.h>

int img[100][100];//�����ά����img���洢�Թ�ͼ��
int path[100][100];//�洢�Թ�·��
int r, c;//�����Թ�������������
int count = 1;
/*
 * output������������Թ�·��
 */
void output()
{
    printf("%d\n",count);
    count ++;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d", path[i][j]);
            if(j != c-1) printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

/*
 * solution���ڵݹ麯���������п��ܵ�·��
 * @param x,y ��ǰλ�õ��кź��к�
 */
void solution(int x, int y)
{
    //��������յ㣬���ǵ�ǰλ�ò����·��
    if (x == r - 1 && y == c - 1)
    {
        path[x][y] = 1;
        output();
        //���ñ��
        path[x][y] = 0;
        return;
    }

    if (x >= 0 && x < r && y >= 0 && y < c && img[x][y] == 1) //�ж��Ƿ�����ƶ���(x,y)���λ��
    {
        path[x][y] = 1;
        img[x][y] = 0; //���Ѿ����ʹ���λ�ñ��Ϊ0�������ظ�����

        solution(x, y + 1);// �����ƶ�
        solution(x + 1, y);// �����ƶ�
        solution(x, y - 1);// �����ƶ�
        solution(x - 1, y);// �����ƶ�

        path[x][y] = 0; // ȡ�����
        img[x][y] = 1; // �����Թ�
    }
}


int main() {
    scanf("%d %d", &r, &c);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &img[i][j]);
        }
    }

    // ��ʼ��·������Ϊ0
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            path[i][j] = 0;
        }
    }

    solution(0, 0);
    return 0;
}
