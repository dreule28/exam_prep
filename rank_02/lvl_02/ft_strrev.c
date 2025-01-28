
char	*ft_strrev(char *str)
{
	int i = 0;
	int j;
	char temp;

	while (str[i])
		i++;
	j = 0;
	i = i - 1;
	while (i > j)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		j++;
		i--;
	}
	return (str);
}

// #include <stdio.h>

// int	main()
// {
// 	char str[] = "Hello, World";

// 	printf("Res --- > %s\n", ft_strrev(str));
// 	return (0);
// }