#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "lines.h"

int main()
{

    char *line = "hghjvjh";
    fgets_(stdin, line, ';', 5);
    printf("%s\n", line);

    return 0;
}
