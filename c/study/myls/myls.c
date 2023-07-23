#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h> 
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdint.h>
#include <unistd.h>
#include <inttypes.h>

const char *optstring;

void ls();

void show();

int main(int argc, char* argv[])
{   

    for (int i = 0; i < argc; i++)
    {
        ls(argv[i]);
    }
    printf("\n");
    return 0;
}


void ls(char *str)
{
    int *DIR = opendir(str);
    int *e;
    printf("%s\n", str);
    
    while (e = readdir(DIR))
    {
        show(e);
    }
    closedir(str);
}


void show(int *e)
{
    //printf("%s\n", d_name);
}