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
        enqueue(&queue.head, test[i]);
        if (i==0)
            queue.tail = queue.head;
        
        printf("date from first: %d \n", *queue.head);
        printf("date from tail: %d \n", *queue.tail);
        printf("\n");
    }

    print_queue(queue.head);

    printf("date from first: %d \n", *queue.head);
    printf("date from tail: %d \n", *queue.tail);

    return 0;
}


void print_queue(Node *queue_head)
{
    if (queue_head == NULL)
        printf("No elements in queue");

    for (Node *p = queue_head; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

void enqueue(Node **queue_head, int data)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->next = *queue_head;
    *queue_head = p;
}

int dequeue(Node *queue)
{
    return 0;
}
