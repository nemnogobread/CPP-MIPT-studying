#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    struct timeval start = {};
    struct timeval end = {};
    
    pid_t pid = fork();

    if (pid)
    {
        gettimeofday(&start, NULL);
    }
    else
    {
        execvp(argv[0], argv + 1);
    }
    int status;
    wait(&status);
    
    gettimeofday(&end, NULL);

    printf("%d \n", end.tv_sec - start.tv_sec);
    return 0;
}