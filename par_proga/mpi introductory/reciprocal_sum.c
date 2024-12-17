#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>


double Sum(long long start, long long end) {
    double partSum = 0.0;

    for(long long i = start; i < end; i++) {
        partSum += 1.0 / (double)i;
    }

    return partSum;
}


int main(int argc, char* argv[]) {

    MPI_Init(&argc, &argv);

    int commsize, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &commsize);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(argc < 2) {
        if(!rank)
            printf("Usage: %s [N]\n", argv[0]);

        MPI_Finalize();
        return 0;
    }

    const long long N = atoll(argv[1]);

    const long long diff  = N / commsize;
    long long start = 1 + diff * rank;
    long long end   = 1 + diff * (rank + 1);

    if(N % commsize) {
        if(rank < N % commsize) {
            start += rank;
            end += rank + 1;
        }
        else {
            start += (N % commsize);
            end   += (N % commsize);
        }
    }

    const double partSum = Sum(start, end);
    printf("Process %d: summing interval = [%10lld, %10lld)  ==>  Sum = %.16lg\n", rank, start, end, partSum);
    
    double totalSum = 0.0;
    if(!rank) {
        totalSum = partSum;
        for(int i = 1; i < commsize; i++) {
            double newPart = 0.0;
            MPI_Recv(&newPart, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            totalSum += newPart;
        }

        printf("\nTotal sum S = %.16lg\n", totalSum);
    }
    else {
        MPI_Send(&partSum, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}