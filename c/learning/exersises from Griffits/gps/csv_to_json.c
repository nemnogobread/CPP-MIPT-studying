#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int main()
{
    float latitude, longitude;
    char info[80];
    bool started = false;
    
    puts("{");
    puts("\t\"data\": [");
    
    while(scanf("%f, %f, %80[^\n]", &latitude, &longitude, info) == 3)
    {
        if(started)
            printf(",\n");
        else
            started = true;
        if(latitude<-90.0 || latitude>90.0)
        {
            fprintf(stderr, "Неправильная широта: %f\n", latitude);
            printf("\n\t]");
            printf("\n}");
            return 2;
        }
        if(longitude<-180.0 || longitude>180.0)
        {
            fprintf(stderr, "Неправильная долгота: %f\n", longitude);
            printf("\n\t]");
            printf("\n}");
            return 2;
        }
        printf("\t\t{\"latitude\": %f, \"longitude\": %f, \"info\": \"%s\"}", latitude, longitude, info);
    }

    printf("\n\t]");
    printf("\n}");

    return 0;
}