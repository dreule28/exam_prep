#include "stdarg.h"
#include "unistd.h"

void	ft_putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	int i = 0;
	while (str && str[i])
	{
		*len += write(1, &str[i], 1);
		i++;
	}
}

void	print_digit(long long int nb, int base, int *len)
{
	char pool[16] = "0123456789abcdef";

	if (nb < 0)
	{
		*len += write(1, "-", 1);
		nb = (-nb);
	}
	if (nb >= base)
		print_digit(nb / base, base, len);
	*len += write(1, &pool[nb % base], 1);
}

int	ft_printf(const char *format, ... )
{
	int		i = 0;
	int		len = 0;
	va_list	arg;

	va_start(arg, format);
	while (format && format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 's' || format[i + 1] == 'd' || format[i + 1] == 'x'))
		{
			i++;
			if (format[i] == 's')
				ft_putstr((va_arg(arg, char *)), &len);
			else if (format[i] == 'd')
				print_digit((long long int)va_arg(arg, int), 10, &len);
			else if (format[i] == 'x')
				print_digit((long long int)va_arg(arg, unsigned int), 16, &len);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(arg);
	return (len);
}

#include <stdio.h>

int main(void)
{
    int ft_ret, og_ret;

    printf("===== COMPARING STRING OUTPUT =====\n");
    ft_ret = ft_printf("Test string: %s\n", "Hello, world!");
    og_ret = printf("Test string: %s\n", "Hello, world!");
    printf("Return values - ft_printf: %d, printf: %d\n\n", ft_ret, og_ret);

    printf("===== COMPARING NULL STRING =====\n");
    ft_ret = ft_printf("NULL string: %s\n", NULL);
    og_ret = printf("NULL string: %s\n", NULL);
    printf("Return values - ft_printf: %d, printf: %d\n\n", ft_ret, og_ret);

    printf("===== COMPARING DECIMAL INTEGERS =====\n");
    ft_ret = ft_printf("Positive: %d, Negative: %d\n", 42, -42);
    og_ret = printf("Positive: %d, Negative: %d\n", 42, -42);
    printf("Return values - ft_printf: %d, printf: %d\n\n", ft_ret, og_ret);

    printf("===== COMPARING LARGE NUMBERS =====\n");
    ft_ret = ft_printf("INT_MAX: %d, INT_MIN: %d\n", 2147483647, -2147483648);
    og_ret = printf("INT_MAX: %d, INT_MIN: %ld\n", 2147483647, -2147483648);
    printf("Return values - ft_printf: %d, printf: %d\n\n", ft_ret, og_ret);

    printf("===== COMPARING HEXADECIMAL =====\n");
    ft_ret = ft_printf("Hex: %x, Large hex: %x\n", 42, 0xABCDEF);
    og_ret = printf("Hex: %x, Large hex: %x\n", 42, 0xABCDEF);
    printf("Return values - ft_printf: %d, printf: %d\n\n", ft_ret, og_ret);

    printf("===== COMPARING MIXED FORMATS =====\n");
    ft_ret = ft_printf("Mixed: %s, %d, %x\n", "test", 123, 456);
    og_ret = printf("Mixed: %s, %d, %x\n", "test", 123, 456);
    printf("Return values - ft_printf: %d, printf: %d\n\n", ft_ret, og_ret);

    printf("===== COMPARING EDGE CASES =====\n");
    ft_ret = ft_printf("Percent sign: %%s\n");
    og_ret = printf("Percent sign: %%s\n");
    printf("Return values - ft_printf: %d, printf: %d\n\n", ft_ret, og_ret);

    ft_ret = ft_printf("%s\n", NULL);
    og_ret = printf("%s\n", NULL);
    printf("Empty format - ft_printf: %d, printf: %d\n", ft_ret, og_ret);

    return (0);
}