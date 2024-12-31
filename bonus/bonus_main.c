#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*buffer1;
	char	*buffer2;

	fd1 = open("hello.txt", O_RDWR);
	fd2 = open("goodbye.txt", O_RDWR);

	if (fd1 == -1 || fd2 == -1)
		return (1);
	while ((buffer1 = get_next_line(fd1)) != NULL && (buffer2 = get_next_line(fd2)) != NULL)
	{
		printf("This is from hello.txt: ");
		printf("%s", buffer1);
		printf("This is from goodbye.txt: ");
		printf("%s", buffer2);
		free(buffer1);
		free(buffer2);
	}
	if (buffer1)
		free(buffer1);
	if (buffer2)
		free(buffer2);
	close(fd1);
	close(fd2);
	return (0);
}
