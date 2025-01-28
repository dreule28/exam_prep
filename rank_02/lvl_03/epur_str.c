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

	// Skip leading spaces/tabs
	while (argv[1][i] == ' ' || argv[1][i] == '\t')
		i++;

	// Process the string
	while (argv[1][i])
	{
		// Check if the current character is a space/tab
		if (argv[1][i] == ' ' || argv[1][i] == '\t')
		{
			// Only insert spaces if not already inserted between words
			if (!space)
			{
				space = 1;  // Mark that space should be inserted after the next word
			}
		}
		else
		{
			// If a space is flagged, insert three spaces before the word
			if (space)
			{
				write(1, "   ", 3);
				space = 0;  // Reset space flag
			}
			// Write the current word (character by character)
			write(1, &argv[1][i], 1);
		}
		i++;
	}

	// End the output with a newline
	write(1, "\n", 1);
	return (0);
}
