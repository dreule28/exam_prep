char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;

	while (*s1)
	{
		while (s2[i])
		{
			if (*s1 != s2[i])
				return ((char *)s1);
		}
		s1++;
	}
	return (s1 - s2);
}