#include <stdlib.h>

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	*ft_range(int start, int end)
{
	int i = 0;
	int len = ft_abs(end - start) + 1;
	int *res = malloc(sizeof(int) * len);
	if (!res)
		return (NULL);

	while (len > i )
	{
		if (end > start)
		{
			res[i] = start;
			start++;
			i++;
		}
		else
		{
			res[i] = start;
			start--;
			i++;
		}
	}
	return (res);
}