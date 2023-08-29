/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:02:55 by stunca            #+#    #+#             */
/*   Updated: 2023/08/29 17:02:57 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c] != 0)
		c++;
	return (c);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;

	dup = (char *)malloc(ft_strlen(s1) + 1);
	if (dup == NULL)
		return (NULL);
	ft_memcpy (dup, s1, (ft_strlen(s1) + 1));
	return (dup);
}

char	*get_next_line(int fd)
{
	char	buffer;
	char	*line;
	int		rd_byte;
	int		i;

	rd_byte = 1;
	i = 0;
	line = (char *)malloc(sizeof(char) * 9999);
	buffer = 0;
	while (rd_byte > 0)
	{
		rd_byte = read(fd, &buffer, 1);
		if (rd_byte <= 0)
			break ;
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
	}
	line[i] = '\0';
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	unsigned int	i;
	unsigned int	a;

	i = 0;
	a = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (NULL);
	while (s1[i])
	{
	new[i] = s1[i];
	i++;
	}
	while (s2[a])
		new[i++] = s2[a++];
	new[i] = '\0';
	return (new);
}
