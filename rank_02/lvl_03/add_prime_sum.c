#include <unistd.h>

int	ft_atoi(char *str)
{
	int sign = 1;
	int result;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str =='+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str -'0';
		str++;
	}
	return (sign * result);
}

int	is_prime(int nb)
{
	int i = 2;

	if (nb <= 1)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	put_nbr(int nb)
{
	if (nb >= 10)
		put_nbr(nb / 10);
	char digit = nb % 10 + '0';
	write(1, &digit, 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	int nb = ft_atoi(argv[1]);
	int sum = 0;
	while (nb > 0)
	{
		if (is_prime(nb))
			sum += nb;
		nb--;
	}
	put_nbr(sum);
	write(1, "\n", 1);
	return (0);
}