/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:03:11 by stunca            #+#    #+#             */
/*   Updated: 2023/08/29 17:53:32 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_path
{
	char	**map;
	int		player_x;
	int		player_y;
	int		map_width;
	int		map_height;
}t_path;
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strdup(const char *s1);
char		*get_next_line(int fd);
char		*ft_strjoin(char const *s1, char const *s2);

char		*strndup(const char *s, size_t n);
char		**ft_split(const char *s, char c);
char		**read_map(char *path);
void		exit_func(char *x, t_path *data);

int			multi_pec(t_path *data, char x);
int			control3(t_path *data);
int			control2(t_path *data);
int			control(t_path *data);
void		init_data(t_path *data);

size_t		ft_strlen2d(char **s);
void		free2d(char **x);
int			is_len_dif(t_path *data);
int			top_bottom_check(t_path *data);
int			left_right_check(t_path *data);

void		player_index(t_path *data);
int			dif_char_control(t_path *data);
void		pathfinder_recursive1(t_path *data, int y, int x);
int			valid_coin_check(t_path *data);
int			recursive(t_path *data);

int			valid_exit_check(t_path *data);
void		print_map(char **xd);
int			is0or_c(char x);

#endif