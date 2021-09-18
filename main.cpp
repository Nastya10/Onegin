#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "lines.h"
#include "overall.h"

int main()
{
    printf("The program sorts the text from the beginning and from the end of the lines.\n\n");

    FILE *input_file1 = fopen("input.txt", "r");
    FILE *input_file2 = fopen("conclusion.txt", "w");

    assert(input_file1 != NULL);
    assert(input_file2 != NULL);

    int file_len = 0;
    int len_array = 0;

    char *buffer = copy_file(input_file1, &file_len);
    assert(buffer != NULL);

    struct array_element *array_lines = read_lines(buffer, file_len, &len_array);

    fprint_Onegin("Sorted alphabetically by the beginning of the line:", input_file2, len_array, array_lines, strcmp_begin);

    /*fprintf(input_file2, "\n-------------------------------------------------------------------");
    fprintf(input_file2, "\nSorted alphabetically by the beginning of the line:\n\n");
    quick_sort(array_lines, 0, len_array - 1, strcmp_begin);
    fprint_array(array_lines, len_array, input_file2);


    fprintf(input_file2, "\n-------------------------------------------------------------------");
    fprintf(input_file2, "\nSorted alphabetically by the end of the line:\n\n");
    quick_sort(array_lines, 0, len_array - 1, strcmp_end);
    fprint_array(array_lines, len_array, input_file2);

    fprintf(input_file2, "\n-------------------------------------------------------------------");
    fprintf(input_file2, "\nThe original:\n\n");
    fprintf(input_file2, "%s", buffer);*/

    free(array_lines);

    int fclose1 = fclose(input_file1);
    int fclose2 = fclose(input_file2);

    assert(fclose1 != EOF);
    assert(fclose2 != EOF);

    printf("Onegin has been successfully sorted.\n");

    return 0;
}
