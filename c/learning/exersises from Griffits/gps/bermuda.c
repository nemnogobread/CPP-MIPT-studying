#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    float latitude, longitude;
    char info[80];
    while (scanf("%f, %f, %80[^\n]", &latitude, &longitude, info) == 3)
    {
        if (26.0 < latitude && latitude < 34.0 && -76.0 < longitude  && longitude < -64.0)
            printf("%f, %f, %s\n", latitude, longitude, info);
    }

    return 0;
}