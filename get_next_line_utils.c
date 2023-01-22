#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(dst);
	i = 0;
	if (len > size)
		return (ft_strlen(src) + size);
	else
	{
		while (len + i + 1 < size && src[i] != '\0')
		{
			dst[len + i] = src[i];
			i++;
		}
		dst[len + i] = '\0';
		return (len + ft_strlen(src));
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *) malloc ((len + 1) * sizeof(char));
	if (joined == NULL)
		return (joined);
	else
	{
		ft_strlcpy(joined, s1, ft_strlen(s1) + 1);
		ft_strlcat(joined, s2, len + 1);
		return (joined);
	}
}*/

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;
	char	*b;

	i = 0;
	if (!s)
		return (0);
	a = (char) c;
	b = (char *) s;
	while (b[i])
	{
		if (b[i] == a)
			return (&b[i]);
		i++;
	}
	if (b[i] == a)
		return (&b[i]);
	return (0);
}

void	*ft_calloc_gnl(size_t num, size_t size)
{
	void	*s;
	size_t	i;

	i = 0;
	s = (void *) malloc(num * size);
	if (s == NULL)
		return (0);
	else
	{
		while (i < num * size)
		{
			((char *) s)[i] = '\0';
			i++;
		}
		return (s);
	}
}