
int	ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	while ((s1[i] && s2[j]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	char str1[] = "hello World";
// 	char str2[] = "hello world";

// 	printf("MY: %d\n", ft_strcmp(str1, str2));
// 	printf("OG: %d\n", strcmp(str1, str2));
// 	return (0);
// }