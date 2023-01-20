/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sung-hle <sung-hle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 05:48:25 by sung-hle          #+#    #+#             */
/*   Updated: 2023/01/17 17:25:29 by sung-hle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
besorge mir eine line, wo \n mit dabei ist <--strjoin
besorge mir eine valide zeile mit \n als abschluss
kümmere dich um den rest(?), speichere es im static superspeicher
*/
#include "get_next_line.h"

static char	*bearbeiten(char **buf)
{
	char	*line;
	char	*newbuf;
	size_t		len;
	size_t		i, j;

	i = 0;
	j = 0;

	//printf("5\n");
	len = ft_strlen(*buf);
	while ((*buf)[i] != '\0')
	{
		if ((*buf)[i] == '\n')
			break ;
		i++;
	}
	//printf("%lu\n", i);
	line = (char *)ft_calloc(1, i + 2);
	ft_strlcpy(line, *buf, i + 2);
	len = len - i;
	newbuf = *buf;
	*buf = (char *)ft_calloc(1, len + 1);
	i++;
	while (i < ft_strlen(newbuf))
	{
		(*buf)[j] = newbuf[i];
		i++;
		j++;
	}
	free(newbuf);
	//if (ft_strchr(*buf, EOF))
	//	return (*buf);
	//printf("*buf : %s\n", *buf);
	//printf("line : %s\n", line);
	return (line);
}

static char	*gnl_join(char *a, char *b)
{
	char	*joined;
	size_t	len;

	//printf("4,1\n");
	len = ft_strlen(a) + ft_strlen(b);
	joined = (char *)ft_calloc(1, ft_strlen(a) + BUFFER_SIZE + 1);
	if (joined == NULL)
		return (joined);
	ft_strlcpy(joined, a, ft_strlen(a) + 1);
	ft_strlcat(joined, b, len + 1);
	//printf("joined : %s\n", joined);
	return (joined);
}

static char	*get_line_with_n(int fd, char **buf)
{
	int		go;
	char	*tmp;
	char 	*joined;
	ssize_t		knall;

	go = 1;
	if (ft_strchr(*buf, '\n'))
		return (*buf);
	while (go)
	{
		//if (ft_strchr(*buf, '\n'))
		//	break ;
	//	printf("1\n");
		tmp = (char *)ft_calloc(1, BUFFER_SIZE + 1);
		if (tmp == NULL)
			return (tmp);
		//printf("2\n");
		knall = read(fd, tmp, BUFFER_SIZE);
		//printf("3\n");
		if (ft_strchr(tmp, '\n') || ft_strchr(tmp, EOF))
			go = 0;
		joined = gnl_join(*buf, tmp);
		if (joined == NULL)
			return (joined);
		*buf = joined;
		free(joined);
		//*buf = gnl_join(*buf, tmp);
		//printf("*buf : %s\n", *buf);
		if (!tmp)
			return (0);
		free(tmp);
		//printf("4\n");
		if (knall == 0)
			return (0);
	}
	return (*buf);
}

char    *get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (!buf)
		buf = "";
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return NULL;
	line = get_line_with_n(fd, &buf);
	//printf("6\n");
	//printf("line gnl : %s\n", line);
	//if (line == NULL)
		//return (0);
	//printf("7\n");
	line = bearbeiten(&buf);
	//printf("8\n");
	if (line == NULL)
		return (0);
	//printf("buf : %s\n", buf);
	//printf("line : %s\n", line);
	return (line);
}


