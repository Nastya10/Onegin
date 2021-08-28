#include <stdio.h>
#include <stdlib.h>
#include <cassert>

#include "lines.h"

int puts_(char *line, char end_input)
{
    if (line == NULL)
        return EOF;

    for (int symbol_index = 0; line[symbol_index] != end_input; symbol_index++)
    {
        putchar(line[symbol_index]);
    }

    putchar('\n');

    return 1;
}

char *strchr_(char *line, char symbol, char end_input)
{
    assert(line != NULL);

    int position = -1;

    for (int symbol_index = 0; line[symbol_index] != end_input; symbol_index++)
    {
        if (line[symbol_index] == symbol)
        {
            position = symbol_index;
            break;
        }
    }

    if (symbol == end_input)
        return &line[strlen_(line, end_input) - 1];

    return position == -1 ? NULL : &line[position];
}

int strlen_(char *line, char end_input)
{
    assert(line != NULL);

    int string_length = 0;

    for (string_length; line[string_length] != end_input; string_length++) {};

    return (string_length);
}

void strcpy_(char *dest, char *source, char end_input)
{
    assert(dest != NULL);
    assert(source != NULL);

    for (int symbol_index = 0; source[symbol_index] != end_input; symbol_index++)
        dest[symbol_index] = source[symbol_index];
}

void strncpy_(char *dest, char *source, int string_length, char end_input)
{
    assert(dest != NULL);
    assert(source != NULL);

    for (int symbol_index = 0; source[symbol_index] != end_input &&
         symbol_index != string_length; symbol_index++)
    {
        dest[symbol_index] = source[symbol_index];
    }
}

void strcat_(char *dest, char *append, char end_input)
{
    assert(dest != NULL);
    assert(append != NULL);

    int dest_len = strlen_(dest);

    for (int symbol_index = 0; append[symbol_index] != end_input; symbol_index++)
    {
        dest[dest_len] = append[symbol_index];
        dest_len++;
    }
}

void strncat_(char *dest, char *append, int string_length, char end_input)
{
    assert(dest != NULL);
    assert(append != NULL);

    int dest_len = strlen_(dest);

    for (int symbol_index = 0; append[symbol_index] != end_input &&
         symbol_index != string_length; symbol_index++)
    {
        dest[dest_len] = append[symbol_index];
        dest_len++;
    }
}

char *strdup_(char *dest)
{
    assert(dest != NULL);

    int dest_len = strlen_(dest);

    char *line_copy = NULL;

    line_copy = (char*) calloc(dest_len + 1, sizeof(char));
    strcpy_(line_copy, dest);

    return line_copy;
}

int getline_(FILE *input, char **dest, char end_input)
{
    int symbol = fgetc(input);

    while(symbol != EOF && symbol != end_input)
    {
        int len_dest = *dest != NULL ? strlen_(*dest) : 0;

        char* temp = (char*) realloc(*dest, (len_dest + 2) * sizeof(char));

        if (temp == NULL) {
            return -1;
        }

        *dest = temp;
        (*dest)[len_dest] = symbol;
        (*dest)[len_dest + 1] = 0;

        symbol = getchar();
    }

    if (*dest == NULL)
        return NULL;

    if (symbol == EOF)          //проверка конец файла или ошибка чтения
    {
        if (feof(input))
        {
            printf("File reading error\n");
            return -1;
        }
    }

}

int fgets_(FILE *input, char *dest, char end_input, int string_length)
{
    if (dest == NULL)
        return NULL;

    char symbol = fgetc(input);

    int symbol_index = 0;

    for (symbol_index; symbol != EOF && symbol != end_input; symbol_index++)
    {
        if (symbol_index == string_length)
        {
            break;
        }

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
    }


    return 1;
}


int line_is_empty(char *line, char end_input)
{
    for (int symbol_index = 0; line[symbol_index] != end_input; symbol_index++)
    {
        if (line[symbol_index] != NULL && line[symbol_index] != ' ' && line[symbol_index] != '\t')
        {
            printf("%d\t%d\n", (int)(line[symbol_index]), symbol_index);

            return 0;
        }
    }
    return 1;
}
