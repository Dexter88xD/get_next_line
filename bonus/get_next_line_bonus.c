/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:03:49 by sohamdan          #+#    #+#             */
/*   Updated: 2024/12/31 15:29:59 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*extract_line(char *buffer)
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
		buffer = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*newline;
	char		*temp_buffer;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer[fd])
		buffer[fd] = (char *)malloc(BUFFER_SIZE);
	newline = NULL;
	buffer[fd] = ft_strchr(buffer[fd], '\n');
	while (newline == NULL)
	{
		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		temp_buffer[read_bytes] = '\0';
		buffer[fd] = ft_strjoin(buffer[fd], temp_buffer);
		newline = ft_strchr(buffer[fd], '\n');
	}
	if (read_bytes < 0 || (read_bytes == 0 && buffer[fd][0] == '\0'))
		return (NULL);
	return (extract_line(buffer[fd]));
}
