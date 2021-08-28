#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "lines.h"
#include "overall.h"

int main()
{
    int length = 0;
    char **lines = read_lines(stdin, &length);

    return 0;
}
