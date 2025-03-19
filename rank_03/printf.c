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
static void ft_print_hex(unsigned int num, int *res)
{
	char hex[16] = "0123456789abcdef";
	if (num > 15)
		ft_print_hex(num / 16, res);
	*res += write(1, &hex[num % 16], 1);
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

int	main()
{
	int x = ft_printf("MY: %s ist %d lang bei %x\n", "Hallo", 5, 0x1234);
	int y = printf("OG: %s ist %d lang bei %x\n", "Hallo", 5, 0x1234);
	printf("X: %d\nY: %d\n", x, y);
	return (0);
}
