#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int THREADS_NUM = 4;

double Sum(long long start, long long end) {
    double partSum = 0.0;

    for(long long i = start; i < end; i++) {
        partSum += 1.0 / (double)i;
    }

    return partSum;
}

int main(int argc, char* argv[]) {

    if (argc != 2)
    {
        printf("wrong input");
        return 1;
    }
    
    int N = atoi(argv[1]);
    double result = 0.0;

    omp_set_num_threads(THREADS_NUM);

    #pragma omp parallel
    {
        const long long diff  = N / THREADS_NUM;
        int rank = omp_get_thread_num();

        long long start = 1 + diff * rank;
        long long end   = 1 + diff * (rank + 1);

        if(N % THREADS_NUM) {
            if(rank < N % THREADS_NUM) {
            start += rank;
            end += rank + 1;
            }
            else {
            start += (N % THREADS_NUM);
            end   += (N % THREADS_NUM);
            }
        }

        result += Sum(start, end);
    }

    printf("%f\n", result);

    return 0;    
}