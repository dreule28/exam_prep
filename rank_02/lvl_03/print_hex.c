#include <unistd.h>

int	ft_atoi(char *str)
{
	int result;
	int sign = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

void	print_hex(int nb)
{
	char *base = "0123456789abcdef";
	if (nb >= 16)
		print_hex(nb / 16);
	write(1, &base[nb % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
	
}
