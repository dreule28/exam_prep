#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	int nb;

	if (argc != 2)
	{
		printf("\n");
		return (1);
	}
	i = 1;
	nb = atoi(argv[1]);
	if (nb == 1)
	{
		printf("1");
		return (0);
	}
	while (nb >= ++i)
	{
		if (nb % i == 0)
		{
			printf("%d", i);
			if (nb == i)
				break ;
			printf("*");
			nb /= i;
			i = 1;
		}
	}
	printf("\n");
	return (0);
}
