#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lines.h"
#include "overall.h"

struct array_element *read_lines(char *buffer, const int buffer_len, int* length)
{
    assert(buffer != NULL);
    assert(length != NULL);

    int num_lines = n_lines(buffer, buffer_len);

    struct array_element *array_lines = (struct array_element*) calloc(num_lines, sizeof(struct array_element));
    assert(array_lines != 0);

    int array_index = 0;

    for (int symbol_index = 0; array_index < num_lines; symbol_index++)
    {
        if (line_is_empty(&buffer[symbol_index], 0) == 0)
        {
            array_lines[array_index].str = &buffer[symbol_index];
            array_lines[array_index].len = strlen_(&buffer[symbol_index], END_OF_STR);

            symbol_index += array_lines[array_index].len;

            ++array_index;
        }
        else
        {
            symbol_index += strlen_(&buffer[symbol_index], END_OF_STR);

            --num_lines;
        }
    }

    *length = num_lines;

    return array_lines;
}

int strlen_(const char *str, const char end_input)
{
    assert(str != NULL);

    int string_length = 0;

    for (string_length; str[string_length] != end_input; string_length++)
        ;

    return string_length;
}

int line_is_empty(const char *str, const char end_input)
{
    assert(str != NULL);

    for (int symbol_index = 0;  str[symbol_index] != end_input
                                && str[symbol_index] != END_OF_STR; symbol_index++)
    {
        if (is_comparable(str[symbol_index]) == 1)
        {
            return 0;
        }
    }
    return 1;
}


int strcmp_begin(char *str1, char *str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    int len_str1 = strlen_(str1, END_OF_STR), len_str2 = strlen_(str2, END_OF_STR);

    int len_alfa_str1 = len_alpha_str(str1, len_str1);
    int len_alfa_str2 = len_alpha_str(str2, len_str2);

    int symbol_index_str1 = 0, symbol_index_str2 = 0;

    while (str1[symbol_index_str1] != END_OF_STR && str2[symbol_index_str2] != END_OF_STR)
    {
        while (is_comparable(str1[symbol_index_str1]) == 0 && str1[symbol_index_str1] != END_OF_STR)
        {
            ++symbol_index_str1;
        }

        while (is_comparable(str2[symbol_index_str2]) == 0 && str2[symbol_index_str2] != END_OF_STR)
        {
            ++symbol_index_str2;
        }

        char symbol1 = tolower_(str1[symbol_index_str1]);
        char symbol2 = tolower_(str2[symbol_index_str2]);

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
        ++symbol_index_str1;
        ++symbol_index_str2;
    }

    if (len_alfa_str1 == len_alfa_str2)
    {
        return 0;
    }
    else
    {
        if (len_alfa_str1 > len_alfa_str2)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

int strcmp_end(char *str1, char *str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    int len_str1 = strlen_(str1, END_OF_STR), len_str2 = strlen_(str2, END_OF_STR);

    int len_alfa_str1 = len_alpha_str(str1, len_str1);
    int len_alfa_str2 = len_alpha_str(str2, len_str2);

    int symbol_index_str1 = len_str1 - 1, symbol_index_str2 = len_str2 - 1;

    while (symbol_index_str1 >= 0 && symbol_index_str2 >= 0)
    {
        while (is_comparable(str1[symbol_index_str1]) == 0 && symbol_index_str1 >= 0)
        {
            --symbol_index_str1;
        }

        while (is_comparable(str2[symbol_index_str2]) == 0 && symbol_index_str2 >= 0)
        {
            --symbol_index_str2;
        }

        char symbol1 = tolower_(str1[symbol_index_str1]);
        char symbol2 = tolower_(str2[symbol_index_str2]);

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
        --symbol_index_str1;
        --symbol_index_str2;
    }

    if (len_alfa_str1 == len_alfa_str2)
    {
        return 0;
    }
    else
    {
        if (len_alfa_str1 > len_alfa_str2)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

int n_lines(const char *buffer, const int buffer_len)
{
    assert(buffer != NULL);

    int num_lines = 0;

    for (int symbol_index = 0; symbol_index <= buffer_len; symbol_index++)
    {
        if (buffer[symbol_index] == '\n')
        {
            num_lines++;
        }
    }

    return num_lines;
}

int len_alpha_str(const char *str, const int len_str)
{
    int len = 0;

    for (int symbol_index = 0; symbol_index < len_str; ++symbol_index)
    {
        len += is_comparable(str[symbol_index]);
    }

    return len;
}

int is_comparable(const char symbol)
{
    for (int symbol_index = 0; symbol_index < ARR_RU_LEN; ++symbol_index)
    {
        if (symbol == ARR_RU[symbol_index])
        {
            return 1;
        }
    }

    for (int symbol_index = 0; symbol_index < ARR_ru_LEN; ++symbol_index)
    {
        if (symbol == ARR_ru[symbol_index])
        {
            return 1;
        }
    }

    for (int symbol_index = 0; symbol_index < ARR_EN_LEN; ++symbol_index)
    {
        if (symbol == ARR_EN[symbol_index])
        {
            return 1;
        }
    }

    for (int symbol_index = 0; symbol_index < ARR_en_LEN; ++symbol_index)
    {
        if (symbol == ARR_en[symbol_index])
        {
            return 1;
        }
    }

    for (int symbol_index = 0; symbol_index < ARR_NUM_LEN; ++symbol_index)
    {
        if (symbol == ARR_NUM[symbol_index])
        {
            return 1;
        }
    }

    return 0;
}

char tolower_(const char symbol)
{
    for (int symbol_index = 0; symbol_index < ARR_RU_LEN; ++symbol_index)
    {
        if (symbol == ARR_RU[symbol_index])
        {
            return ARR_ru[symbol_index];
        }
    }

    for (int symbol_index = 0; symbol_index < ARR_EN_LEN; ++symbol_index)
    {
        if (symbol == ARR_EN[symbol_index])
        {
            return ARR_en[symbol_index];
        }
    }

    return symbol;
}

int fputs_(const char *line, const char end_input, FILE *conclusion)
{
    if (line == NULL)
        return EOF;

    for (int symbol_index = 0; line[symbol_index] != end_input; symbol_index++)
    {
        int symbol = putc(line[symbol_index], conclusion);
        if(symbol == EOF)
        {
            printf("Output error");
            return EOF;
        }
    }

    putc('\n', conclusion);

    return 1;
}
