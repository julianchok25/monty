#include "monty.h"
/**
 * _strtok - splits a string into tokens by delimiters
 * @str: String to split
 * @tokens: Delimiters to do the split
 * Return: pointer with the token
 */
char *_strtok(char *str, char *tokens)
{
	static char *newstr;
	int i = 0, j;

	if (str != NULL)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			for (j = 0; tokens[j] != '\0'; j++)
			{
				if (str[i] == tokens[j])
				{
					str[i] = '\0';
					newstr = str;
					return (str);
				}
			}
		}
	}
	else
	{
		if (newstr != NULL)
		{
			for (i = 0; newstr[i] != '\0'; i++)
				;
			newstr = &newstr[i + 1];
			for (i = 0; newstr[i] != '\0'; i++)
			{
				for (j = 0; tokens[j] != '\0'; j++)
				{
					if (newstr[i] == tokens[j])
					{
						newstr[i] = '\0';
						return (newstr);
					}
				}
			}
		}
	}
	return (NULL);
}
/**
 * _strcmp - compare a string adding all characters
 * @s1: String one
 * @s2: String two
 * Return: A hash
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int res = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			res = (s1[i] - s2[i]);
			break;
		}
		i++;
	}
	return (res);
}
