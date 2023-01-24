#include "get_next_line.h"

int main()
{
	int		fd;
	char	*result;
	int		i = 0;

	//fd = open("testfile.txt", O_RDONLY);
	//fd = open("./files/41_no_nl", O_RDONLY);
	//fd = open("./files/big_line_no_nl", O_RDONLY);
	//fd = open("./files/big_line_with_nl", O_RDONLY);
	fd = open("./files/multiple_line_no_nl", O_RDONLY);
	//fd = open("./files/nl", O_RDONLY);
	//fd = open("./files/multiple_nlx5", O_RDONLY);
	//fd = open("./files/alternate_line_nl_with_nl", O_RDONLY);
	if (fd <= 0)
		return (1);
	while (i < 6)
	{
		result = get_next_line(fd);
	
		printf("main: %s", result);
		free(result);
		i++;
	}
	close(fd);


	/*//static char *test;
	char *test = "\0";
	printf("%d", !test);*/
	return (0);
}