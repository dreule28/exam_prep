#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\n");
		return (1);
	}
	int i = 1;
	int first = 1;
	int nb = atoi(argv[1]);
	if (nb == 1)
		printf("1");
	while (nb > 1)
	{
		if (nb % ++i == 0 )
		{
			if (!first)
				printf("*");
			printf("%d", i);
			first = 0;
			nb = nb / i;
			i = 1;
		}
	}
	printf("\n");
	return (0);
}