#include "main.h"

/**
*container - contains tokens of an input as an array
*
*@str: string to contain tokens
*
*dlim: DeLimiter
*
*Return: array of container, NULL if errror
*/

char **container(char *str, char dlim)
{
	int pos = 0, i = 0, j = 0;
	int len = strlen(str);
	char **array = (char **)malloc(sizeof(char *) * (len + 1));
	char *buf = (char *)malloc(sizeof(char) * (len + 1));


	for (; i < len + 1; pos++)
	{
		if (str[pos] != dlim && str[pos] != '\0')
		{
			buf[j] = str[pos];
			j++;
		}
		else
		{
			if (j > 0)
			{
				buf[j] = '\0';
				array[i] = malloc(sizeof(char) * (j + 1));
				strcpy(array[i], buf);
				pos++;
				i = 0;
			}
		}
	}

	array[pos] = NULL;
	free(buf);

	return (array);
}
