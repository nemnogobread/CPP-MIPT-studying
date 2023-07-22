#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        pid_t pid;
        pid = fork();
        int x = atoi(argv[i]);
        switch(pid)
        {
            case -1: // {*}при вызове fork() возникла ошибка{*}
            case 0 : 
                usleep(3000*x);
                printf("%d ", x);
                exit(0);
            default : // {*}это код родительского процесса{*}
        }
    }

    for (int i = 1; i < argc; i++)
    {
        int status;
        wait(&status);
    }

    printf("\n");

    return 0;
}