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
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	len = ft_strlen(*buf);
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
			break ;
		i++;
	}
	line = (char *)ft_calloc_gnl(1, i + 2);// +2 fuer \n und \0
	ft_strlcpy(line, *buf, i + 2);
	if (len == i)//der gesamte buf wurde in line kopiert
	{
		free(*buf);
		*buf = NULL;
		//free(*buf);
		return (line);
	}
	len = len - i;//(hier ist \n noch mit dabei)
	newbuf = *buf;
	*buf = (char *)ft_calloc_gnl(1, len);
	i++;//\n ueberspringen
	while (i < ft_strlen(newbuf))
	{
		(*buf)[j] = newbuf[i];
		i++;
		j++;
	}
	free(newbuf);
	return (line);
}

static char	*gnl_join(char *a, char *b)
{
	char	*joined;
	size_t	len;

	len = ft_strlen(a) + ft_strlen(b);
	joined = (char *)ft_calloc_gnl(1, ft_strlen(a) + BUFFER_SIZE + 1);
	if (joined == NULL)
		return (joined);
	ft_strlcpy(joined, a, ft_strlen(a) + 1);
	ft_strlcat(joined, b, len + 1);
	//if (!a)
	//	free(a);
	//free(b);
	return (joined);
}

static char	*get_line_with_n(int fd, char **buf)
{
	int		go;
	char	*tmp;
	char	*joined;
	ssize_t		readreturn;

	go = 1;
	if (ft_strchr(*buf, '\n'))
		return (*buf);
	while (go)
	{
		tmp = (char *)ft_calloc_gnl(1, BUFFER_SIZE + 1);
		if (tmp == NULL)
			return (tmp);
		readreturn = read(fd, tmp, BUFFER_SIZE);
		if (ft_strchr(tmp, '\n'))
			go = 0;
		joined = gnl_join(*buf, tmp);
		free(tmp);
		free(*buf);
		if (joined == NULL)
			return (joined);
		*buf = joined;
		//free(joined);
		if (readreturn > 0 && readreturn < BUFFER_SIZE)//equivalent to has reached the eof
			return (*buf);
		if (readreturn <= 0)//nothing read or error
			return (0);
	}
	return (*buf);
}

char    *get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (!buf)
		buf = (char *)ft_calloc_gnl(1, 1);
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return NULL;
	line = get_line_with_n(fd, &buf);
	if (line == NULL)
		return (0);
	line = bearbeiten(&buf);
	if (line == NULL)
		return (0);
	return (line);
}


