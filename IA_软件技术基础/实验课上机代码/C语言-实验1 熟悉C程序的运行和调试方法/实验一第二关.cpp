#include<stdio.h>
int main(void)
{
    char c, num_char, num_line;
    num_char = 0;
    num_line = 0;
    printf("�����������ı�,��������Ctrl+z������\n");
    while((c = getchar()) != EOF){
        num_char++;
        if(c == '\n'){
            num_line++;
        }
    }
    printf("�ַ���:%d,", num_char);
    printf("����:%d", num_line);
    return 0;
}