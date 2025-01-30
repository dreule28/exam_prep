#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)  // Prüft, ob genau ein Argument übergeben wurde
	{
		write(1, "\n", 1);
		return (0);
	}
	int i = 0;
	while (argv[1][i] == ' ' || argv[1][i] == '\t')
		i++;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ' || argv[1][i] == '\t')
		{
			while (argv[1][i] == ' ' || argv[1][i] == '\t')
				i++;
			if (argv[1][i])
				write(1, " ", 1);
		}
		else
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
