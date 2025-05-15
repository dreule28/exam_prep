#include "get_next_line.h"

char	*ft_strdup(char *str)
{
	char	*duplicate;
	int		i = 0;

	while (str[i])
		i++;
	duplicate = malloc(i + 1);
	if (!duplicate)
		return (NULL);
	i = 0;
	while (str[i])
	{
		duplicate[i] = str[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

char	*get_next_line(int fd)
{
	static int	bytes_read = 0;
	static int	bytes_given = 0;
	static char	buffer[BUFFER_SIZE];
	char		line[1000003];
	int 		i = 0;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (1)
	{
		if (bytes_given >= bytes_read)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
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
	return (ft_strdup(line));
}


// int	main(void)
// {
// 	int fd = open("get_next_line.h", O_RDONLY);
// 	char *line;
// 	while ((line = get_next_line(fd) )!= NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }