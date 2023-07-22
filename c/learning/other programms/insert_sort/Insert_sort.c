#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define ALLOCATE_SIZE 1000

int input_array(int N, int arr[])
{
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void print_array(int N, int arr[])
{
    for (int i = 0; i < N; i++)
        printf("%3d ", arr[i]);
    printf("\n");
    return;
}

void insert_sort(int N, int arr[])
{
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j-1])
            {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
            else
                break;
        }
    }
    return;
}

int main(int argc, char* argv[])
{
    int *arr;
    int N;
    scanf("%d", &N);
    arr = (int*)malloc(N*sizeof(int));
    input_array(N, arr);
    print_array(N, arr);
    insert_sort(N, arr);
    print_array(N, arr);
    
    return 0;
}
