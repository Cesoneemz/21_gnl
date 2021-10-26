/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:45:36 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/27 00:47:09 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strjoin(char *s1, char *s2)
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
	while (*s1)
		buffer[index++] = *s1++;
	while (*s2)
		buffer[index++] = *s2++;
	buffer[index] = '\0';
	return (buffer);
}

char	*ft_strnew(size_t size)
{
	char	*buffer;

	buffer = (char *)malloc((size + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[size] = '\0';
	while (size--)
		buffer[size] = '\0';
	return (buffer);
}
