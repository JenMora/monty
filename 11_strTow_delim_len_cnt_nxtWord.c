#include "monty.h"

char **c33_str_tow(char *str, char *c7_delimiter);
int is_delim(char ch, char *c7_delimiter);
int c43_word_length(char *str, char *c7_delimiter);
int c44_word_count(char *str, char *c7_delimiter);
char *c45_word_next(char *str, char *c7_delimiter);

/**
 * c33_str_tow - from string to words
 * @str: the string
 * @c7_delimiter: does it have a seperator?
 * Return: pointers to the seperate words
 */
char **c33_str_tow(char *str, char *c7_delimiter)
{
	char **w = NULL;
	int word_count, le_n, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	word_count = c44_word_count(str, c7_delimiter);
	if (word_count == 0)
		return (NULL);
	w = malloc((word_count + 1) * sizeof(char *));
	if (w == NULL)
		return (NULL);
	while (i < word_count)
	{
		le_n = c43_word_length(str, c7_delimiter);
		if (is_delim(*str, c7_delimiter))
		{
			str = c45_word_next(str, c7_delimiter);
		}
		w[i] = malloc((le_n + 1) * sizeof(char));
		if (w[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(w[i]);
			}
			free(w);
			return (NULL);
		}
		n = 0;
		while (n < le_n)
		{
			w[i][n] = *(str + n);
			n++;
		}
		w[i][n] = '\0';
		str = c45_word_next(str, c7_delimiter);
		i++;
	}
	w[i] = NULL;
	return (w);
}

/**
 * is_delim - does the string have a delim?
 * @ch: the characyer delim
 * @c7_delimiter: the delim
 * Return: 1 or 0
 */
int is_delim(char ch, char *c7_delimiter)
{
	int i = 0;

	while (c7_delimiter[i])
	{
		if (c7_delimiter[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * c43_word_length - gets string length
 * @str: the string
 * @c7_delimiter: delimeter
 * Return: len
 */
int c43_word_length(char *str, char *c7_delimiter)
{
	int word_length = 0, remainig = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], c7_delimiter))
			remainig = 1;
		else if (remainig)
		{
			word_length++;
		}
		if (word_length > 0 && is_delim(str[i], c7_delimiter))
			break;
		i++;
	}
	return (word_length);
}

/**
 * c44_word_count - counts words
 * @str: the string
 * @c7_delimiter: delimeter
 * Return: count
 */
int c44_word_count(char *str, char *c7_delimiter)
{
	int wordcount = 0, words_left = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], c7_delimiter))
			words_left = 1;
		else if (words_left)
		{
			words_left = 0;
			wordcount++;
		}
		i++;
	}
	return (wordcount);
}

/**
 * c45_word_next - gets the folowing word in string
 * @str: the string
 * @c7_delimiter: delimeter
 * Return: address of next file
 */
char *c45_word_next(char *str, char *c7_delimiter)
{
	int words_left = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], c7_delimiter))
			words_left = 1;
		else if (words_left)
			break;
		i++;
	}
	return (str + i);
}
