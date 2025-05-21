#include <stdio.h>
#include <unistd.h>

{
	unsigned char	reversed_bits;
	int				i;

	reversed_bits = 0;
	i = 8;
	while (i--)
	{
		reversed_bits <<= 1;
		reversed_bits |= octet & 1;
		octet >>= 1;
	}
	return (reversed_bits);
}

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	a;
	unsigned char	b;

	a = octet >> 4;
	b = octet << 4;
	return (a | b);
}

int	main(void)
{
	unsigned char	octet;

	octet = 128;
	print_bits(octet);
	write(1, "\n", 1);
	print_bits(swap_bits(octet));
	write(1, "\n", 1);
	print_bits(reverse_bits(octet));
	write(1, "\n", 1);
	return (0);
}