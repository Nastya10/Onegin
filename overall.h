#ifndef OVERALL_H_INCLUDED
#define OVERALL_H_INCLUDED

const int MAX_LENGTH = 1000;

struct array_element {
    char *line;
    int line_len;
};

char **read_lines(FILE *input, int* length);

void print_array(char **array_lines, int len_array);

void fprint_array(char **array_lines, int len_array, FILE *conclusion);

void bubble_sort(char **array_lines, int len_array);

#endif // OVERALL_H_INCLUDED
