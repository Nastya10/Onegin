#ifndef LINES_H_INCLUDED
#define LINES_H_INCLUDED

/**
 * ����� ������ � ����������� ����� ������
 *
 * @param[in] line ��������� �� ������, ������� ���������� �������
 */
int puts_(char *line);

/**
 * ����� ������� ��������� ������� � ������
 *
 * @param[in] line      ��������� �� ������, � ������� ����� �������������� �����
 * @param[in] symbol    ��� �������� �������
 *
 * @param[out] position ��������� �� ������� ������, ���� �� ������ � ������ str, ����� NULL
 */
char *strchr_(char *line, char symbol);

/**
 * ����������� ����� ������
 *
 * @param[in]  line          ��������� �� ������
 *
 * @param[out] string_length ���������� �������� � ������ �� ������� ��������� ������� ����� ������
 */
int strlen_(char *line);

/**
 * ����������� �����
 *
 * @param[in]  source ��������� �� ������ �������� ���������� ������
 *
 * @param[out] dest   ��������� �� ������, � ������� ����� ����������� ������
 */
void strcpy_(char *dest, char *source);

/**
 * ����������� ����� c ������������ �����
 *
 * @param[in] source        ��������� �� ������ �������� ���������� ������
 * @param[in] string_length ����������� ������ �����������
 *
 * @param[out] dest         ��������� �� ������ � ������� ����� ����������� ������
 */
void strncpy_(char *dest, char *source, int string_length);

/**
 * ����������� �����
 *
 * @param[in]  append ��������� �� ������ �������� ���������� ������
 *
 * @param[out] dest   ��������� �� ������, � ������� ����� ��������� ������
 */
void strcat_(char *dest, char *append);

/**
 * ����������� ����� c ������������ ����� ����������� ������
 *
 * @param[in] append        ��������� �� ������ �������� ���������� ������
 * @param[in] string_length ������������ ����� ����������� �������
 *
 * @param[out] dest         ��������� �� ������, � ������� ����� ��������� ������
 */
void strncat_(char *dest, char *append, int string_length);

/**
 * ������������ ����� � ���������� ������ ��� ����� ������
 *
 * @param[in] dest       ��������� �� ����������� ������
 *
 * @param[out] line_copy ��������� �� ����������� ������
 */
char *strdup_(char *dest);

/**
 * ������ ������ �� ���������� ������ ������
 *
 * @param[in] input     ��������� �� ����� ������
 * @param[in] end_input ������, ������� �������� ����� ����������� ������
 *
 * @param[out] dest     ��������� �� ��������� �� ������,
 *                      � ������� ����� �������� ��������� ������
 */
int getline_(FILE *input, char **dest, char end_input);

/**
 * ������ ������ �� ���������� ������ ������ � ������������ �����
 *
 * @param[in] input         ��������� �� ����� ������
 * @param[in] end_input     ������, ������� �������� ����� ����������� ������
 * @param[in] string_length ����������� ���������� ������ ����������� ������
 *
 * @param[out] dest         ��������� �� ��������� �� ������,
 *                          � ������� ����� �������� ��������� ������
 */
int fgets_(FILE *input, char **dest, char end_input, int string_length);

#endif // LINES_H_INCLUDED
