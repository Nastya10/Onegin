#ifndef LINES_H_INCLUDED
#define LINES_H_INCLUDED

const char END_OF_STR = '\n';

const char ARR_ru[] = {
                       'à', 'á', 'â', 'ã', 'ä', 'å', '¸', 'æ', 'ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ð', \
                       'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', '÷', 'ø', 'ù', 'ü', 'û', 'ú', 'ý', 'þ', 'ÿ'                 \
                      };

const char ARR_RU[] = {
                       'À', 'Á', 'Â', 'Ã', 'Ä', 'Å', '¨', 'Æ', 'Ç', 'È', 'É', 'Ê', 'Ë', 'Ì', 'Í', 'Î', 'Ï', 'Ð', \
                       'Ñ', 'Ò', 'Ó', 'Ô', 'Õ', 'Ö', '×', 'Ø', 'Ù', 'Ü', 'Û', 'Ú', 'Ý', 'Þ', 'ß'                 \
                      };

const char ARR_en[] = {
                       'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', \
                       's', 't', 'u', 'v', 'w', 'x', 'y', 'z'                                                    \
                      };

const char ARR_EN[] = {
                       'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', \
                       'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'                                                    \
                      };

const char ARR_NUM[] = {
                        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'                                         \
                       };

const int ARR_ru_LEN = 33;
const int ARR_RU_LEN = 33;
const int ARR_en_LEN = 26;
const int ARR_EN_LEN = 26;
const int ARR_NUM_LEN = 10;

struct array_element {
    char *str;
    int len;
};

enum direction {
    BEG_OF_LINE = 1,
    END_OF_LINE = -1
};

struct array_element *read_lines(char *buffer, int buffer_len, int* length);

int strlen_(const char *str, const char end_input);

int line_is_empty(const char *str, const char end_input);

int strcmp_begin(char *str1, char *str2);

int strcmp_end(char *str1, char *str2);

int n_lines(const char *buffer, const int buffer_len);

int len_alpha_str(const char *str, const int len_str);

int is_comparable(const char symbol);

char tolower_(const char symbol);

int fputs_(const char *line, const char end_input, FILE *conclusion);

#endif // LINES_H_INCLUDED
