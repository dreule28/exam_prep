#include <unistd.h>

void	put_nbr(int nb)
{
	char *base = "0123456789";
	if (nb >= 10)
		put_nbr(nb /10);
	write(1 ,&base[nb % 10], 1);
}

int	main()
{
	int nb = 1;
	while (nb <= 100)
	{
		if (nb % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (nb % 3 == 0)
			write(1, "fizz", 4);
		else if (nb % 5 == 0)
			write(1, "buzz", 4);
		else
			put_nbr(nb);
		nb++;
		write(1, "\n", 1);
	}
	return (0);
}