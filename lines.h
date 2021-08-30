#ifndef LINES_H_INCLUDED
#define LINES_H_INCLUDED

const int END_FILE = 2;

/**
 * Вывод строки в стандартный поток вывода
 *
 * @param[in] line             указатель на строку, которую необходимо вывести
 * @param[in] end_input = '\n' опциональный параметр функции, конец считывания
 *
 * @return 1 если вывод прошёл успешно
 * @return EOF  случае ошибки
 */
int puts_(char *line, char end_input = '\n');

/**
 * Поиск первого вхождения символа в строку
 *
 * @param[in] line             указатель на строку, в которой будет осуществляться поиск
 * @param[in] symbol           код искомого символа
 * @param[in] end_input = '\n' опциональный параметр функции, конец считывания
 *
 * @param[out] position        указатель на искомый символ, если он найден в строке str, иначе NULL
 *
 * @return NULL если символ не входит
 */
char *strchr_(char *line, char symbol, char end_input = '\n');

/**
 * Определение длины строки
 *
 * @param[in] line             указатель на строку
 * @param[in] end_input = '\n' опциональный параметр функции, конец считывания
 *
 * @param[out] string_length   количество символов в строке до первого вхождения символа конца строки
 */
int strlen_(char *line, char end_input = '\0');

/**
 * Копирование строк
 *
 * @param[in] source           указатель на строку источник копируемых данных
 * @param[in] end_input = '\n' опциональный параметр функции, конец считывания
 *
 * @param[out] dest            указатель на строку, в которую будут скопированы данные
 *
 * @return dest
 */
char *strcpy_(char *dest, char *source, char end_input = '\n');

/**
 * Копирование строк c ограничением длины
 *
 * @param[in] source           указатель на строку источник копируемых данных
 * @param[in] string_length    ограничение длинны копирования
 * @param[in] end_input = '\n' опциональный параметр функции, конец считывания
 *
 * @param[out] dest            указатель на строку в которую будут скопированы данные
 *
 * @return dest
 */
char *strncpy_(char *dest, char *source, int string_length, char end_input = '\n');

/**
 * Объединение строк
 *
 * @param[in] append           указатель на строку источник копируемых данных
 * @param[in] end_input = '\n' опциональный параметр функции, конец считывания
 *
 * @param[out] dest            указатель на строку, в которую будет добавлена строка
 *
 * @return dest
 */
char *strcat_(char *dest, char *append, char end_input = '\n');

/**
 * Объединение строк c ограничением длины добавляемой строки
 *
 * @param[in] append           указатель на строку источник копируемых данных
 * @param[in] string_length    максимальная длина добавляемой строкия
 * @param[in] end_input = '\n' опциональный параметр функции, конец считывания
 *
 * @param[out] dest            указатель на строку, в которую будет добавлена строка
 *
 * @return dest
 */
char *strncat_(char *dest, char *append, int string_length, char end_input = '\n');

/**
 * Дублирование строк с выделением памяти под новую строку
 *
 * @param[in] dest       указатель на дублируемую строку
 *
 * @param[out] line_copy указатель на дублирующую строку
 */
char *strdup_(char *dest);

/**
 * Чтение строки из указанного потока данных
 *
 * @param[in] input            указатель на поток данных
 * @param[in] end_input        символ, который означает конец считываемой строки
 * @param[in] end_input = '\n' опциональный параметр функции, конец считывания
 * @param[in] string_length    максимальная длина строки
 *
 * @param[out] dest            указатель на указатель на строки,
 *                             в которую будет помещена считанная строка
 *
 * @return END_FILE  если строка является концом файла
 * @return -1        в случае ошибки
 * @return 1         если строка записана успешно
 */
int getline_(FILE *input, char **dest, int string_length, char end_input = '\n');

/**
 * Чтение строки из указанного потока данных с ограничением длины
 *
 * @param[in] input            указатель на поток данных
 * @param[in] end_input        символ, который означает конец считываемой строки
 * @param[in] string_length    максимально допустимая длинна считываемой строки
 * @param[in] end_input = '\n' опциональный параметр функции, конец считывания
 *
 * @param[out] dest            указатель на указатель на строки,
 *                             в которую будет помещена считанная строка
 *
 * @return 0 если строка пустая
 */
int fgets_(FILE *input, char *dest, char end_input, int string_length);

/**
 * Проверка пустая ли строка
 *
 * @param[in] line             указатель на строку
 * @param[in] end_input = '\n' опциональный параметр функции, конец считывания
 *
 * @return 1 если строка пустая
 * @return 0 если в строке есть символы отличные от пробела, таба и нуля
 */
int line_is_empty(char *line, char end_input = '\n');

#endif // LINES_H_INCLUDED
