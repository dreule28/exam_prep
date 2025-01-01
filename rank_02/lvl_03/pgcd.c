#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("\n");
		return (0);
	}
	int temp;
	int nbr1 = atoi(argv[1]);
	int nbr2 = atoi(argv[2]);
	if (nbr1 > 0 && nbr2 > 0)
	{
		while (nbr2 != 0)
		{
			temp = nbr2;
			nbr2 = nbr1 % nbr2;
			nbr1 = temp;
		}
		printf("%d", nbr1);
	}
	printf("\n");
	return (0);
}
