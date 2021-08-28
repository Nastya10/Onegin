#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "lines.h"

int main()
{

    char line[10] = {};
    fgets_(stdin, line, ';', 5);
    printf("FINAL OUTPUT: %s\n", line);

    return 0;
}
