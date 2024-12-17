#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define ISIZE 1000
#define JSIZE 1000

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <num_threads>\n", argv[0]);
        return 1;
    }

    int num_threads = atoi(argv[1]);
    if (num_threads <= 0)
    {
        fprintf(stderr, "Invalid number of threads: %d. Must be positive.\n", num_threads);
        return 1;
    }

    omp_set_num_threads(num_threads);
    //printf("Using %d threads\n", num_threads);

    FILE *ff;
    double a[ISIZE][JSIZE];
    
    for (int i = 0; i < ISIZE; i++)
    {
        for (int j = 0; j < JSIZE; j++)
        {
            a[i][j] = 10 * i + j;
        }
    }

    //printf("Start computation\n");
    double start = omp_get_wtime();

    for (int i = 0; i < ISIZE - 1; i++)
    {
#pragma omp parallel for
        for (int j = 6; j < JSIZE; j++)
        {
            a[i][j] = sin(0.2 * a[i + 1][j - 6]);
        }
    }

    double end = omp_get_wtime();
    double work_time = end - start;
    printf("Time taken for computation: %f seconds\n", work_time);

    ff = fopen("1dopenmp_result.txt", "w");
    for (int i = 0; i < ISIZE; i++)
    {
        for (int j = 0; j < JSIZE; j++)
        {
            fprintf(ff, "%f ", a[i][j]);
        }
        fprintf(ff, "\n");
    }
    fclose(ff);

    return 0;
}