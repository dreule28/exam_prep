#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)  // Check if exactly one argument is provided
	{
		write(1, "\n", 1);  // If not, output only a newline
		return (1);
	}
	int i = 0;
	int space = 0;
	while (argv[1][i] == ' ' || argv[1][i] == '\t')
		i++;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ' || argv[1][i] == '\t')
		{
			if (!space)
				space = 1;  // Mark that space should be inserted after the next word
		}
		else
		{
			if (space)
			{
				write(1, "   ", 3);
				space = 0;  // Reset space flag
			}
			write(1, &argv[1][i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
