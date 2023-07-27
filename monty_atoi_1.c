#include <stdlib.h>

void monty_base_buff(unsigned int num, unsigned int base,
		       char *buff, int buff_size);
char *get_int(int num);
unsigned int monty_abs(int);
int monty_base_num_len(unsigned int num, unsigned int base);

/**
 * get_int -  A function that gets a character pointer to
 * new string containing int
 * @num: number to convert to string
 *
 * Return: character pointer to newly created string,
 * otherwise NULL if malloc fails.
 */
char *get_int(int num)
{
	unsigned int monty_temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	monty_temp = monty_abs(num);
	length = monty_base_num_len(monty_temp, 10);

	if (num < 0 || num_l < 0)
		length++; /* negative sign */
	ret = malloc(length + 1); /* create new string */
	if (!ret)
		return (NULL);

	monty_base_buff(monty_temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * monty_abs -A function that  gets the absolute value of
 * an integer in a .m file
 * @i:the integer argument parsed
 *
 * Return: unsigned integer abs rep of i
 */
unsigned int monty_abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * monty_base_num_len -A function that gets length of buffer
 * needed for an unsigned int in a .m file
 * @num: number to get length needed for
 * @base: base of number representation used by buffer
 *
 * Return: integer containing length of buffer needed (doesn't contain null bt)
 */
int monty_base_num_len(unsigned int num, unsigned int base)
{
	int len = 1;
/* This code means that all numbers contain atleast one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * monty_base_buff - A function that fills buffer with correct
 * numbers up to base 36
 * @num: number to convert to string given base
 * @base: base of number used in conversion, only works up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffer in bytes
 *
 * Return: Nothing
 */
void monty_base_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
/* return lowercase ascii val representation */
			buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}

