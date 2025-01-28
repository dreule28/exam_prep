#include <stdlib.h>

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	nlen(int nb)
{
	int count = 0;

	if (nb == 0)
		return (1);
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	int len;
	char *new_nb;
	int is_negative = (nbr < 0);

	len = nlen(nbr);
	if (is_negative)
		len++;
	new_nb = malloc(sizeof(char) * (len + 1));
	if (!new_nb)
		return (NULL);
	if (is_negative)
		new_nb[0] = '-';
	new_nb[len] = '\0';
	while (len >= is_negative)
	{
		new_nb[len] = ft_abs(nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (new_nb);
}