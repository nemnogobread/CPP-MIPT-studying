#include "stdio.h"
#include "stdlib.h"


typedef struct Node
{
    int data;
    struct Node *next;
}Node;
Node *queue = NULL;

typedef struct Queue
{
    struct Node *head;
    struct Node *tail;
}Queue;


void print_queue(Node *queue);
void enqueue(Node **queue, int data);
int dequeue(Node *queue);


int main()
{
    int test[] = {3, 17, 21, 10};
    Queue queue = {NULL, NULL}; 

    for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++)
    {
        enqueue(&queue.tail, test[i]);
        if (i==0)
            queue.head = queue.tail;
        
        printf("date from head: %d \n", *queue.head);
        printf("date from tail: %d \n", *queue.tail);
        printf("\n");
    }

    print_queue(queue.tail);

    printf("date from head: %d \n", *queue.head);
    printf("date from tail: %d \n", *queue.tail);

    return 0;
}


void print_queue(Node *queue_tail)
{
    if (queue_tail == NULL)
        printf("No elements in queue");

    for (Node *p = queue_tail; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

void enqueue(Node **queue_tail, int data)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->next = *queue_tail;
    *queue_tail = p;
}

int dequeue(Node *queue)
{
    return 0;
}
