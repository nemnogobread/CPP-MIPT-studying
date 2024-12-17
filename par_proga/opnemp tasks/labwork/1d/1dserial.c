#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ISIZE 100
#define JSIZE 100

int main(int argc, char **argv)
{
    double a[ISIZE][JSIZE];
    int i, j;
    FILE *ff;
    
    for (i = 0; i < ISIZE; i++)
    {
        for (j = 0; j < JSIZE; j++)
        {
            a[i][j] = 10 * i + j;
        }
    }

    for (i = 0; i < ISIZE - 1; i++)
    {
        for (j = 6; j < JSIZE; j++)
        {
            a[i][j] = sin(0.2 * a[i + 1][j - 6]);
        }
    }

    ff = fopen("1dserial_result.txt", "w");
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