/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:03:02 by stunca            #+#    #+#             */
/*   Updated: 2023/08/29 17:54:35 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

int	multi_pec(t_path *data, char x)
{
	int	a;
	int	b;
	int	count;

	a = 0;
	b = 0;
	count = 0;
	while (data->map[a])
	{
		b = 0;
		while (data->map[a][b])
		{
			if (data->map[a][b] == x)
				count++;
			b++;
		}
		a++;
	}
	return (count);
}

int	control3(t_path *data)
{
	int	top_bottom;
	int	left_right;

	top_bottom = top_bottom_check(data);
	if (top_bottom == -1)
	{
		printf("Map's top or bottom has char which is not 1\n");
		return (-1);
	}
	left_right = left_right_check(data);
	if (left_right == -1)
	{
		printf("Map's left side or right side has a char which is not 1\n");
		return (-1);
	}
	return (0);
}

int	control2(t_path *data)
{
	int	len_widths;
	int	num_of_coins;

	len_widths = is_len_dif(data);
	if (len_widths == -1)
	{
		printf("Map's widths' are not same\n");
		return (-1);
	}
	num_of_coins = multi_pec(data, 'C');
	if (!(num_of_coins >= 1))
	{
		printf("Coin number must be bigger than zero\n");
		return (-1);
	}
	if (control3(data) == -1)
		return (-1);
	return (0);
}

int	control(t_path *data)
{
	int	dif_char;
	int	num_of_player;
	int	num_of_exit;

	dif_char = dif_char_control(data);
	if (dif_char == -1)
	{
		printf("Map has a char which is not 1,0,C,E or P\n");
		return (-1);
	}
	num_of_player = multi_pec(data, 'P');
	num_of_exit = multi_pec(data, 'E');
	if (num_of_player != 1 || num_of_exit != 1)
	{
		printf("Multi num of player or exit!\n");
		return (-1);
	}
	if (control2(data) == -1)
		return (-1);
	return (0);
}

void	init_data(t_path *data)
{
	data->player_x = -1;
	data->player_y = -1;
}
