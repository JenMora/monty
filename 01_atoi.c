#include "monty.h"

void c35_base_buffer(unsigned int num, unsigned int base,
		char *buff, int buffer_size);
char *c34_get_integer(int num);
unsigned int c36_make_abs(int);
int c37_length_of_base(unsigned int num, unsigned int base);

/**
 * c34_get_integer - gets char converts to int
 * @num: num being changed
 * Return: pointer to new string
 */

/*MY CODES*/

char *c34_get_integer(int num)
{
	unsigned int c38_tmp;
	int length = 0;
	long base_num = 0;
	char *string_copy;

	c38_tmp = c36_make_abs(num);
	length = c37_length_of_base(c38_tmp, 10);
	if (num < 0 || base_num < 0)
		length++;
	string_copy = malloc(length + 1);
	if (!string_copy)
		return (NULL);
	c35_base_buffer(c38_tmp, 10, string_copy, length);
	if (num < 0 || base_num < 0)
		string_copy[0] = '-';

	return (string_copy);
}
/**
 * c36_make_abs - gets absolute valur
 * @i: the integer whose absolute value is to be got
 * Return: value
 */

unsigned int c36_make_abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * c37_length_of_base - length of buff
 * @num: parameter
 * @base: the base
 * Return: int
 */

int c37_length_of_base(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * c35_base_buffer - gives buff the right nums
 * @num: number parameter
 * @base: the base
 * @buff: buffer
 * @buffer_size: bytes
 */

void c35_base_buffer(unsigned int num, unsigned int base,
			char *buff, int buffer_size)
{
	int carry_forward, i = buffer_size - 1;

	buff[buffer_size] = '\0';
	while (i >= 0)
	{
		carry_forward = num % base;
		if (carry_forward > 9)
			buff[i] = carry_forward + 87;
		else
			buff[i] = carry_forward + '0';
		num /= base;
		i--;
	}

}
