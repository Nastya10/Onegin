#ifndef LINES_H_INCLUDED
#define LINES_H_INCLUDED

/**
 * Вывод строки в стандартный поток вывода
 *
 * @param[in] line указатель на строку, которую необходимо вывести
 */
int puts_(char *line);

/**
 * Поиск первого вхождения символа в строку
 *
 * @param[in] line      указатель на строку, в которой будет осуществляться поиск
 * @param[in] symbol    код искомого символа
 *
 * @param[out] position указатель на искомый символ, если он найден в строке str, иначе NULL
 */
char *strchr_(char *line, char symbol);

/**
 * Определение длины строки
 *
 * @param[in]  line          указатель на строку
 *
 * @param[out] string_length количество символов в строке до первого вхождения символа конца строки
 */
int strlen_(char *line);

/**
 * Копирование строк
 *
 * @param[in]  source указатель на строку источник копируемых данных
 *
 * @param[out] dest   указатель на строку, в которую будут скопированы данные
 */
void strcpy_(char *dest, char *source);

/**
 * Копирование строк c ограничением длины
 *
 * @param[in] source        указатель на строку источник копируемых данных
 * @param[in] string_length ограничение длинны копирования
 *
 * @param[out] dest         указатель на строку в которую будут скопированы данные
 */
void strncpy_(char *dest, char *source, int string_length);

/**
 * Объединение строк
 *
 * @param[in]  append указатель на строку источник копируемых данных
 *
 * @param[out] dest   указатель на строку, в которую будет добавлена строка
 */
void strcat_(char *dest, char *append);

/**
 * Объединение строк c ограничением длины добавляемой строки
 *
 * @param[in] append        указатель на строку источник копируемых данных
 * @param[in] string_length максимальная длина добавляемой строкия
 *
 * @param[out] dest         указатель на строку, в которую будет добавлена строка
 */
void strncat_(char *dest, char *append, int string_length);

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
 * @param[in] input     указатель на поток данных
 * @param[in] end_input символ, который означает конец считываемой строки
 *
 * @param[out] dest     указатель на указатель на строки,
 *                      в которую будет помещена считанная строка
 */
int getline_(FILE *input, char **dest, char end_input);

/**
 * Чтение строки из указанного потока данных с ограничением длины
 *
 * @param[in] input         указатель на поток данных
 * @param[in] end_input     символ, который означает конец считываемой строки
 * @param[in] string_length максимально допустимая длинна считываемой строки
 *
 * @param[out] dest         указатель на указатель на строки,
 *                          в которую будет помещена считанная строка
 */
int fgets_(FILE *input, char **dest, char end_input, int string_length);

#endif // LINES_H_INCLUDED
