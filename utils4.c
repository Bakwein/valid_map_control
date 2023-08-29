/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:03:08 by stunca            #+#    #+#             */
/*   Updated: 2023/08/29 17:43:37 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

int	valid_exit_check(t_path *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'E')
			{
				if (!(data->map[y + 1][x] == '#' \
				|| data->map[y][x + 1] == '#' \
				|| data->map[y - 1][x] == '#' \
				|| data->map[y][x - 1] == '#'))
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	print_map(char **xd)
{
	int	i;

	i = 0;
	while (xd[i])
	{
		printf("%s\n", xd[i]);
		i++;
	}
	printf("\n");
}

int	is0or_c(char x)
{
	if (x == '0' || x == 'C')
		return (1);
	return (0);
}
