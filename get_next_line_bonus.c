/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:45:21 by wlanette          #+#    #+#             */
/*   Updated: 2021/10/28 03:47:40 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_line(char *read_file)
{
	int		index;
	char	*buffer;

	index = 0;
	if (!read_file || read_file[index] == '\0')
		return (NULL);
	while (read_file[index] && read_file[index] != '\n')
		index++;
	buffer = (char *)malloc((index + 2) * sizeof(char));
	if (!buffer)
		return (NULL);
	index = 0;
	while (read_file[index] && read_file[index] != '\n')
	{
		buffer[index] = read_file[index];
		index++;
	}
	if (read_file[index] == '\n')
	{
		buffer[index] = read_file[index];
		index++;
	}
	buffer[index] = '\0';
	return (buffer);
}

static char	*ft_read_file_remaind(char *read_file)
{
	int		index;
	int		jndex;
	char	*buffer;

	index = 0;
	while (read_file[index] && read_file[index] != '\n')
		index++;
	if (!read_file[index])
	{
		free(read_file);
		return (NULL);
	}
	buffer = (char *)malloc((ft_strlen(read_file) - index + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	index++;
	jndex = 0;
	while (read_file[index])
		buffer[jndex++] = read_file[index++];
	buffer[jndex] = '\0';
	free(read_file);
	return (buffer);
}

static char	*ft_read_from_file(char fd, char *read_file)
{
	char	*buffer;
	int		byte;
	char	*temp;

	byte = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(read_file, '\n') && byte != 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte] = '\0';
		if (!read_file)
			read_file = ft_strnew(0);
		temp = read_file;
		read_file = ft_strjoin(read_file, buffer);
		free(temp);
	}
	free(buffer);
	return (read_file);
}

char	*get_next_line(int fd)
{
	char				*line;
	static char			*read_file[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_file[fd] = ft_read_from_file(fd, read_file[fd]);
	if (!read_file[fd])
		return (NULL);
	line = ft_get_line(read_file[fd]);
	read_file[fd] = ft_read_file_remaind(read_file[fd]);
	return (line);
}
