//*以下是源代码

// #include<stdio.h>

// void strcate(char [], char []) ;
// void strdelc(char [], char);

// int main(void)
// {
//     char a[100] = "Language", b[100] = "Programming";

//     printf("%s %s\n", b, a);

//     strcate(b, a);
//     printf("%s %s\n", b, a);

//     strdelc(b, 'a');
//     printf("%s\n", b);
//     return 0;
// }

// /*strcate()函数的功能是把s[]连接到t[]后面
//  * @param s[]: 源字符串
//  * @param t[]: 目标字符串
//  * @return: void
//  */
// void strcate(char t[], char s[])
// {
//     int i = 0, j = 0;
//     while(t[i] != '\0') i++; //i++先用再加
//     while((t[i++] = s[j++]) != '\0') ;
// }

// /*strdelc()函数的功能是删除s[]中的c字符
//  * @param s[]: 源字符串
//  * @param c: 要删除的字符
//  * @return: void
//  */
// void strdelc(char s[], char c)
// {
//     int j, k;
//     for(j = k = 0; s[j] != '\0'; j++)
//         if(s[j] != c) s[k++] = s[j];
//     s[k] = '\0';// 确保字符串以结束符结束
// }


#include<stdio.h>

void strcate(char [], char []) ;
void strdelc(char [], char);

int main(void)
{
    char a[100], b[100], c;
    scanf("%s %s %c", b, a, &c);

    strcate(b, a);
    printf("%s\n", b);

    strdelc(b, c);
    printf("%s\n", b);
    return 0;
}

/* strcate()函数的功能是把s[]连接到t[]后面
 * @param s[]: 源字符串
 * @param t[]: 目标字符串
 * @return: void
 */
void strcate(char t[], char s[])
{
    int i = 0, j = 0;
    while(t[i] != '\0') i++; //i++先用再加
    while((t[i++] = s[j++]) != '\0') ;
}

/* strdelc()函数的功能是删除s[]中的c字符
 * @param s[]: 源字符串
 * @param c: 要删除的字符
 * @return: void
 */
void strdelc(char s[], char c)
{
    int j, k;
    for(j = k = 0; s[j] != '\0'; j++)
        if(s[j] != c) s[k++] = s[j];
    s[k] = '\0';// 确保字符串以结束符结束
}
