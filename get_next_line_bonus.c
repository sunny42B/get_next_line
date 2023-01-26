/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sung-hle <sung-hle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 05:48:25 by sung-hle          #+#    #+#             */
/*   Updated: 2023/01/25 13:39:59 by sung-hle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*justline(char **buf, size_t *i, size_t *len)
{
	char	*line;

	*len = ft_strlen(*buf);
	while ((*buf)[++(*i)])
	{
		if ((*buf)[*i] == '\n')
			break ;
	}
	line = (char *)ft_calloc_gnl((*i) + 2);
	if (line == NULL)
		return (line);
	ft_strlcpy(line, *buf, (*i) + 2);
	if (*len == (*i))
	{
		free(*buf);
		*buf = NULL;
		return (line);
	}
	return (line);
}

static char	*bearbeiten(char **buf)
{
	char		*line;
	char		*newbuf;
	size_t		len;
	size_t		i;
	size_t		j;

	i = -1;
	j = 0;
	line = justline(buf, &i, &len);
	if (*buf == NULL)
		return (line);
	if (line == NULL)
		return (line);
	len = len - i;
	newbuf = *buf;
	*buf = (char *)ft_calloc_gnl(len);
	if (*buf == NULL)
		return (*buf);
	while (i < ft_strlen(newbuf))
		(*buf)[j++] = newbuf[1 + i++];
	free(newbuf);
	return (line);
}

static char	*gnl_join(char *a, char *b)
{
	char	*joined;
	size_t	len;
	size_t	jsize;
	size_t	i;

	i = 0;
	len = ft_strlen(a) + ft_strlen(b);
	joined = (char *)ft_calloc_gnl(ft_strlen(a) + ft_strlen(b) + 1);
	if (joined == NULL)
		return (joined);
	ft_strlcpy(joined, a, ft_strlen(a) + 1);
	jsize = ft_strlen(joined);
	while (jsize + i < len && b[i] != '\0')
	{
		joined[jsize + i] = b[i];
		i++;
	}
	joined[jsize + i] = '\0';
	free(a);
	free(b);
	return (joined);
}

static char	*get_line_with_n(int fd, char **buf)
{
	int			go;
	char		*tmp;
	char		*joined;
	ssize_t		r;

	go = 1;
	while (go)
	{
		tmp = (char *)ft_calloc_gnl(BUFFER_SIZE + 1);
		if (tmp == NULL)
			return (tmp);
		r = read(fd, tmp, BUFFER_SIZE);
		if (ft_strchr(tmp, '\n'))
			go = 0;
		joined = gnl_join(*buf, tmp);
		if (joined == NULL)
			return (joined);
		*buf = joined;
		if ((r > 0 && r < BUFFER_SIZE) || (r == 0 && ft_strlen(*buf) > 0))
			return (*buf);
		if (r <= 0)
			return (0);
	}
	return (*buf);
}

char	*get_next_line(int fd)
{
	static char	*buf[4096];
	char		*line;

	if (!(buf[fd]))
		buf[fd] = (char *)ft_calloc_gnl(1);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (freebuf(&buf[fd]));
	if (ft_strchr(buf[fd], '\n'))
		line = bearbeiten(&buf[fd]);
	else
	{
		line = get_line_with_n(fd, &buf[fd]);
		if (line == NULL)
			return (freebuf(&buf[fd]));
		line = bearbeiten(&buf[fd]);
	}
	if (line == NULL)
		return (0);
	return (line);
}
