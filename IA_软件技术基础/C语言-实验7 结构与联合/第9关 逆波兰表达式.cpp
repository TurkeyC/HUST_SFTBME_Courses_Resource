#include <stdio.h>
#include <stdlib.h>

typedef struct Nod {
    int val;
    struct Nod* next;
} Nod;

Nod* cr_Nod(int val) {
    Nod* n_Nod = (Nod*)malloc(sizeof(Nod));
    n_Nod->val = val;
    n_Nod->next = NULL;
    return n_Nod;
}

void pu(Nod** top, int val) {
    Nod* n_Nod = cr_Nod(val);
    n_Nod->next = *top;
    *top = n_Nod;
}

int po(Nod** top) {
    Nod* tem = *top;
    int val = tem->val;
    *top = tem->next;
    free(tem);
    return val;
}

int j_Emp(Nod* top) {
    return top == NULL;
}

int cal(char* exp) {
    Nod* sta = NULL;
    char* ch = exp;
    char tem[100];
    int buf_i = 0;

    while (*ch != '\0')
    {
        if ((*ch >= '0' && *ch <= '9') || (*ch == '-' && (*(ch + 1) >= '0' && *(ch + 1) <= '9')))
            tem[buf_i++] = *ch;
        else if (*ch == ' ' || *ch == '\n')
        {
            if (buf_i > 0)
            {
                tem[buf_i] = '\0';
                pu(&sta, atoi(tem));
                buf_i = 0;
            }
        }
        else
        {
            if (buf_i > 0)
            {
                tem[buf_i] = '\0';
                pu(&sta, atoi(tem));
                buf_i = 0;
            }
            int b = po(&sta);
            int a = po(&sta);
            switch (*ch)
            {
                case '+': pu(&sta, a + b); break;
                case '-': pu(&sta, a - b); break;
                case '*': pu(&sta, a * b); break;
                case '/': pu(&sta, a / b); break;
            }
        }
        ch++;
    }

    if (!j_Emp(sta))
    {
        int result = po(&sta);
        return result;
    }
    return 0;
}

int main() {
    char exp[100];
    fgets(exp, sizeof(exp), stdin);
    int result = cal(exp);
    printf("%d\n", result);
    return 0;
}