#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    char line[80];
    if (argc != 6)
    {
        fprintf(stderr, "Братишка, ты по-моему что-то перепутал, аргументов должно быть 5\n");
        return 1;
    }

    FILE *in_file;
    if (!(in_file = fopen("input.csv", "r")))
    {
        fprintf(stderr, "He удалось открыть файл. \n");
        return 1;
    }

    FILE *out1_file = fopen(argv[2], "w");
    FILE *out2_file = fopen(argv[4], "w");
    FILE *out3_file = fopen(argv[5], "w");

    while (fscanf(in_file, "%80[^\n]\n", line) == 1)
    {
        if (strstr(line, argv[1]))
            fprintf(out1_file, "%s\n", line);
        else if (strstr(line, argv[3]))
            fprintf(out2_file, "%s\n", line);
        else
            fprintf(out3_file, "%s\n", line);
    }

    fclose(in_file);
    fclose(out1_file);
    fclose(out2_file);
    fclose(out3_file);

    return 0;
}