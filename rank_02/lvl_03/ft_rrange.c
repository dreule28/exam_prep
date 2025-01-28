#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int *range;
	int i = 0;
	int step = 1;
	int n = end - start;

	if (end > start)
		step = -1;
	n++;

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