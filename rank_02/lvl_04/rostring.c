#include <unistd.h>

void	write_word(char *start, char *end)
{
	while (start < end)
	{
		write(1, start, 1);
		start++;
	}
}

int	main(int argc, char** argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	char *str = argv[1];
	char *first_start;
	char *first_end;
	int words_written = 0;

	while (*str == ' ' || *str == '\t')
		str++;
	first_start = str;
	while (*str && (*str != ' ' && *str != '\t'))
		str++;
	first_end = str;
	while (*str == ' ' || *str == '\t')
		str++;
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
		{
			while (*str == ' ' || *str == '\t')
				str++;
			if (*str)
				write(1, " ", 1);
		}
		else
		{
			write(1, str, 1);
			str++;
			words_written = 1;
		}
	}
	if (first_start != first_end)
	{
		if (words_written)
			write(1, " ", 1);
		write_word(first_start, first_end);
	}
	write(1, "\n", 1);
	return (0);
}