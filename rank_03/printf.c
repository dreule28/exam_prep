#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

static void ft_putstr(char *str, int *res)
{
    int i = 0;
    if (!str)
        str = "(null)";
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
        (*res)++;
    }
}
static void ft_putnbr(int num, int *res)
{
    char    c;
    if(num == -2147483648)
    {
        ft_putstr("-2147483648", res);
        return;
    }
    if (num < 0)
    {
        write(1, "-", 1);
        num = -num;
        (*res)++;
    }
    if(num > 9)
    {
        ft_putnbr(num / 10, res);
    }
    c = num % 10 + '0';
    write(1, &c, 1);
    (*res)++;
}
static void ft_print_hex(unsigned int num, int *res)
{
    char hex[16] = "0123456789abcdef";
    if (num > 15)
        ft_print_hex(num / 16, res);
    write(1, &hex[num % 16], 1);
    (*res)++;
}
int ft_printf(const char *format, ...)
{
    va_list arg;
    int     res = 0;
    int     i = 0;
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
            {
                write(1, &format[i], 1);
                res++;
            }
        }
        else
        {
            write(1, &format[i], 1);
            res++;
        }
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

// 48 61 6c 6c 6f