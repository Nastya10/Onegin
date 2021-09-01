#ifndef LINES_H_INCLUDED
#define LINES_H_INCLUDED

struct array_element {
    char *line;
    int line_len;
};

enum direction {
    BEG_OF_LINE = 1,
    END_OF_LINE = -1
};

struct array_element *read_lines(char *buffer, int file_len, int* length);

int strlen_(char *line, char end_input);

int line_is_empty(char *line, char end_input);

int strcmp_(char *str1, char *str2, enum direction start);

int n_lines(char *buffer, int file_len);

#endif // LINES_H_INCLUDED
