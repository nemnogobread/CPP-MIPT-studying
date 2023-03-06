#include "stdio.h"
#include "stdlib.h"

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef struct Queue
{
    struct Node *head;
    struct Node *tail;
}Queue;

void print_queue(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);

int main()
{
    int test[] = {3, 17, 21, 10};
    Queue queue = {NULL, NULL};
    
    for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++)
    {
        enqueue(&queue, test[i]);    

        print_queue(&queue);
        printf("date from head: %d \n", *queue.head);
        printf("date from tail: %d \n\n", *queue.tail);
    }

    while (queue.head != NULL)
    {
        printf("poped element: %d \n", dequeue(&queue));

        print_queue(&queue);
        if (queue.head != NULL)
        {
            printf("date from head: %d \n", *queue.head);
            printf("date from tail: %d \n\n", *queue.tail);
        }
    }

    printf("\n");
    return 0;
}

void print_queue(Queue *q)
{
    if (q->head == NULL)
        printf("No elements in queue");

    for (Node *p = q->head; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

void enqueue(Queue *q, int data)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    if (q->tail == NULL)
    {
        q->head = p;
        q->tail = p;
    }
    else
    {
        q->tail->next = p;
        q->tail = p;
    }
}

int dequeue(Queue *q)
{
    if (q->head == NULL)
    {
        printf("No elements in queue");
        return 0;
    }
    Node *temp = q->head;
    int res = q->head->data;
    q->head = q->head->next;
    free(temp);
    return res;
}
