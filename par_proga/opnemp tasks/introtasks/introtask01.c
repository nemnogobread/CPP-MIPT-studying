#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int THREADS_NUM = 4;

int main(int argc, char* argv[]) {

    omp_set_num_threads(THREADS_NUM);

    printf("\n");
    
    #pragma omp parallel
        printf("Hello World!\n");

    printf("\n");

    return 0;    
}