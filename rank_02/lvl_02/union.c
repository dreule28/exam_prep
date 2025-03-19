#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	int i = 0;
	unsigned char seen[256] = {0};
	while (argv[1][i])
	{
		if (!seen[((unsigned char)argv[1][i])])
			write(1, &argv[1][i], 1);
		seen[(unsigned char)argv[1][i]] = 1;
		i++;
	}
	while (argv[2][i])
	{
		if (!seen[((unsigned char)argv[2][i])])
			write(1, &argv[2][i], 1);
		seen[(unsigned char)argv[2][i]] = 1;
		i++;
	}
	write(1, "\n", 1);
	return (0);
}