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

static char	*gnl_join(char *a, char *b)
{
	char	*joined;
	size_t	len;

	//printf("in gnl_join\n");
	len = ft_strlen(a) + ft_strlen(b);
	joined = ft_calloc(1, ft_strlen(a) + BUFFER_SIZE + 1);
	if (joined == NULL)
		return (joined);
	ft_strlcpy(joined, a, ft_strlen(a) + 1);
	ft_strlcat(joined, b, len + 1);
	return (joined);
}

static char	*get_line_with_n(int fd, char *buf)
{
	int		go;
	char	*tmp;

	//printf("in gnl_n\n");
	go = 1;
	if (!buf)
	{
		free(tmp);
		tmp = "";
	}
	else
		tmp = "";
	while (go)
	{
		buf = ft_calloc(1, BUFFER_SIZE + 1);
		if (buf == NULL)
			return (buf);
		read(fd, buf, BUFFER_SIZE);
		//printf("in while %s\n", buf);
		if (ft_strchr(buf, '\n'))
			go = 0;
		//printf("in gnl_n vor tmp\n");
		tmp = gnl_join(tmp, buf);
		printf("tmp: %s\n", tmp);
	}
	//printf("in gnl_n nach while\n");
	return (buf);
}

char    *get_next_line(int fd)
{
	static char	*buf;
	char		*buffer;

	if (!buf)
		buf = NULL;
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return NULL;
	buf = get_line_with_n(fd, buf);
	buf = bearbeiten(fd, buf);
	
	return (buf);
}


