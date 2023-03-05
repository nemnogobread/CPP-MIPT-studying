#include "stdio.h"
#include "stdlib.h"


typedef struct Node
{
    int data;
    struct Node *next;
}Node;
Node *queue = NULL;


void print_queue(Node *queue);
void push_in_queue(Node **queue, int data);


int main()
{
    int test[] = {3, 17, 21, 10};
    Node *queue = NULL;

    for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++)
    {
        push_in_queue(&queue, test[i]);
    }

    print_queue(queue);
    return 0;
}


void print_queue(Node *queue)
{
    if (queue == NULL)
        printf("No elements in queue");

    for ( Node *p = queue ; p != NULL ; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

void push_in_queue(Node **queue, int data)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->next = *queue;
    *queue = p;
}
