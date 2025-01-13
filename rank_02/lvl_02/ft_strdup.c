#include <stdlib.h>

char *ft_strdup(char *src)
{
	int i = 0;
	int len = 0;
	char *strcpy;

	while (src[len])
		len++;
	strcpy = malloc(sizeof(*strcpy) * (len + 1));
	if (!strcpy)
		return (NULL);
	while (src[i])
	{
		strcpy[i] = src[i];
		i++;
	}
	strcpy[i] = '\0';
	return (strcpy);
}