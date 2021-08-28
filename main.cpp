#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "lines.h"

int main()
{
    char line[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, '\n'};
    printf("%d\n", line_is_empty(line));

    /*char line[10] = {};
    getline_(stdin, &line, ';');
    printf("FINAL OUTPUT: %s\n", line);*/

    return 0;
}
