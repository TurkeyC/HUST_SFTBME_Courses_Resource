#include <stdio.h>

char u[]="UVWXYZ", v[]="xyz";
struct T {
    int x;
    char c;
    char *t;
} a[]={{11,'A',u}, {100,'B',v}}, *p=a;

void fuc1(struct T *p) { printf("%d\n", (++p)->x); }
void fuc2(struct T *p) { printf("%c\n", (p++, p->c)); }
void fuc3(struct T *p) { printf("%c\n", (*p++->t, *p->t)); }
void fuc4(struct T *p) { printf("%c\n", (*(++p)->t)); }
void fuc5(struct T *p) { printf("%c\n", (*++p->t)); }
void fuc6(struct T *p) { printf("%c\n", (++*p->t)); }

typedef void (*FuncPtr)(struct T *p);
FuncPtr funcs[] = {fuc1, fuc2, fuc3, fuc4, fuc5, fuc6};

int main() {

    int cho;
    scanf("%d", &cho);
    if (cho >= 1 && cho <= 6)
        funcs[cho-1](p);
    return 0;
}