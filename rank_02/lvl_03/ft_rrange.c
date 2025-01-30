#include <stdlib.h>

int	ft_abs(nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	*ft_rrange(int start, int end)
{
	int *range;
	int i = 0;
	int step = 1;
	int n = ft_abs(end - start) + 1;

	if (end > start)
		step = -1;
	range = malloc(sizeof(int) * n);
	if (!range)
		return (NULL);
	while (i < n)
	{
		range[i] = end;
		end = end + step;
		i++;
	}
	return(range);
}