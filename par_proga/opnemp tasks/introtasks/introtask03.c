#include <omp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int THREADS_NUM = 4;

int main(int argc, char* argv[]) {

    int x;

    omp_set_num_threads(THREADS_NUM);

    #pragma omp parallel shared(x)
    {
        int rank = omp_get_thread_num();
        sleep((rank + 1));
        x += rank;
        printf("thread: %d, x: %d\n", omp_get_thread_num(), x);
    }

    return 0;    

}