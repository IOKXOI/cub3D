/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by rmechety          #+#    #+#             */
/*   Updated: 2024/02/19 12:49:24 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "includes.h"
# include "struct.h"
# include "../lib/minilibx/mlx.h"
# include "../lib/42_libft/libft.h"

/* -------------------------------------------------------------------------- */
/*                                  PARSING                                   */
/* -------------------------------------------------------------------------- */
void		check_file_acces_open_file(char *map_name, t_data *data);
int			block_a_getter_textures_colors(t_data *data);
void		clear_exit_parsing(t_data *data, char *error_message);
void		block_a_checker_open_path(char *line, t_data *data,
				t_texture *texture);
uint32_t	block_a_checker_get_colors(char *line, t_data *data);
uint8_t		utils_line_is_not_map(char *line);
int			utils_skip_spaces(char *line);
int			utils_open_map(char *map_name, t_data *data);
int32_t		utils_convert_rgb_to_int(char **values_array);
char		*ft_get_textures_name(char *line);
bool		floodfill(t_data *data, int x, int y);
int			duplicate_map(t_data *data);
void		come_back_to_block_b(t_data *data, char *map_name);
bool		block_b_getter_array(t_data *data);
void		get_start_pos(t_data *data);
void		init_parsing_resources(t_data *data);
void		free_map_array(char **tab, int height);
void		free_array(char **tab);
int			ft_strlen_no_space(char *str);
void		textures_to_null(t_data *data);
void		free_line_print_error_clean(t_data *data, char *line);

/* -------------------------------------------------------------------------- */
/*                         FILE = Cub3d/srcs/hooks.c                          */
/* -------------------------------------------------------------------------- */
int			destroy(t_data *data);
int			cross_button(t_data *data);
void		init_hooks(t_data *data);
/* -------------------------------------------------------------------------- */
/*                      FILE = Cub3d/srcs/cub3d_utils.c                       */
/* -------------------------------------------------------------------------- */
int			rgb_to_int(int r, int g, int b);
void		ft_bzero(void *ptr, size_t count);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
/* -------------------------------------------------------------------------- */
/*                     FILE = Cub3d/srcs/set_background.c                     */
/* -------------------------------------------------------------------------- */
void		set_floor_and_ceiling(t_data *data);

/* -------------------------------------------------------------------------- */
/*                          FILE = Cub3d/srcs/main.c                          */
/* -------------------------------------------------------------------------- */
bool		init_mlx(t_data *data);
int			main(int ac, char **av);
int			check_buff(char *buffer, char c);
bool		check_collision(t_data *data, int x, int y);
void		casting_ray(t_data *data);
void		draw_height_line(int x, t_line	*line,
				t_data *data, t_r_cast *values);
void		free_tab(int **tab);
void		init_distance(t_data *data, t_r_cast *values);
void		up_down_hook(int keycode, t_data *data);
void		right_hook(int keycode, t_data *data);
void		left_hook(int keycode, t_data *data);
void		pan_hook(int keycode, t_data *data);
void		check_texture(char *line, t_data *data, t_texture *texture);

#endif
