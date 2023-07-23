#include "encrypt.h"

void encrypt(char *messege)
{
    while (*messege)
    {
        *messege = *messege ^ 21; 
        messege++; 
    }
}