char	*ft_strdup(const char *s1)
{
	char		*store;
	size_t		i;
	size_t		len;
	const char	*temp;

	i = 0;
	len = 0;
	temp = s1;
	while (*temp != '\0')
	{
		temp++;
		len++;
	}
	store = malloc(len + 1);
	if (!store)
		return (NULL);
	while (s1[i] != '\0')
	{
		store[i] = s1[i];
		i++;
	}
	store[i] = '\0';
	return (store);
}



char	*get_next_line(int fd)
{
	static int bytes_read = 0;
	static int bytes_given = 0;
	static char buffer[BUFFER_SIZE];
	char line[1000003];
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
	return(strdup(line));
}


