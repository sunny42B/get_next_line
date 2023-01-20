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

	len = ft_strlen(*buf);
	//printf("len: %lu\n", len);

	while ((*buf)[i] != '\0')
	{
		//printf("%c\n", (*buf)[i]);
		if ((*buf)[i] == '\n')
			break ;
		i++;
		//printf("%c\n", (*buf)[1]);
	}
	//printf("i: %lu, len: %lu\n", i, len);
	line = (char *)ft_calloc(1, i + 1);
	ft_strlcpy(line, *buf, i + 1);//line sollte hier fertig sein
	len = len - i;
	//printf("line: %s\n", line);
	newbuf = *buf;
	*buf = (char *)ft_calloc(1, len + 1);
	i++;
	while (i < ft_strlen(newbuf))
	{
		(*buf)[j] = newbuf[i];
		i++;
		j++;
	}
	//ft_strlcpy(*buf, ft_strchr(newbuf, '\n'), len + 1);
	//printf("ft_strchr: %s\n", ft_strchr(newbuf, '\n'));
	//printf("*buf: %s\n", *buf);
	free(newbuf);
	return (line);
}

static char	*gnl_join(char *a, char *b)
{
	char	*joined;
	size_t	len;

	len = ft_strlen(a) + ft_strlen(b);
	joined = (char *)ft_calloc(1, ft_strlen(a) + BUFFER_SIZE + 1);
	if (joined == NULL)
		return (joined);
	ft_strlcpy(joined, a, ft_strlen(a) + 1);
	ft_strlcat(joined, b, len + 1);
	return (joined);
}

static char	*get_line_with_n(int fd, char **buf)
{
	int		go;
	char	*tmp;

	go = 1;
	while (go)
	{
		tmp = (char *)ft_calloc(1, BUFFER_SIZE + 1);
		if (tmp == NULL)
			return (tmp);
		read(fd, tmp, BUFFER_SIZE);
		if (ft_strchr(tmp, '\n'))
			go = 0;
		*buf = gnl_join(*buf, tmp);
		free(tmp);
		//printf("joined in loop: %s\n", *buf);
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
	get_line_with_n(fd, &buf);
	//printf("vor bearbeiten: %s\n", buf);
	line = bearbeiten(&buf);
	//printf("nach bearbeiten buf: %s\n", buf);
	//printf("nach bearbeiten buffer: %s\n", line);
	return (line);
}


