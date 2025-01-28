#include <unistd.h>

int main(int argc, char**argv)
{
	if (argc <= 1)
	{
		write(1, "\n", 1);
		return 1;
	}
	int j = 1;
	while (j < argc)
	{
		int i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] >= 'A' && argv[j][i] <= 'Z')
				argv[j][i] += 32;
			if ((argv[j][i] >= 'a' && argv[j][i] <= 'z')
					&& (argv[j][i - 1] == ' ' || argv[j][i - 1] == '\t' || argv[j][i - 1] == '\n' || argv[j][i] == argv[j][0]))
				argv[j][i] -= 32;
			write(1, &argv[j][i], 1);
			i++;
		}
		if (j < argc -1)
			write(1, "\n", 1);
		j++;
	}
	write(1, "\n", 1);
	return 0;
}