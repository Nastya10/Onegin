#include <stdio.h>
#include <stdlib.h>

#include "lines.h"
#include "overall.h"


int main()
{
    FILE *input_file1 = fopen("1", "r");
    FILE *input_file2 = fopen("2", "w");


    int file_len = 0;
    int len_array = 0;

    char *buffer = copy_file(input_file1, &file_len);
    struct array_element *array_lines = read_lines(buffer, file_len, &len_array);

    fprintf(input_file2, "The original:\n\n");
    fprint_array(array_lines, len_array, input_file2);
    fprintf(input_file2, "\n");

    fprintf(input_file2, "Sorted alphabetically by the beginning of the line:\n\n");
    quick_sort(array_lines, 0, len_array - 1, BEG_OF_LINE);
    fprint_array(array_lines, len_array, input_file2);
    fprintf(input_file2, "\n");

    fprintf(input_file2, "Sorted alphabetically by the end of the line:\n\n");
    quick_sort(array_lines, 0, len_array - 1, END_OF_LINE);

    fprint_array(array_lines, len_array, input_file2);
    fprintf(input_file2, "\n");

    free(array_lines);

    fclose(input_file1);
    fclose(input_file2);

    return 0;
}
