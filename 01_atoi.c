#include "monty.h"

/**
 * getInteger - gets char converts to int
 * @num: num being changed
 * Return: pointer to new string
 */
void lowerBuff(unsigned int num, unsigned int _lower,
		char *buff, int buff_size);
char *getInteger(int num);
unsigned int _abs(int);
int lenthOfBaseNum(unsigned int num, unsigned int _lower);

char *getInteger(int num)
{
	unsigned int tmp;
	int length = 0;
	long num_l = 0;
	char *result;

	tmp = _abs(num);
	length = lenthOfBaseNum(tmp, 10);

	if (num < 0 || num_l < 0)
		length++;
	result = malloc(length + 1);
	if (!result)
		return (NULL);

	lowerBuff(tmp, 10, result, length);
	if (num < 0 || num_l < 0)
		result[0] = '-';
				
	return (result);

}

/**
 * _abs - gets absolute valur
 * @i: the integer whose absolute value is to be got
 */

unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * lenthOfBaseNum - length of buff
 * @num: parameter
 * @_lower: the base
 * Return: int
 */

int lenthOfBaseNum(unsigned int num, unsigned int _lower)
{
	int length = 1;

	while (num > _lower - 1)
	{
		length++;
		num /= _lower;
	}
	return (length);
}

/**
 * lowerBuff - gives buff the right nums
 * @num: number parameter
 * @_lower: the base
 * @buff: buffer
 * @buff_size: bytes
 */
void lowerBuff(unsigned int num, unsigned int _lower,
		char *buff, int buff_size)
{
	int carry;
	int i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		carry = num % _lower;
		if (carry > 9)
			buff[i] = carry + 87;
		else
			buff[i] = carry + '0';
		num /= _lower;
		i--;
	}

}
