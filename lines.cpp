#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <ctype.h>

#include "lines.h"

int puts_(char *line, char end_input)
{
    if (line == NULL)
        return EOF;

    for (int symbol_index = 0; line[symbol_index] != end_input; symbol_index++)
    {
        int symbol = putchar(line[symbol_index]);
        if(symbol == EOF)
        {
            printf("Output error");
            return EOF;
        }
    }

    putchar('\n');

    return 1;
}

char *strchr_(char *line, char symbol, char end_input)
{
    assert(line != NULL);

    int position = -1;

    int symbol_index = 0;

    for (symbol_index; line[symbol_index] != end_input; symbol_index++)
    {
        if (line[symbol_index] == symbol)
        {
            position = symbol_index;
            break;
        }
    }

    if (symbol == end_input)
        return &line[symbol_index];

    return position == -1 ? NULL : &line[position];
}

int strlen_(char *line, char end_input)
{
    assert(line != NULL);

    int string_length = 0;

    for (string_length; line[string_length] != end_input; string_length++)
        ;

    return string_length;
}

char *strcpy_(char *dest, char *source, char end_input)
{
    assert(dest != NULL);
    assert(source != NULL);
    assert(dest != source);

    int symbol_index = 0;

    for (symbol_index; source[symbol_index] != end_input; symbol_index++)
        dest[symbol_index] = source[symbol_index];

    dest[symbol_index + 1] = end_input;

    return dest;
}

char *strncpy_(char *dest, char *source, int string_length, char end_input)
{
    assert(dest != NULL);
    assert(source != NULL);
    assert(dest != source);

    int symbol_index = 0;

    for (symbol_index; source[symbol_index] != end_input &&
         symbol_index < string_length; symbol_index++)
    {
        dest[symbol_index] = source[symbol_index];
    }

    dest[symbol_index + 1] = end_input;

    return dest;
}

char *strcat_(char *dest, char *append, char end_input)
{
    assert(dest != NULL);
    assert(append != NULL);

    int dest_len = strlen_(dest);

    for (int symbol_index = 0; append[symbol_index] != end_input; symbol_index++)
    {
        dest[dest_len] = append[symbol_index];
        dest_len++;
    }
    return dest;
}

char *strncat_(char *dest, char *append, int string_length, char end_input)
{
    assert(dest != NULL);
    assert(append != NULL);

    int dest_len = strlen_(dest);

    for (int symbol_index = 0; append[symbol_index] != end_input &&
         symbol_index < string_length; symbol_index++)
    {
        dest[dest_len] = append[symbol_index];
        dest_len++;
    }
    return dest;
}

char *strdup_(char *dest)
{
    assert(dest != NULL);

    int dest_len = strlen_(dest);

    char *line_copy = NULL;

    line_copy = (char*) calloc(dest_len + 1, sizeof(char));

    if (line_copy == NULL)
    {
        printf("ERROR calloc");
        return NULL;
    }

    strncpy_(line_copy, dest, dest_len);

    return line_copy;
}

int getline_(FILE *input, char **dest, int string_length, char end_input)
{
    int symbol = fgetc(input);

    while(symbol != EOF && symbol != end_input)
    {
        int len_dest = *dest != NULL ? strlen_(*dest) : 0;

        if (len_dest >= string_length)
            break;

        char* temp = (char *)realloc(*dest, (len_dest + 2) * sizeof(char));

        if (temp == NULL) {
            printf ("ERROR: Realloc faild\n");
            return -1;
        }

        *dest = temp;

        (*dest)[len_dest] = symbol;
        (*dest)[len_dest + 1] = 0;

        symbol = fgetc(input);
    }

    if (symbol == EOF)          //проверка конец файла или ошибка чтения
    {
        if (feof(input) == 0)
        {
            printf("File reading error\n");
            return -1;
        }
        return END_FILE;               //считанная строка состоит только из символа конца файла
    }

    return 1;

}

int fgets_(FILE *input, char *dest, char end_input, int string_length)
{
    if (dest == NULL)
        return NULL;

    char symbol = fgetc(input);

    int symbol_index = 0;

    for (symbol_index; symbol != EOF && symbol != end_input &&
         symbol_index < (string_length - 1); symbol_index++)
    {
        dest[symbol_index] = symbol;

        symbol = fgetc(input);
    }

    dest[symbol_index + 1] = 0;

    if (symbol == EOF)          //проверка конец файла или ошибка чтения
    {
        if (feof(input))
        {
            printf("File reading error\n");
            return NULL;
        }
        return 0;               //считанная строка состоит только из символа конца файла
    }


    return 1;
}


int line_is_empty(char *line, char end_input)
{
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
