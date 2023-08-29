/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:03:04 by stunca            #+#    #+#             */
/*   Updated: 2023/08/29 17:22:18 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

size_t	ft_strlen2d(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	free2d(char **x)
{
	int	i;

	i = 0;
	while (x[i])
	{
		free(x[i]);
		i++;
	}
	free(x);
}

int	is_len_dif(t_path *data)
{
	int	i;
	int	temp;

	i = 1;
	while (data->map[i])
	{
		temp = ft_strlen(data->map[i]);
		if (temp != data->map_width)
			return (-1);
		i++;
	}
	return (0);
}

int	top_bottom_check(t_path *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
	{
		if (data->map[0][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (data->map[data->map_height - 1][i])
	{
		if (data->map[data->map_height - 1][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	left_right_check(t_path *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (data->map[i][0] != '1' || \
		data->map[i][data->map_width - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}
