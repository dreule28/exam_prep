#include "get_next_line.h"

char	*ft_strdup(char *str)
{
	char *dup;
	int i = 0;

	while (str[i])
		i++;
	dup = malloc(i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] == '\0';
	return (dup);
}

char	*get_next_line(int fd)
{
	static int bytes_read = 0;
	static int bytes_given = 0;
	static char buffer[BUFFER_SIZE];
	char	line[1000003];

	if (fc <)
}