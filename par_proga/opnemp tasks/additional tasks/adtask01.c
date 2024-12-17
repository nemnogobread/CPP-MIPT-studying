#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

long int factorial(long int x){
    if (x == 1 || x == 0)
        return 1;
    else
        return x * factorial(x-1);
}

int main(int argc, char* argv[]) {

    omp_set_num_threads(4);
    long int result = 1;
    double start_time;
    double end_time;
    printf("\n");
    
    
    start_time = omp_get_wtime();

    #pragma omp parallel for
        for (int i = 1; i < 129; i++){
            result = factorial(i);
            //printf("thread: %d, %d\n", omp_get_thread_num(), i);
        }    

    end_time = omp_get_wtime();
    printf("without balancing: %f\n", end_time - start_time);


    start_time = omp_get_wtime();

    #pragma omp parallel for schedule(static, 1)
        for (int i = 1; i < 129; i++){
            result = factorial(i);
        }

    end_time = omp_get_wtime();
    printf("static balancing with 1 chunk: %f\n", end_time - start_time);


    start_time = omp_get_wtime();

    #pragma omp parallel for schedule(static, 4)
        for (int i = 1; i < 129; i++){
            result = factorial(i);
        }

    end_time = omp_get_wtime();
    printf("static balancing with 4 chunks: %f\n", end_time - start_time);


    start_time = omp_get_wtime();

    #pragma omp parallel for schedule(dynamic, 1)
        for (int i = 1; i < 129; i++){
            result = factorial(i);
        }

    end_time = omp_get_wtime();
    printf("dynamic balancing with 1 chunk: %f\n", end_time - start_time);


    start_time = omp_get_wtime();

    #pragma omp parallel for schedule(dynamic, 4)
        for (int i = 1; i < 129; i++){
            result = factorial(i);
        }

    end_time = omp_get_wtime();
    printf("dynamic balancing with 4 chunks: %f\n", end_time - start_time);

    
    start_time = omp_get_wtime();

    #pragma omp parallel for schedule(guided)
        for (int i = 1; i < 129; i++){
            result = factorial(i);
        }

    end_time = omp_get_wtime();
    printf("guided balancing with no chunk: %f\n", end_time - start_time);


    start_time = omp_get_wtime();

    #pragma omp parallel for schedule(guided, 4)
        for (int i = 1; i < 129; i++){
            result = factorial(i);
        }

    end_time = omp_get_wtime();
    printf("guided balancing with 4 chunks: %f\n", end_time - start_time);

    printf("\n");

    return 0;
}