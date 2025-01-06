
char	*ft_strcpy(char *s1, char *s2)
{
	int i = 0;

	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char s1[100];
// 	char *s2 = "Hello World how are you doing";

// 	printf("MY: %s\n", ft_strcpy(s1, s2));
// 	printf("OG: %s\n", strcpy(s1, s2));
// 	return (0);
// }