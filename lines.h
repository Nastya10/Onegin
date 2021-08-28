#ifndef LINES_H_INCLUDED
#define LINES_H_INCLUDED

/**
 * ����� ������ � ����������� ����� ������
 *
 * @param[in] line             ��������� �� ������, ������� ���������� �������
 * @param[in] end_input = '\n' ������������ �������� �������, ����� ����������
 */
int puts_(char *line, char end_input = '\n');

/**
 * ����� ������� ��������� ������� � ������
 *
 * @param[in] line             ��������� �� ������, � ������� ����� �������������� �����
 * @param[in] symbol           ��� �������� �������
 * @param[in] end_input = '\n' ������������ �������� �������, ����� ����������
 *
 * @param[out] position        ��������� �� ������� ������, ���� �� ������ � ������ str, ����� NULL
 */
char *strchr_(char *line, char symbol, char end_input = '\n');

/**
 * ����������� ����� ������
 *
 * @param[in]  line            ��������� �� ������
 * @param[in] end_input = '\n' ������������ �������� �������, ����� ����������
 *
 * @param[out] string_length   ���������� �������� � ������ �� ������� ��������� ������� ����� ������
 */
int strlen_(char *line, char end_input = '\n');

/**
 * ����������� �����
 *
 * @param[in]  source          ��������� �� ������ �������� ���������� ������
 * @param[in] end_input = '\n' ������������ �������� �������, ����� ����������
 *
 * @param[out] dest            ��������� �� ������, � ������� ����� ����������� ������
 */
void strcpy_(char *dest, char *source, char end_input = '\n');

/**
 * ����������� ����� c ������������ �����
 *
 * @param[in] source           ��������� �� ������ �������� ���������� ������
 * @param[in] string_length    ����������� ������ �����������
 * @param[in] end_input = '\n' ������������ �������� �������, ����� ����������
 *
 * @param[out] dest            ��������� �� ������ � ������� ����� ����������� ������
 */
void strncpy_(char *dest, char *source, int string_length, char end_input = '\n');

/**
 * ����������� �����
 *
 * @param[in] append           ��������� �� ������ �������� ���������� ������
 * @param[in] end_input = '\n' ������������ �������� �������, ����� ����������
 *
 * @param[out] dest            ��������� �� ������, � ������� ����� ��������� ������
 */
void strcat_(char *dest, char *append, char end_input = '\n');

/**
 * ����������� ����� c ������������ ����� ����������� ������
 *
 * @param[in] append           ��������� �� ������ �������� ���������� ������
 * @param[in] string_length    ������������ ����� ����������� �������
 * @param[in] end_input = '\n' ������������ �������� �������, ����� ����������
 *
 * @param[out] dest            ��������� �� ������, � ������� ����� ��������� ������
 */
void strncat_(char *dest, char *append, int string_length, char end_input = '\n');

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
 * @param[in] input            ��������� �� ����� ������
 * @param[in] end_input        ������, ������� �������� ����� ����������� ������
 * @param[in] end_input = '\n' ������������ �������� �������, ����� ����������
 *
 * @param[out] dest            ��������� �� ��������� �� ������,
 *                             � ������� ����� �������� ��������� ������
 */
int getline_(FILE *input, char **dest, char end_input = '\n');

/**
 * ������ ������ �� ���������� ������ ������ � ������������ �����
 *
 * @param[in] input            ��������� �� ����� ������
 * @param[in] end_input        ������, ������� �������� ����� ����������� ������
 * @param[in] string_length    ����������� ���������� ������ ����������� ������
 * @param[in] end_input = '\n' ������������ �������� �������, ����� ����������
 *
 * @param[out] dest            ��������� �� ��������� �� ������,
 *                             � ������� ����� �������� ��������� ������
 */
int fgets_(FILE *input, char *dest, char end_input, int string_length);

int line_is_empty(char *line, char end_input = '\n');

#endif // LINES_H_INCLUDED
