#include <stdio.h>
#include <stdlib.h>
#include <cassert>

#include "lines.h"

int puts_(char *line)
{
    if (line == NULL)
        return EOF;

    for (int symbol_index = 0; line[symbol_index] != '\0'; symbol_index++)
    {
        putchar(line[symbol_index]);
    }

    putchar('\n');

    return 1;
}

char *strchr_(char *line, char symbol)
{
    assert(line != NULL);

    int position = -1;

    for (int symbol_index = 0; line[symbol_index] != '\0'; symbol_index++)
    {
        if (line[symbol_index] == symbol)
        {
            position = symbol_index;
            break;
        }
    }

    return position == -1 ? NULL : &line[position];
}

int strlen_(char *line)
{
    assert(line != NULL);

    int string_length = 0;

    for (string_length; line[string_length] != '\0'; string_length++) {};

    return (string_length);
}

void strcpy_(char *dest, char *source)     //ok
{
    assert(dest != NULL);
    assert(source != NULL);

    for (int symbol_index = 0; source[symbol_index] != '\0'; symbol_index++)
        dest[symbol_index] = source[symbol_index];
}

void strncpy_(char *dest, char *source, int string_length)     //ok
{
    assert(dest != NULL);
    assert(source != NULL);

    for (int symbol_index = 0; source[symbol_index] != '\0' && symbol_index != string_length; symbol_index++)
    {
        dest[symbol_index] = source[symbol_index];
    }
}

void strcat_(char *dest, char *append)     //ok
{
    assert(dest != NULL);
    assert(append != NULL);

    int dest_len = strlen_(dest);

    for (int symbol_index = 0; append[symbol_index] != '\0'; symbol_index++)
    {
        dest[dest_len] = append[symbol_index];
        dest_len++;
    }
}

void strncat_(char *dest, char *append, int string_length)      //ok
{
    assert(dest != NULL);
    assert(append != NULL);

    int dest_len = strlen_(dest);

    for (int symbol_index = 0; append[symbol_index] != '\0' && symbol_index != string_length; symbol_index++)
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

        *dest = (char*) realloc(*dest, (len_dest + 2) * sizeof(char));
        (*dest)[len_dest] = symbol;
        (*dest)[len_dest + 1] = 0;

        symbol = getchar();
    }

    if (*dest == NULL)
        return NULL;

    if (symbol == EOF)
    {                         //проверка конец файла или ошибка чтения
        if (feof(input))
        {
            printf("Ошибка чтения файла\n");
            return NULL;
        }
    }

}

int fgets_(FILE *input, char **dest, char end_input, int string_length)
{
    int symbol = fgetc(input);

    while(symbol != EOF && symbol != end_input)
    {
        int len_dest = *dest != NULL ? strlen_(*dest) : 0;

        if (len_dest == string_length)
            break;

        *dest = (char*) realloc(*dest, (len_dest + 2) * sizeof(char));
        (*dest)[len_dest] = symbol;
        (*dest)[len_dest + 1] = 0;

        symbol = getchar();
    }

    if (*dest == NULL)
        return NULL;

    if (symbol == EOF)
    {                         //проверка конец файла или ошибка чтения
        if (feof(input))
        {
            printf("Ошибка чтения файла\n");
            return NULL;
        }
    }

    return 1;
}
