#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	int		s1len;
	int		s2len;
	size_t	index;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	buffer = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	index = 0;
	while (*s1 != '\0')
	{
		buffer[index] = *s1++;
		index++;
	}
	while (*s2 != '\0')
	{
		buffer[index] = *s2++;
		index++;
	}
	buffer[index] = '\0';
	return (buffer);
}

char	*ft_strdup(const char *s1)
{
	char			*buffer;
	unsigned int	strlen;
	unsigned int	index;

	strlen = ft_strlen(s1);
	buffer = malloc((strlen + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	index = 0;
	while (*s1 != '\0')
		buffer[index++] = *s1++;
	buffer[index] = '\0';
	return (buffer);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	char		*str;
	size_t		index;
	size_t		str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start > str_len)
		return (ft_strdup(""));
	if (str_len < len)
		len = str_len - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	index = 0;
	str = (char *)(s + start);
	while (*str != '\0' && len--)
		substr[index++] = *str++;
	substr[index] = '\0';
	return (substr);
}