/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:03:07 by stunca            #+#    #+#             */
/*   Updated: 2023/08/29 17:54:04 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

void	player_index(t_path *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

int	dif_char_control(t_path *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] != '0' && \
			data->map[y][x] != '1' && \
			data->map[y][x] != 'C' && \
			data->map[y][x] != 'P' && \
			data->map[y][x] != 'E')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

void	pathfinder_recursive1(t_path *data, int y, int x)
{
	print_map(data->map);
	if (data->map[y][x] != '#')
		data->map[y][x] = '#';
	if (is0or_c(data->map[y - 1][x]))
	{
		data->map[y - 1][x] = '#';
		pathfinder_recursive1(data, y - 1, x);
	}
	if (is0or_c(data->map[y][x + 1]))
	{
		data->map[y][x + 1] = '#';
		pathfinder_recursive1(data, y, x + 1);
	}
	if (is0or_c(data->map[y + 1][x]))
	{
		data->map[y + 1][x] = '#';
		pathfinder_recursive1(data, y + 1, x);
	}
	if (is0or_c(data->map[y][x - 1]))
	{
		data->map[y][x - 1] = '#';
		pathfinder_recursive1(data, y, x - 1);
	}
	return ;
}

int	valid_coin_check(t_path *data)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
			{
				count++;
			}
			x++;
		}
		y++;
	}
	return (count);
}

int	recursive(t_path *data)
{
	int	coin_control;
	int	exit_control;

	pathfinder_recursive1(data, data->player_y, data->player_x);
	coin_control = valid_coin_check(data);
	if (coin_control > 0)
	{
		printf("At least one coin is unreachable\n");
		return (-1);
	}
	exit_control = valid_exit_check(data);
	if (exit_control == -1)
	{
		printf("Exit is unreachable\n");
		return (-1);
	}
	return (0);
}
