#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>
#include <time.h>

#define ISIZE 500
#define JSIZE 500

int main(int argc, char* argv[])
{
    double a[ISIZE][JSIZE];
    double local_a[ISIZE][JSIZE];
    FILE *ff;
    int i, j;
    int rank, commsize;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &commsize);

    for (i = 0; i < ISIZE; i++)
    {
        for (j = 0; j < JSIZE; j++)
        {
            a[i][j] = 10 * i + j;
        }
    }

    int rows_per_process = ISIZE / commsize;
    int start_row = rank * rows_per_process;
    int end_row = (rank + 1) * rows_per_process;
    if (rank == commsize - 1)
    {
        end_row = ISIZE;
    }

    // printf("Process %d sending data to process start row %d end_row %d\n", rank, start_row, end_row);

    clock_t start;

    if (rank == 0)
    {
        start = clock();
    }
    
    for (i = start_row; i < end_row; i++)
    {
        for (j = 0; j < JSIZE; j++)
        {
            local_a[i][j] = sin((double)(2 * a[i][j]));
        }
    }

    if (rank == 0)
    {
        for (i = start_row; i < end_row; i++){
            for (j = 0; j < JSIZE; j++){
                a[i][j] = local_a[i][j];
            }
        }

        // printf("second elems in local_a of 0 proc %f \n", local_a[0][1]);
        for (i = 1; i < commsize; i++)
        {
            int rows = ((i == commsize - 1) && (ISIZE % commsize != 0)) ? (ISIZE - rows_per_process*i) : rows_per_process;
            
            MPI_Recv(&a[i*rows_per_process], JSIZE * rows , MPI_DOUBLE, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
    }
    else
    {
        MPI_Send(local_a[start_row], (end_row - start_row) * JSIZE, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }

    if (rank == 0)
    {
        clock_t end = clock();
        double work_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken for computation: %f seconds\n", work_time);
    }

    if (rank == 0)
    {
        ff = fopen("refparallel_result.txt", "w");
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

    MPI_Finalize();
    return 0;
}