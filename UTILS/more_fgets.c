#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fgets_int(int *var)
{
    char str[100];
    fgets(str, sizeof(str), stdin);
    *var = atoi(str);
}

void fgets_float(float *var)
{
    char str[100];
    fgets(str, sizeof(str), stdin);
    *var = atof(str);
}

void fgets_str(char *str, int size)
{
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = 0;
}
