#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "lines.h"

int main()
{

    char *line = NULL;
    fgets_(stdin, &line, ';', 5);
    printf("%s\n", line);
    free(line);

    return 0;
}
