#ifndef OVERALL_H_INCLUDED
#define OVERALL_H_INCLUDED

int file_size(FILE *input_file);

char *copy_file(FILE *input_file, int *file_len);

void print_array(struct array_element *array_lines, int len_array);

void fprint_array(struct array_element *array_lines, int len_array, FILE *conclusion);

int max_(int number1, int number2);

int min_(int number1, int number2);

void quick_sort(struct array_element *array_lines, int low, int high, enum direction start);

#endif // OVERALL_H_INCLUDED
