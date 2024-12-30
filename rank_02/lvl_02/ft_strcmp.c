
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

// int main(void)
// {
// 	char *str1 = "Hello!";
// 	char *str2 = "Hello,!";

// 	printf("OG: DIFF = %d\n", ft_strcmp(str1, str2));
// 	printf("OG: DIFF = %d\n", strcmp(str1, str2));
// }