#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char *dst;
	int i = 0;

	dst = malloc(sizeof(src) + 1);
	if (!dst)
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}