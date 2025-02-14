/*测试程序定义了如下结点类型
typedef struct c_node{
    char data;  struct c_node *next;
} C_NODE;
*******************************/
#include <stdlib.h>

void createLinkList(C_NODE **head,char *s)
{
    C_NODE *p,*q;
    int i;
    *head=NULL;
    for(i=0;s[i];i++)
    {
        p=(C_NODE *)malloc(sizeof(C_NODE));
        p->data=s[i];
        p->next=NULL;
        if(*head==NULL) *head=p;
        else q->next=p;
        q=p;
    }
}

void judgePalindrome(C_NODE *head)
{
    C_NODE *p,*q,*r;
    int i,j,len=0;
    for(p=head;p;p=p->next) len++;
    for(i=0,p=head;i<len/2;i++) p=p->next;
    if (len % 2 != 0) p = p->next;
    q=p->next;
    p->next=NULL;
    while (q)
    {
        r = q->next;
        q->next=p;
        p=q;
        q=r;
    }
    for (i = 0, q = head; i < len / 2; i++, q = q->next, p = p->next)
        if(q->data!=p->data) { printf("false");return;}
    printf("true");
}