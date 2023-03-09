#include "stdio.h"
#include "stdlib.h"
#include "inttypes.h"

typedef struct Queue
{
    int *data;  // массив, который мы замкнём в процессе реализации
    int head;   // номер первого элемента в очереди
    int tail;   // номер последнего элемента в очереди
    int count;   // размер очереди
    int size;   // размер текущего вектора
}Queue;

Queue *init(size_t size);
void enqueue(Queue *q, int a); 
void reallocate_memory(Queue *q);                         
int dequeue(Queue *q);                                  
void print_queue(Queue *q);                             
void print_data(Queue *q);                                      

int main()
{
    int test[] = {1, 2, 3, 4, 5, 6};  
    uint8_t size = 2;                                 
    Queue *q = init(size);
    print_queue(q);
    for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++)                        
    {
        enqueue(q, test[i]);                         
        puts("queue has next structure: ");
        print_queue(q);
        puts("data has next structure: ");
        print_data(q);
        puts("");
    }
    printf("\n");

}

Queue *init(size_t size)                                
{
    Queue *q = (Queue*)malloc(sizeof(Queue));           
    q->data = (int*)calloc(size, sizeof(int));       
    q->head = q->tail = q->count = 0;
    q->size = size;
    return q;
}

void print_queue(Queue *q)
{
    if (q->count == 0)
        printf("No elements in queue");

    for (int i = 0; i < q->count; i++)
    {
        printf("%d ", q->data[i + q->head]);
    }
    printf("\n");
}

void reallocate_memory(Queue *q)
{
    int *temp = (int*)calloc((q->size)*2, sizeof(int));
    for (int i = 0; i < q->count; i++)
    {
        temp[i] = q->data[i + q->head];
    }
    free(q->data);
    q->data = temp;
    q->head = 0;
    q->tail = q->count - 1;
    q->size *= 2;
}

void enqueue(Queue *q, int a)                         
{
    if (q->count == 0)
    {
        q->data[q->tail] =  a;
        q->count++;
        return;
    }

    if (q->count == q->size)
        reallocate_memory(q);

    q->data[q->tail + 1] = a;
    q->count++;
    q->tail++;
}

int dequeue(Queue *q)                                 
{
    return 0;
}

void print_data(Queue *q)                              
{
    for (int i = 0; i < q->size; i++)
    {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}