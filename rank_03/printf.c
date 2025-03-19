#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

static void ft_putstr(char *str, int *res)
{
	if (!str)
		str = "(null)";
	while (*str)
		*res += write(1, str++, 1);
}
static void ft_putnbr(long nb, int *res)
{
	char base[16] = "0123456789";
	if (nb < 0)
	{
		write(1, "-", 1);
		(*res)++;
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10, res);
	*res += write(1, &base[nb % 10], 1);
}
static void ft_print_hex(unsigned int nb, int *res)
{
	char hex[16] = "0123456789abcdef";
	if (nb > 15)
		ft_print_hex(nb / 16, res);
	*res += write(1, &hex[nb % 16], 1);
}
int ft_printf(const char *format, ...)
{
	va_list	arg;
	int		res = 0;
	int		i = 0;
	va_start(arg, format);
	while(format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if(format[i] == 's')
				ft_putstr(va_arg(arg, char *), &res);
			else if(format[i] == 'd')
				ft_putnbr(va_arg(arg, int), &res);
			else if(format[i] == 'x')
				ft_print_hex(va_arg(arg, int), &res);
			else
				res += write(1, &format[i], 1);
		}
		else
			res += write(1, &format[i], 1);
		i++;
	}
	va_end(arg);
	return(res);
}

int main()
{
	ft_printf("MY: Basic string test\n");
	printf("OG: Basic string test\n");
	// String formats
	ft_printf("MY: String: '%s', NULL: '%s'\n", "hello", NULL);
	printf("OG: String: '%s', NULL: '%s'\n", "hello", NULL);
	// Integer formats
	ft_printf("MY: Integers: %d, %d, %d, %d\n", 0, -42, 2147483647, -2147483648);
	printf("OG: Integers: %d, %d, %d, %ld\n", 0, -42, 2147483647, -2147483648);
	// Hexadecimal formats
	ft_printf("MY: Hex: %x, %x, %x, %x\n", 0, 42, 0xDEAD, 0xFFFFFFFF);
	printf("OG: Hex: %x, %x, %x, %x\n", 0, 42, 0xDEAD, 0xFFFFFFFF);
	// Mixed formats
	ft_printf("MY: Mixed: %s %d %x\n", "test", 42, 0xABC);
	printf("OG: Mixed: %s %d %x\n", "test", 42, 0xABC);
	// Edge cases
	ft_printf("MY: Edge: %%\n");
	printf("OG: Edge: %%\n");
	// Multiple identical formats
	ft_printf("MY: Multiple: %d %d %d\n", 1, 2, 3);
	printf("OG: Multiple: %d %d %d\n", 1, 2, 3);
	// Empty string
	ft_printf("MY: Empty string: '%s'\n", "");
	printf("OG: Empty string: '%s'\n", "");
	return (0);
}
