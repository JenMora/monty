#include "monty.h"

char **strTow(char *str, char *delimeter);
int is_delim(char ch, char *delimeter);
int get_word_length(char *str, char *delimeter);
int get_word_count(char *str, char *delimeter);
char *get_next_word(char *str, char *delimeter);

/**
 * strTow - from string to words
 * @str: the string
 * @delimeter: does it have a seperator?
 * Return: pointers to the seperate words
 */
char **strTow(char *str, char *delimeter)
{
	char **word_str = NULL;
	int count, len, n = 0, i = 0;

	if (str == NULL || !*str)
		return (NULL);

	count = countWords(str, delimeter);

	if (count == 0)
		return (NULL);

	while (i < count)
	{
		len = lenWords(str, delimeter);

		if (is_delim(*str, delimeter))
		{
			str = wordNext(str, delimeter);
		}

		word_str[i] = malloc((len + 1) * sizeof(char));
		if (word_str[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(word_str[i]);
			}
			free(word_str);
			return (NULL);
		}
		while (n < len)
		{
			word_str[i][n] = *(str + n);
			n++;
		}
		word_str[i][n] = '\0';
		str = wordNext(str, delimeter);

		i++;
	}
	word_str[i] = NULL;
	return (word_str);
}

/**
 * isdelim - does the string have a delim?
 * @ch: the characyer delim
 * @delimeter: the delim
 * Return: 1 or 0
 */
int is_delim(char ch, char *delimeter)
{
	int i = 0;

	while (delimeter[i])
	{
		if (delimeter[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * lenWords - gets string length
 * @str: the string
 * @delimeter: delimeter
 * Return: len
 */
int lenWords(char *str, char *delimeter)
{
	int lenW = 0, rem = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delimeter))
			rem = 1;
		else if (rem)
		{
			lenW++;
		}
		if (lenW > 0 && is_delim(str[i], delimeter))
		{
			break;
		}
		i++;
	}
	return (lenW);
}

/**
 * countWords - counts words
 * @str: the string
 * @delimeter: delimeter
 * Return: count
 */
int countWords(char *str, char *delimeter)
{
	int countW = 0, rem = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delimeter))
			rem = 1;
		else if (rem)
		{
			rem = 0;
			countW++;
		}
		i++;
	}
	return (countW);
}

/**
 * wordNext - gets the folowing word in string
 * @str: the string
 * @delimeter: delimeter
 * Return: address of next file
 */
char *wordNext(char *str, char *delimeter)
{
	int rem = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delimeter))
			rem = 1;
		else if (rem)
			break;
		i++;
	}
	return (str + i);
}
