#include <cassert>
#include <cctype>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lines.h"
#include "overall.h"

struct array_element *read_lines(char *buffer, int file_len, int* length)
{
    assert(buffer != NULL);
    assert(length != NULL);

    int num_lines = n_lines(buffer, file_len);

    struct array_element *array_lines = (struct array_element*) calloc(num_lines, sizeof(struct array_element));

    int array_index = 0;

    for (int symbol_index = 0; array_index < num_lines; symbol_index++)
    {
        if (line_is_empty(&buffer[symbol_index], 0) == 0)
        {
            array_lines[array_index].line = &buffer[symbol_index];
            array_lines[array_index].line_len = strlen_(&buffer[symbol_index], 0);

            symbol_index += array_lines[array_index].line_len;

            array_index++;
        }
        else
        {
            symbol_index += strlen_(&buffer[symbol_index], 0);

            num_lines--;
        }
    }

    *length = num_lines;

    return array_lines;
}

int strlen_(char *line, char end_input)
{
    assert(line != NULL);

    int string_length = 0;

    for (string_length; line[string_length] != end_input; string_length++)
        ;

    return string_length;
}

int line_is_empty(char *line, char end_input)
{
    assert(line != NULL);

    for (int symbol_index = 0; line[symbol_index] != end_input
         && line[symbol_index] != 0; symbol_index++)
    {
        if (!isspace(line[symbol_index]))
        {
            return 0;
        }
    }
    return 1;
}


int strcmp_(char *str1, char *str2, enum direction start)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);

    int min_len = min_(len_str1, len_str2);

    for(int symbol_index = 0; symbol_index < min_len; symbol_index++)
    {
        if (start == BEG_OF_LINE)
        {
            char symbol1 = tolower(str1[symbol_index]);
            char symbol2 = tolower(str2[symbol_index]);

            if (symbol1 != symbol2)
            {
                if ((int)(symbol1) > (int)(symbol2))
                {
                    return 1;
                }
                else
                {
                    return -1;
                }
            }
        }
        else
        {
            char symbol1 = tolower(str1[len_str1 - 1 - symbol_index]);
            char symbol2 = tolower(str2[len_str2 - 1 - symbol_index]);

            if (symbol1 != symbol2)
            {
                if ((int)(symbol1) > (int)(symbol2))
                {
                    return 1;
                }
                else
                {
                    return -1;
                }
            }
        }
    }

    if (len_str1 == len_str2)
    {
        return 0;
    }
    else
    {
        if (len_str1 > len_str2)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}


int n_lines(char *buffer, int file_len)
{
    assert(buffer != NULL);

    int num_lines = 0;

    for (int symbol_index = 0; symbol_index <= file_len; symbol_index++)
    {
        if (buffer[symbol_index] == '\n')
        {
            buffer[symbol_index] = 0;
            num_lines++;
        }
    }

    return num_lines;
}
