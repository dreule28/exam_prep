
#include <stdlib.h>

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	nlen(int nb)
{
	int len = 0;

	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char *new_nb;
	int len = nlen(nbr);
	int is_negative = (nbr < 0);

	if (is_negative)
		len++;
	new_nb = malloc(sizeof(char) * (len + 1));
	if (!new_nb)
		return (NULL);
	if (is_negative)
		new_nb[0] = '-';
	new_nb[len] = '\0';
	while (len > is_negative)
	{
		new_nb[--len] = ft_abs(nbr % 10) + '0';
		nbr /= 10;
	}
	return (new_nb);
}
