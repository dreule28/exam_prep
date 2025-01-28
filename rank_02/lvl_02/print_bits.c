#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int bit_index = 8;
	unsigned char bit;

	while (bit_index--)
	{
		bit = (octet >> bit_index & 1) + '0';
		write(1, &bit, 1);
	}
}

// #include <stdio.h>
// int	main()
// {
// 	unsigned char D = 'D';

// 	printf("Die Bits des Char %c sind: ", 'D');
// 	print_bits(D);
// 	printf("\n");
// 	return (0);
// }