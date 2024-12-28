/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:03:49 by sohamdan          #+#    #+#             */
/*   Updated: 2024/12/28 23:17:18 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	file_reading(int fd, char *buffer)
{
	int	i;
	int	read_value;

	i = 0;
	read_value = read(fd, buffer, BUFFER_SIZE);
	if (read_value < 0)
		return (-1);
	if (read_value == 0)
		return (-2);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		return (0);
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*remaining_line;
	char		*buffer;
	char		*line;
	int			i;

	if (remaining_line == NULL)
		remaining_line = (char *)malloc(BUFFER_SIZE * sizeof(char));
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (free(buffer), NULL);
	i = 0;
	while (i == 0)
		i = file_reading(fd, buffer);
	if (i == -1)
		return (free(buffer), NULL);
	else if (i == -2)
		return (remaining_line);
	buffer = ft_strjoin(remaining_line, buffer);
	line = ft_strndup(buffer, i + 1);
	remaining_line = ft_strchr(buffer, '\n');
	remaining_line = ft_strndup(remaining_line, 0);
	free(buffer);
	return (line);
}

int	main(void)
{
	int		i;
	char	*buffer;

	i = open("hello.txt", O_RDWR);
	if (i == -1)
		return (1);
	buffer = get_next_line(i);
	printf("%s", buffer);
	buffer = get_next_line(i);
	printf("%s", buffer);
	free(buffer);
	return (0);
}
