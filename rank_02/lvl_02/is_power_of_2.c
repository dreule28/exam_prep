int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	return (n & (n -1)) == 0;
}

// #include <stdio.h>

// int main()
// {
// 	int n = 4;

// 	if ((!is_power_of_2(n)) == 0)
// 	{
// 		printf("The result is a power of 2!\n");
// 	}
// 	else
// 	{
// 		printf("The result is not a power of 2!\n");
// 	}
// 	return (0);
// }