#include "stdio.h"

typedef struct Node
{
    int data;
    struct Node *next;
}Node;
Node *list = NULL;

int main()
{
    Node a={3}, b={17}, c={21}, t={10};
    Node *list = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    Node *p = list;
    printf("%d ", p->data);
    p = p->next;
    printf("%d ", p->data);
    p = p->next;
    printf("%d ", p->data);
    printf("\n");
 
    return 0;
}