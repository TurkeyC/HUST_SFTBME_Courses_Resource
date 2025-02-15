#include<stdio.h>
int main(void)
{
    char c, num_char, num_line;
    num_char = 0;
    num_line = 0;
    printf("输入若干行文本,行首输入Ctrl+z结束。\n");
    while((c = getchar()) != EOF){
        num_char++;
        if(c == '\n'){
            num_line++;
        }
    }
    printf("字符数:%d,", num_char);
    printf("行数:%d", num_line);
    return 0;
}