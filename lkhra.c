#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ptr_dest;
	const char	*ptr_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	ptr_dest = (char *)dest;
	ptr_src = (const char *)src;
	while (n > 0)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
		n--;
	}
	return (dest);
}

char	*ft_strndup(const char *s, size_t len)
{
	char	*buffer;

	if (s == NULL)
		return (NULL);
	if (len == 0)
		len = ft_strlen(s);
	buffer = (char *)malloc((len + 1) * sizeof(*s));
	if (buffer == NULL)
		return (NULL);
	buffer = ft_memcpy(buffer, s, len);
	buffer[len] = '\0';
	return (buffer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strndup(s2, 0));
	else if (s2 == NULL)
		return (ft_strndup(s1, 0));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	ft_memcpy(s, s1, len1);
	ft_memcpy(s + len1, s2, len2);
	s[len1 + len2] = '\0';
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i + 1));
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s + i + 1));
	return (NULL);
}

static char	*line_extract(char **buffer)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if (!(*buffer))
		return (NULL);
	while (*buffer && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		line = ft_strndup(*buffer, i + 1);
	else
	{
		line = ft_strndup(*buffer, 0);
		free(*buffer);
		*buffer = NULL;
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
	while (!ft_strchr(*buffer, '\n'))
	{
		temp_buffer = (char *)malloc(BUFFER_SIZE + 1);
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(temp_buffer);
			break ;
		}
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
	bytes_read = line_read(&buffer, fd);
	if (bytes_read <= 0 && buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (line_extract(&buffer));
}

int	main(void)
{
	int		fd;
	char	*toz;

	fd = open("alphabet.txt", O_RDWR);
	if (fd == -1)
		return (1);
	while ((toz = get_next_line(fd)) != NULL)
	{
		printf("%s", toz);
		free(toz);
	}
	if (toz)
		free(toz);
	close(fd);
	return (0);
}
