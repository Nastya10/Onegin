#ifndef OVERALL_H_INCLUDED
#define OVERALL_H_INCLUDED

int file_size(FILE *input_file);

char *copy_file(FILE *input_file, int *file_len);

void print_array(struct array_element *array_lines, const int len_array);

void fprint_array(struct array_element *array_lines, const int len_array, FILE *conclusion);

int max_(const int number1, const int number2);

int min_(const int number1, const int number2);

void quick_sort(struct array_element *array_lines, const int low, const int high, enum direction start);

#endif // OVERALL_H_INCLUDED
