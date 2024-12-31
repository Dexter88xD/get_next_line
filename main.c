#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open("alphabet.txt", O_RDWR);
	if (fd == -1)
		return (1);
	while ((buffer = get_next_line(fd)) != NULL)
	{
		printf("%s", buffer);
		free(buffer);
	}
	
	return (0);
}
