#include <stdio.h>
#include "encrypt.h"

int main(int argc, char *argv[])
{
    char msg[80];
    while (fgets(msg, 80, stdin))
    {
        encrypt(msg);
        printf("%s\n", msg);
    }
}