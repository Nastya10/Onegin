#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lines.h"
#include "overall.h"


int file_size(FILE *input_file)
{
    assert(input_file != NULL);

    fseek(input_file, 0, SEEK_END);
    int file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    return file_size;
}

char *copy_file(FILE *input_file, int *file_len)
{
    assert(input_file != NULL);
    assert(file_len != NULL);

    *file_len = file_size(input_file);

    char *buffer = (char*) calloc(*file_len + 2, sizeof(char));
    assert(buffer != 0);

    buffer[*file_len] = '\n';

    fread(buffer, sizeof(char), *file_len, input_file);

    return buffer;
}

void print_array(struct array_element *array_lines, const int len_array)
{
    assert(array_lines != NULL);

    fprint_array(array_lines, len_array, stdout);
}

void fprint_array(struct array_element *array_lines, const int len_array, FILE *conclusion)
{
    assert(array_lines != NULL);
    assert(conclusion != NULL);

    for(int symbol_index = 0; symbol_index < len_array; symbol_index++)
        fputs_(array_lines[symbol_index].str, END_OF_STR, conclusion);
}

int max_(const int number1, const int number2)
{
    return ((number2 > number1) ? number2 : number1);
}

int min_(const int number1, const int number2)
{
    return ((number2 < number1) ? number2 : number1);
}

void quick_sort(struct array_element *array_lines, const int low, const int high, enum direction start)
{
    assert(array_lines != NULL);

    int symbol_index1 = low;
    int symbol_index2 = high;

    int (*strcmp_)(char *, char *) = NULL;

    if (start == BEG_OF_LINE)
    {
        strcmp_ = strcmp_begin;
    }
    else
    {
        strcmp_ = strcmp_end;
    }

    char *pivot = array_lines[(low + (high-low)/2)].str;

    while (symbol_index1 <= symbol_index2)
    {
        while (strcmp_(array_lines[symbol_index1].str, pivot) == -1)
        {
            ++symbol_index1;
        }

        while (strcmp_(array_lines[symbol_index2].str, pivot) == 1)
        {
            --symbol_index2;
        }

        if (symbol_index1 <= symbol_index2)
        {
            if (strcmp_(array_lines[symbol_index1].str, array_lines[symbol_index2].str) == 1)
            {
                char *temp = array_lines[symbol_index1].str;
                int temp_len = array_lines[symbol_index1].len;

                array_lines[symbol_index1].str = array_lines[symbol_index2].str;
                array_lines[symbol_index1].len = array_lines[symbol_index2].len;

                array_lines[symbol_index2].str = temp;
                array_lines[symbol_index2].len = temp_len;
            }

            symbol_index1++;

            if (symbol_index2 > 0)
            {
                --symbol_index2;
            }
        }
    }

    if (symbol_index1 < high)
    {
        quick_sort(array_lines, symbol_index1, high, start);
    }

    if (symbol_index2 > low)
    {
        quick_sort(array_lines, low, symbol_index2, start);
    }
}
