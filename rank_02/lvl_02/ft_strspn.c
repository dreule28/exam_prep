#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;
	size_t count = 0;

	while (*s)
	{
		while (accept[i] && *s != accept[i])
			i++;
		if (accept[i] == '\0')
			return (count);
		i = 0;
		count++;
		s++;
	}
	return (count);
}

int	main()
{
	printf("MY: %lu\n", ft_strspn("Hello", "Hel"));
	printf("MY: %lu\n", strspn("Hello", "Hel"));
	return (0);
}