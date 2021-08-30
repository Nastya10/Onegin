#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "lines.h"
#include "overall.h"

int main()
{
    int length = 0;

    FILE *fp = fopen("1", "r");
    FILE *record = fopen("2", "w");

    char **array_lines = read_lines(fp, &length);

    bubble_sort(array_lines, length);

    print_array(array_lines, length);

    fprint_array(array_lines, length, record);

    fclose(fp);
    fclose(record);

    //printf("%d\n", line_is_empty("", '\0'));

    //char *line = line_backwards("abcdef", 6);

    //printf("%s\n", line);

    return 0;
}
