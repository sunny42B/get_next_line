#include "get_next_line.h"

int main()
{
	int		fd;
	char	*result;
	int		i = 0;

	fd = open("testfile.txt", O_RDONLY);
	if (fd <= 0)
		return (1);
	while (i < 12)
	{
		result = get_next_line(fd);
		printf("main: %s", result);
		free(result);
		i++;
	}
	close(fd);


	/*static char *test;
	//test = "abcde";
	printf("%d", !test);*/
	return (0);
}