/* 实验6程序完善与修改替换第（1）题源程序：字符串升序排序 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* 对指针数组s指向的size个字符串进行升序排序 */
void strsort ( char *s[ ], int size )
{
    char *temp;
    int i, j ;
    for(i=0; i<size-1; i++)
        for(j=0; j<size-i-1; j++)
            if ( strcmp(s[j], s[j+1]) > 0 )
            {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
}

int main( )
{
    int i,N;
    scanf("%d",&N);
    N++;
    char *s[N], t[50];
    for(i=0;i<N;i++)
    {
        gets(t);
        s[i] = (char *)malloc(strlen(t)+1);
        strcpy(s[i], t);
    }
    strsort(s, N);
    for(i=0; i<N; i++)  puts(s[i]);
    return 0;
}