/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sung-hle <sung-hle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 05:48:25 by sung-hle          #+#    #+#             */
/*   Updated: 2023/01/14 10:49:48 by sung-hle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
besorge mir eine line, wo \n mit dabei ist <--strjoin
besorge mir eine valide zeile mit \n als abschluss
kümmere dich um den rest(?), speichere es im static superspeicher
*/
#include "get_next_line.h"

/*char	*get_line_with_n(int fd, char *buf)
{

}
*/
char    *get_next_line(int fd)
{
	static char	*buf;
	char		*buffer;

	if (fd <= 0 || BUFFER_SIZE <= 0)//read-error?
		return NULL;
	buf = get_line_with_n(fd, buf);
	
	return (buffer);
}

int main()
{
	int		fd;
	char	*result;
	int		i = 0;

	fd = open("file_to_open.txt", O_RDONLY);
	if (fd <= 0)
		return (1);
	while (i < 2)
	{
		result = get_next_line(fd);
		printf("%s\n", result);
		i++;
	}
	return (0);
}