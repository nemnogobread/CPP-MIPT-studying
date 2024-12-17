#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define K 1601
#define M 1601


const double a = 2.0;

const double T = 1;
const double X = 1;

const double tau = T / (K - 1);
const double h   = X / (M - 1);


double phi(double x) {
    return cos(3.14159 * x);
}


double psi(double t) {
    return exp(-t);
}


double f(double x, double t) {
    return x + t;
}



int main(int argc, char* argv[]) {

    MPI_Init(&argc, &argv);

    int commsize, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &commsize);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    int Bsend_Size;

    MPI_Pack_size(2 * (K - 1), MPI_DOUBLE, MPI_COMM_WORLD, &Bsend_Size);
    Bsend_Size += MPI_BSEND_OVERHEAD * 2 * (K - 1);
    double* Bsend_Buf = (double*)malloc(Bsend_Size);

    MPI_Buffer_attach(Bsend_Buf, Bsend_Size);

    const long long diff_M  = M / commsize;
    long long start_M = diff_M * rank;
    long long end_M   = diff_M * (rank + 1);

    if(M % commsize) {
        if(rank < M % commsize) {
            start_M += rank;
            end_M   += rank + 1;
        }
        else {
            start_M += (M % commsize);
            end_M   += (M % commsize);
        }
    }

    long long total_M = end_M - start_M;

    double* prev_row = (double*)calloc(total_M, sizeof(double));
    double* curr_row = (double*)calloc(total_M, sizeof(double));

    double begin;
    if(!rank)
    {
        //printf("t x u\n");
        //begin = MPI_Wtime();
    }
    MPI_Barrier(MPI_COMM_WORLD);

    for(int m = 0; m < total_M; m++) {
        prev_row[m] = phi((start_M + m) * h);
        // printf("%.6lf %.6lf %.6lf\n", 0.0f, (start_M + m) * h, prev_row[m]);
    }

    const double c_1 =  2 * tau * h  / (a * tau + h);
    const double c_2 = (a * tau - h) / (a * tau + h);

    double* p_tmp = NULL;

    if(rank) {
        double prev_col_curr_row = 0;
        double prev_col_prev_row = phi((start_M - 1) * h);

        for(int k = 1; k < K; k++) {
            MPI_Recv(&prev_col_curr_row, 1, MPI_DOUBLE, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            curr_row[0] = c_1 * f((start_M + 0.5) * h, (k - 0.5) * tau) + prev_col_prev_row + (prev_col_curr_row - prev_row[0]) * c_2;
            // printf("%.6lf %.6lf %.6lf\n", k * tau, start_M * h, curr_row[0]);

            for(int m = 1; m < total_M; m++) {
                curr_row[m] = c_1 * f((start_M + m + 0.5) * h, (k - 0.5) * tau) + prev_row[m - 1] + (curr_row[m - 1] - prev_row[m]) * c_2;
                // printf("%.6lf %.6lf %.6lf\n", k * tau, (start_M + m) * h, curr_row[m]);
            }

            p_tmp = curr_row;
            curr_row = prev_row;
            prev_row = p_tmp;

            prev_col_prev_row = prev_col_curr_row;

            if(rank < commsize - 1) {
                MPI_Bsend(&prev_row[total_M - 1], 1, MPI_DOUBLE, rank + 1, 0, MPI_COMM_WORLD);
            }
        }
    }
    else {
        double begin = MPI_Wtime();
        for(int k = 1; k < K; k++) {
            curr_row[0] = psi(k * tau);
            // printf("%.6lf %.6lf %.6lf\n", k * tau, 0.0, curr_row[0]);

            for(int m = 1; m < total_M; m++) {
                curr_row[m] = c_1 * f((m + 0.5) * h, (k - 0.5) * tau) + prev_row[m - 1] + (curr_row[m - 1] - prev_row[m]) * c_2;
                //printf("%.6lf %.6lf %.6lf\n", k * tau, m * h, curr_row[m]);
            }

            p_tmp = curr_row;
            curr_row = prev_row;
            prev_row = p_tmp;

            if(commsize > 1) {
                MPI_Bsend(&prev_row[total_M - 1], 1, MPI_DOUBLE, rank + 1, 0, MPI_COMM_WORLD);
            }
        }
        double end = MPI_Wtime();
        double time_spent = (double) (end - begin) * 1000;
        printf("\n execution time witn %i processes is %f ms \n \n", commsize, time_spent); 
    }

    free(curr_row);
    free(prev_row); 

    free(Bsend_Buf);
    MPI_Buffer_detach(&Bsend_Buf, &Bsend_Size);


    MPI_Finalize();

    return 0;
}