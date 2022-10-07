#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <gmp.h>

void file_input(char *filename);
void factors(mpz_t n);

/**
 * file_input - read from file
 * @filename: file to read from
 * Return: line
 */

void file_input(char *filename)
{
	char *line = NULL;
	mpz_t bsize = 0;
	mpz_t line_to_num;
	FILE *fp;

	if (filename == NULL)
		return;

	fp = fopen(filename, "r");
	if (fp == NULL)
		return;

	while (getline(&line, &bsize, fp) != -1)
	{
		mpz_init_set_str(line_to_num, line, 10);
		factors(line_to_num);
	}

	fclose(fp);
}


/**
 * factors - factors the nums
 * @n: number to factor
 * Return: VOID
 */

void factors(mpz_t n)
{
	mpz_t i;

	for (i = 2; i < n; i++)
	{
		if (n == ((n / i) * i))
		{
			printf("%ld=%ld*%ld\n", n, (n / i), i);
			break;
		}
	}
}

/**
 * main - main
 * @i: i
 * @av: arg
 * Return: return (0) on success
 */

int main(char **av)
{
    if (av[1] != NULL)
	   file_input(av[1]);

	return (0);
}
