#include <unistd.h>

int	ft_atoi(char *str)
{
	int sign = 1;
	int res = 0;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (sign * res);
}

void	put_char(char c)
{
	write(1, &c, 1);
}

void	put_nbr(int nb)
{
	if (nb / 10 > 0)
		put_nbr(nb / 10);
	put_char(nb % 10 + '0');
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	int i = 1;
	int nb = ft_atoi(argv[1]);
	while (i <= 9 && nb <= 238609294)
	{
		put_nbr(i);
		write(1, " x ", 3);
		put_nbr(nb);
		write(1, " = ", 3);
		put_nbr(i * nb);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}