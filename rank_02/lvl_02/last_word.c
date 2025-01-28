#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	int i = 0;
	int start = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ' && (argv[1][i + 1] >= 33 && argv[1][i + 1] <= 126))
			start = i + 1;
		i++;
	}
	while (argv[1][start] >= 33 && argv[1][start] <= 126)
	{
		write(1, &argv[1][start], 1);
		start++;
	}
	write(1, "\n", 1);
	return (0);
}