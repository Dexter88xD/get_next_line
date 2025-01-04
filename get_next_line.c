/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:03:49 by sohamdan          #+#    #+#             */
/*   Updated: 2025/01/04 22:56:52 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*line_extract(char **buffer)
{
	char	*line;
	char	*temp;
	size_t	i;

	i = 0;
	line = NULL;
	if (!(*buffer))
		return (NULL);
	while ((*buffer)[i] != '\0' && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
	{
		line = ft_strndup(*buffer, i + 1);
		temp = ft_strndup(*buffer + i + 1, 0);
		free(*buffer);
		*buffer = temp;
	}
	else
	{
		line = ft_strndup(*buffer, 0);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

static char	*join_buffer(char **temp_buffer, char **buffer, char *temp)
{
	if (!*buffer)
		temp = ft_strndup("", 0);
	else
	{
		temp = ft_strndup(*buffer, 0);
		free(*buffer);
	}
	if (!temp)
		return (NULL);
	*buffer = ft_strjoin(temp, *temp_buffer);
	free(*temp_buffer);
	return (temp);
}

ssize_t	line_read(char **buffer, int fd)
{
	char	*temp;
	char	*temp_buffer;
	ssize_t	bytes_read;

	bytes_read = 0;
	while (!ft_strchr(*buffer, '\n'))
	{
		temp_buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
		if (!temp_buffer)
			return (-1);
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(temp_buffer);
			break ;
		}
		temp_buffer[bytes_read] = '\0';
		temp = join_buffer(&temp_buffer, buffer, temp);
		if (!temp)
			return (-1);
		free(temp);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	ssize_t		bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = NULL;
	bytes_read = line_read(&buffer, fd);
	if (bytes_read == -1)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}	
	else if (bytes_read <= 0 && (!buffer || buffer[0] == '\0'))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = line_extract(&buffer);
	return (line);
}
