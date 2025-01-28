#include <stdlib.h>

char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = 0;

	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	**ft_split(char *str)
{
	int i = 0;
	int ws = 0;
	int wc = 0;
	int tw = 0;

	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			tw++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	char **word_array = (char **)malloc(sizeof(char *) * (tw + 1));
	if (!word_array)
		return (NULL);
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		ws = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > ws)
		{
			word_array[wc] = (char *)malloc(sizeof(char) * ((i - ws) + 1));
			if (!word_array)
				return (NULL);
			ft_strncpy(word_array[wc++], &str[ws], i - ws);
		}
	}
	word_array[wc] = NULL;
	return (word_array);
}