#include "stdio.h"
#include "stdlib.h"
#include "inttypes.h"

typedef struct Queue
{
    int *data;
    int head;
    int tail;
    int count;
    int max;
}Queue;

Queue *init(size_t size);
void enqueue(Queue *q, int a);
int dequeue(Queue *q);
void print_queue(Queue *q);

int main()
{
    int test[] = {1, 2, 3, 4, 5, 6};  
    uint8_t size;
    printf("Please, enter max size of queue: ");
    scanf("%d", &size);
    Queue *q = init(size);

    for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++)
    {
        enqueue(q, test[i]);
        print_queue(q);
    }
    printf("\n");
    
    for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++)
    {
        int temp = dequeue(q);
        if (temp > -1)
            printf("poped element: %d\n", temp);
        print_queue(q);
        printf("\n");
    }
}

Queue *init(size_t size)
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)calloc(size, sizeof(int));
    q->head = q->tail = q->count = 0;
    q->max = size;
    return q;
}

void print_queue(Queue *q)
{
    if (q->count == 0)
        printf("No elements in queue");

    for (int i = 0; i < q->count; i++)
    {
        printf("%d ", q->data[(q->head + i) % (q->max)]);
    }
    printf("\n");
}

void enqueue(Queue *q, int a)
{
    if (q->count == q->max)
    {
        fprintf(stderr, "Not enough space in queue\n");
        return;
    }
    if (q->count == 0)
    {
        q->data[q->tail] = a;
        q->count++;
        return;
    }
    q->tail = (q->tail + 1) % q->max;
    q->data[q->tail] = a;
    q->count++;
}

int dequeue(Queue *q)
{
    if (q->count == 0)
    {
        printf("No elements in queue");
        return -1;
    }
    int res = q->data[q->head];
    q->head = (q->head + 1) % q->max;
    q->count--;
    return res;
}

