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
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	int len = nlen(nbr);
	char *new_nb;
	int is_negative = (nbr < 0);

	if (is_negative)
		len++; // Platz für das Minuszeichen
	new_nb = malloc(sizeof(char) * (len + 1));
	if (!new_nb)
		return (NULL);

	new_nb[len] = '\0'; // Null-Terminierung
	len--;

	if (is_negative)
		new_nb[0] = '-'; // Minuszeichen setzen

	while (len >= is_negative) // Start bei len >= 1, wenn negativ
	{
		new_nb[len] = ft_abs(nbr % 10) + '0';
		nbr /= 10;
		len--;
	}

	return (new_nb);
}
