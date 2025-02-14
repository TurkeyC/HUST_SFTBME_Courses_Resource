#include <stdio.h>
#include <stdlib.h>

struct s_list {
    int data;
    struct s_list *next;
};

void create_list(struct s_list **headp, int *p);

int main(void) {
    struct s_list *head = NULL, *p;
    int s[100] = {0};
    for (int i = 0; i < 100; i++)
    {
        scanf("%d", &s[i]);
        if(!s[i]) break;
    }
    create_list(&head, s);
    p = head;
    while (p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
    while (head)
    {
        p = head;
        head = head->next;
        free(p);
    }
    return 0;
}

void create_list(struct s_list **headp, int *p) {
    struct s_list *new_node;
    if (p[0] == 0)
    {
        *headp = NULL;
        return;
    }
    else
    {
        *headp = NULL;
        while (*p)
        {
            new_node = (struct s_list *)malloc(sizeof(struct s_list));
            new_node->data = *p++;
            new_node->next = *headp;
            *headp = new_node;
        }
    }
}