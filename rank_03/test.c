int ft_printf(const char *f, ...)
{
    va_list ap;
    int i = 0, res = 0;

    va_start(ap, f);
    while (f[i])
    {
        if (f[i] == '%')
        {
            i++;
            if (f[i] == 's' || f[i] == 'd' || f[i] == 'x')
            {
                if (f[i] == 's')
                    ft_putstr(va_arg(ap, char *), &res);
                else if (f[i] == 'd')
                    ft_putnbr(va_arg(ap, int), &res);
                else
                    ft_print_hex(va_arg(ap, int), &res);
            }
            else
                res += write(1, &f[i], 1);
        }
        else
            res += write(1, &f[i], 1);
        i++;
    }
    va_end(ap);
    return (res);
}