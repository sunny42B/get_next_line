#include "get_next_line.h"

int main()
{
	int		fd;
	char	*result;
	int		i = 0;

	fd = open("testfile.txt", O_RDONLY);
	if (fd <= 0)
		return (1);
	while (i < 5)
	{
		result = get_next_line(fd);
		printf("%s", result);
		free(result);
		i++;
	}
	close(fd);
	return (0);
}