#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int x = 4;
    printf("x хранится по адресу %p \n", &x);
    return 0; 
}