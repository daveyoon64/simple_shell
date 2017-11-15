#include "sfsh.h"

/**
 * strcmp - compare two strings
 * @s1: the first string
 * @s2: the second string
 * Return: 0 if the same, positive/negative value otherwise
 */

int _strcmp(char *s1, char *s2)
{
	int s1d, s2d;

	do {
		s1d = *s1++;
		s2d = *s2++;
		if (s1d == '\0')
			return (s1d - s2d);
	} while (s1d == s2d);

	return (s1d - s2d);
}


/**
 * _strncmp    - Checks if @s1 matches @s2 up to @length amount
 *
 * @s1:          String to be checked against @s2
 * @s2:          String used to check @s1
 * @length:      How many characters to check
 *
 * Return:       (0)                       @s1 is a match against @s2
 *               (Any number other than 0) @s1 is not a match against @s2
 */

int _strncmp(char *s1, char *s2, int length)
{
	while (length-- && *s1++ && *s2++ && (*s1 == *s2))
		;
	return (length == 0 ? 0 : *s1 - *s2);
}


/**
 * _strdup     - Makes and returns a copy of @src string
 *
 * @src:         Source string to be duplicated
 *
 * Return:       Pointer to string that is duplicate of @src
 */

char *_strdup(char *src)
{
	char *dest, *ptr;
	int i = 0;

	while (src[i])
	{
		i++;
	}

	if (!(dest = malloc(i + 1)))
	{
		printf("Memory allocate error for _strdup\n");
		return (NULL);
	}

	ptr = dest;
	while (*src)
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';

	return (dest);
}


/**
 * cmdcat     - Concatenates @dir and @file into executable format
 *
 * @dir:         Directory where @file resides
 * @file:        The program to be executed
 *
 * Return:       Concatenated string of @dir + / + @file
 */

char *cmdcat(char *dir, char *file)
{
	int dir_length = 0, file_length = 0;

//	printf("processing %s\n", dir);


	while(dir[dir_length])
	{
		dir_length++;
	}

	dir[dir_length] = '/';
	dir_length++;

	while(file[file_length])
	{
		dir[dir_length] = file[file_length];
		dir_length++;
		file_length++;
	}
	dir[dir_length] = '\0';

//	printf("dir len: %d\n", dir_length);
//	printf("returning %s\n", dir);

	return (dir);
}
