//! ���� ����ȥ��


#include <stdio.h>
#include <string.h>

/*
 * input������������ѧ�������ͳɼ��������浽������
 * @param name ѧ������
 * @param score ѧ���ɼ�
 * @param n ѧ����
 */
void input(char name[][50], int score[], int *n)
{
    scanf("%d", n);
    for (int i = 0; i < *n; i++)
        scanf("%s %d", name[i], &score[i]);
}

/*
 * sort������������ѧ���ɼ������������մӸߵ��ͺ���������ĸ����
 * @param name ѧ������
 * @param score ѧ���ɼ�
 * @param n ѧ����
 */
void sort(char name[][50], int score[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (score[j] < score[j + 1] || (score[j] == score[j + 1] && strcmp(name[j], name[j + 1]) > 0))
            {
                int ts = score[j];
                score[j] = score[j + 1];
                score[j + 1] = ts;

                char tn[50];
                strcpy(tn, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], tn);
            }
        }
    }
}

/*
 * output�����������ѧ�������ͳɼ������մӸߵ��ͺ���������ĸ����
 * @param name ѧ������
 * @param score ѧ���ɼ�
 * @param n ѧ����
 */
void output(char name[][50], int score[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%s %d\n", name[i], score[i]);
}


/*
 * scarchmethod�������ڶ��ֲ��ң���������score��Ԫ��Ϊa��Ԫ�أ��������±�
 * @param score ѧ���ɼ�
 * @param l ��߽�
 * @param r �ұ߽�
 * @param a Ҫ���ҵ�Ԫ��
 */
int scarchmethod(int score[], int l, int r, int a) {
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (score[m] == a)
            return m;
        if (score[m] < a)
            l = m+ 1;
        else
            r = m - 1;
    }
    return -1;
}


/*
 * search�������ڲ�������score��Ԫ��Ϊa��ѧ�������ͳɼ��������
 * @param name ѧ������
 * @param score ѧ���ɼ�
 * @param n ѧ����
 */
void search(char name[][50], int score[], int n) {
    int a;
    scanf("%d", &a);

    int tag = scarchmethod(score, 0, n - 1, a);
    if (tag == -1)
        printf("not found\n");
    else
    {
        while (tag >= 0 && score[tag] == a)
        {
            printf("%s %d\n", name[tag], score[tag]);
            tag--;
        }
        tag = scarchmethod(score, 0, n - 1, a) + 1;
        while (tag < n && score[tag] == a)
        {
            printf("%s %d\n", name[tag], score[tag]);
            tag++;
        }
    }
}


/*
 * main����������ʵ�ֲ˵�����
 */
int main() {
    char name[100][50];
    int score[100];
    int n;
    int choose;

    do
    {
        scanf("%d", &choose);

        switch (choose)
        {
            case 1:
                input(name, score, &n);
                break;
            case 2:
                sort(name, score, n);
                break;
            case 3:
                output(name, score, n);
                break;
            case 4:
                search(name, score, n);
                break;
            default:
                break;
        }
    } while (choose != 0);

    return 0;
}
