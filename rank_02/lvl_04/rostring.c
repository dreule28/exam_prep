#include <unistd.h>

void write_word(char *start, char *end)
{
	while (start < end)
	{
		write(1, start, 1);
		start++;
	}
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		char *str = argv[1];       // Zeiger auf den Eingabestring
		char *first_start = NULL; // Start des ersten Wortes
		char *first_end = NULL;   // Ende des ersten Wortes

		while (*str == ' ' || *str == '\t')
			str++;
		first_start = str;
		while (*str && *str != ' ' && *str != '\t')
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
				if (*str) // Falls noch ein Wort folgt, füge ein Leerzeichen hinzu
					write(1, " ", 1);
			}
			else
			{
				write(1, str, 1); // Schreibe das aktuelle Zeichen
				str++;
			}
		}
		if (first_start != first_end)
			write(1, " ", 1);
		write_word(first_start, first_end);
	}
	write(1, "\n", 1);
	return 0;
}
