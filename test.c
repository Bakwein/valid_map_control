/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:03:00 by stunca            #+#    #+#             */
/*   Updated: 2023/08/29 17:54:56 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

void	exit_func(char *x, t_path *data)
{
	if (x != NULL)
		printf("%s\n", x);
	free2d(data->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_path	data;

	if (argc != 2)
		printf("Wrong argc count");
	else
	{
		init_data(&data);
		data.map = read_map(argv[1]);
		data.map_width = ft_strlen(data.map[0]);
		data.map_height = ft_strlen2d(data.map);
		if (control(&data) == -1)
			exit_func("ERROR!", &data);
		player_index(&data);
		if (recursive(&data) == -1)
			exit_func("ERROR!", &data);
		else
			exit_func("MAP is OK!", &data);
	}
	return (0);
}
