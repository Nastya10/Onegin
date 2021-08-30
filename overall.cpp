#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <string.h>

#include "overall.h"
#include "lines.h"

char **read_lines(FILE *input, int* length)
{
    assert(length != NULL);

    char **array_lines = (char**) calloc(1, sizeof(char*));
    char* line = (char*) calloc(1, sizeof(char));

    int getline_result = getline_(input, &line, MAX_LENGTH, '\n');

    int symbol_index = 0;

    for (symbol_index; getline_result != -1 && getline_result != END_FILE; symbol_index++)
    {
        array_lines = (char**) realloc(array_lines, (symbol_index + 1) * sizeof(char*));

        if (array_lines == NULL) {
            printf ("ERROR: Realloc faild\n");
            return 0;
        }

        if (line_is_empty(line, '\n') == 0)
        {
            array_lines[symbol_index] = line;
        }
        else
        {
            symbol_index--;
        }

        line = (char*) calloc(1, sizeof(char));

        getline_result = getline_(input, &line, MAX_LENGTH, '\n');
    }

    *length = symbol_index;

    return array_lines;

}

void print_array(char **array_lines, int len_array)
{
    for(int symbol_index = 0; symbol_index < len_array; symbol_index++)
        printf("%s\n", array_lines[symbol_index]);
}

void fprint_array(char **array_lines, int len_array, FILE *conclusion)
{
    for(int symbol_index = 0; symbol_index < len_array; symbol_index++)
        fprintf(conclusion, "%s\n", array_lines[symbol_index]);
}

void bubble_sort(char **array_lines, int len_array)
{
    bool no_swap = 1;

    for (int symbol_index1 = len_array - 1; symbol_index1 >= 0; symbol_index1--)
    {
        no_swap = 1;

        for (int symbol_index2 = 0; symbol_index2 < symbol_index1; symbol_index2++)
        {
            if(strcmp(array_lines[symbol_index2], array_lines[symbol_index2 + 1]) > 0)
            {
                char *tmp = array_lines[symbol_index2];
                array_lines[symbol_index2] = array_lines[symbol_index2 + 1];
                array_lines[symbol_index2 + 1] = tmp;

                no_swap = 0;
            }
        }
        if(no_swap == 1)
        {
            break;
        }
    }
}
