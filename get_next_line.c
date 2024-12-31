/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:03:49 by sohamdan          #+#    #+#             */
/*   Updated: 2024/12/31 16:26:30 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*line_extract(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		line = ft_strndup(buffer, i + 1);
		
		buffer = ft_strndup(ft_strchr(buffer, '\n'), 0);
	}
	else
	{
		line = ft_strndup(buffer, 0);
		free(buffer);
		buffer = NULL;
	}
	return (line);
}

int	line_read(char **buffer, int fd)
{
	char	*temp;
	char	*temp_buffer;
	int		bytes_read;

	temp = ft_strndup(ft_strchr(*buffer, '\n'), 0);
	free(*buffer);
	*buffer = temp;
	while (1)
	{
		temp_buffer = (char *)malloc(BUFFER_SIZE + 1);
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		temp_buffer[bytes_read] = '\0';
		*buffer = ft_strjoin(*buffer, temp_buffer);
		free(temp_buffer);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	bytes_read = line_read(&buffer, fd);
	if (bytes_read <= 0 && buffer[0] == '\0')
		return (NULL);
	return (line_extract(buffer));
}
