#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ISIZE 1000
#define JSIZE 1000

int main(int argc, char **argv)
{
    double a[ISIZE][JSIZE];
    int i, j;
    FILE *ff;

    clock_t start = clock();

    for (i = 0; i < ISIZE; i++)
    {
        for (j = 0; j < JSIZE; j++)
        {
            a[i][j] = 10 * i + j;
        }
    }
    
    for (i = 8; i < ISIZE; i++)
    {
        for (j = 0; j < JSIZE - 3; j++)
        {
            a[i][j] = sin(4 * a[i-8][j+3]);
        }
    }

    clock_t end = clock();
    double work_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for computation: %f seconds\n", work_time);

    ff = fopen("2dserial_result.txt", "w");
    
    for (i = 0; i < ISIZE; i++)
    {
        for (j = 0; j < JSIZE; j++)
        {
            fprintf(ff, "%f ", a[i][j]);
        }
        fprintf(ff, "\n");
    }
    fclose(ff);
}