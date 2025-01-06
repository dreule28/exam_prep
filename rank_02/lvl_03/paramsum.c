#include <unistd.h>

void putnbr(int n)
{
	char digit;

	if (n >= 10)
		putnbr(n / 10);
	digit = (n %10) + '0';
	write(1, &digit, 1);
}

int	main(int argc, char *argv[])
{
	(void)argv;

	putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}
