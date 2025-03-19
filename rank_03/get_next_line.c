#include "get_next_line.h"

//strdub// to do

char	*ft_strdup(const char *s1)
{
	char	*store;
	int		len = 0;

	while (s1[len])
		len++;
	if (!(store = malloc(len + 1)))
		return (NULL);
	store[len] = '\0';
	while (len--)
		store[len] = s1[len];
	return (store);
}

char	*get_next_line(int fd)
{
	static int bytes_read = 0;
	static int bytes_given = 0;
	static char buffer[BUFFER_SIZE];
	char line[1000000];
	int i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (1)
	{
		if (bytes_given >= bytes_read)
		{
			bytes_read = read(fd,buffer, BUFFER_SIZE);
			bytes_given = 0;
			if (bytes_read <= 0)
				break;
		}
		line[i++] = buffer[bytes_given++];
		line[i] = '\0';
		if (buffer[bytes_given - 1] == '\n')
			break;
	}
	if (i == 0)
		return(NULL);
	return(ft_strdup(line));
}

int main(void)
{
	int fd = open("get_next_line.h", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
}
