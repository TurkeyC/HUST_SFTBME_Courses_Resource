//!���������AI����ʱ������˼��

/*
 * �������񣺱�дһ��C����Ҫ�����ģ�黯���˼�룬����ع����ú���ʵ�֣����ṩ�˵�ѡ�ÿ�γ������н�������ͨ������0�˳�����
 * �ó���������¹��ܣ�
 * 1.����n��ѧ����������C���Կγ̵ĳɼ���
 * 2.���ɼ����Ӹߵ��͵Ĵ�����������ͬʱ������Ӧ�������ɼ���ͬ�İ���������ĸ��������ĸ��ͬ�İ��ڶ�����ĸ�����������ƣ���
 * 3.�������ѧ����������C���Կγ̵ĳɼ���
 */

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
    printf("Enter the number of students: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++)
    {
        printf("Enter name and score for student %d: ", i + 1);
        scanf("%s %d", name[i], &score[i]);
    }
}

/*
 * sort������������ѧ���ɼ������������մӸߵ��ͺ���������ĸ����
 * @param name ѧ������
 * @param score ѧ���ɼ�
 * @param n ѧ����
 * @param ts ���ڽ����ɼ�����ʱ����
 * @param tn ���ڽ�����������ʱ����
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
    printf("\nSorted list of students:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", name[i], score[i]);
    }
}


/*
 * main����������ʵ�ֲ˵�����
 * @param name ѧ������
 * @param score ѧ���ɼ�
 * @param n ѧ����
 * @param choose ѡ��
 */
int main() {
    char name[100][50];
    int score[100];
    int n;
    int choose;

    do
    {
        printf("\nMenu:\n");
        printf("1. Input students' names and scores\n");
        printf("2. Sort students by scores\n");
        printf("3. Print all students\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
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
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choose != 0);

    return 0;
}
