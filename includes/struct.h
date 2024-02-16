/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:59:28 by tschecro          #+#    #+#             */
/*   Updated: 2024/02/13 17:46:14 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

typedef struct s_vec2
{
	float	x;
	float	y;
}				t_vec2;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		w_w;
	int		w_h;
}				t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_img;

typedef struct s_angle
{
	float	vec_x;
	float	vec_y;
	float	rad;
}			t_angle;

typedef struct s_line
{
	int	lineheight;
	int	drawstart;
	int	drawend;
}			t_line;

typedef struct s_texture
{
	t_img	img;
	int		width;
	int		length;
}				t_texture;

typedef struct s_r_cast
{
	double	camerax;
	double	ray_dirx;
	double	ray_diry;
	int		map_x;
	int		map_y;
	double	sidedistx;
	double	sidedisty;
	double	delta_distx;
	double	delta_disty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	double	intersec_x;
	double	intersec_y;
}			t_r_cast;

typedef struct s_data
{
	int				fd;
	double			plane_x;
	double			plane_y;
	int				c_floor;
	int				c_ceiling;
	t_texture		no_texture;
	t_texture		so_texture;
	t_texture		we_texture;
	t_texture		ea_texture;
	t_mlx			mlx;
	t_img			img;
	t_angle			angle;
	int				map_start;
	int				map_height;
	int				*line_size;
	int				spawn;
	char			spawn_char;
	float			player_pos_x;
	float			player_pos_y;
	char			*path;
	char			**map;
	char			**map_copy;
	float			speed;
	float			rs;
	int				side;
}				t_data;

#endif
