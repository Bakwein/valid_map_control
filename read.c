/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:02:58 by stunca            #+#    #+#             */
/*   Updated: 2023/08/29 17:39:20 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

static int	count(const char *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 1;
	if (!s)
		return (0);
	while (s[i++])
	{
		if (s[i] == c)
			count++;
	}
	return (count);
}

char	*strndup(const char *s, size_t n)
{
	char			*str;
	unsigned int	i;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == NULL || !s || !str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	d;
	char			**table;

	a = 0;
	d = 0;
	table = malloc((count(s, c) + 1) * sizeof * table);
	if (table == NULL || !s)
		return (NULL);
	while (s[a])
	{
		while (s[a] == c)
			a++;
		b = a;
		while (s[a] && s[a] != c)
			a++;
		if (b < a)
			table[d++] = strndup(s + b, a - b);
	}
	table[d] = NULL;
	return (table);
}

char	**read_map(char *path)
{
	int		fd;
	char	*line;
	char	*holder_map;
	char	*holder;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	holder_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = holder_map;
		holder_map = ft_strjoin(holder, line);
		free(line);
		free(holder);
	}
	map = ft_split(holder_map, '\n');
	free(holder_map);
	close(fd);
	return (map);
}
