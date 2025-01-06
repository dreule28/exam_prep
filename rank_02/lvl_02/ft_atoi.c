
int	ft_atoi(const char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
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

// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>

// int main()
// {
// 	printf("My: %d\n", ft_atoi("123456"));
// 	printf("Og: %d\n", atoi("123456!"));
// 	return (0);
// }