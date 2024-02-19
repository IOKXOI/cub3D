/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:05:41 by tschecro          #+#    #+#             */
/*   Updated: 2024/02/19 12:42:35 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "cub3d.h"
#include "struct.h"

void	init_line(t_line *line, t_r_cast *values, t_data *data)
{
	line->lineheight = (int)(data->mlx.w_h / values->perpwalldist);
	line->drawstart = -line->lineheight / 2 + data->mlx.w_h / 2;
	if (line->drawstart < 0)
		line->drawstart = 0;
	line->drawend = line->lineheight / 2 + data->mlx.w_h / 2;
	if (line->drawend >= data->mlx.w_h)
		line->drawend = data->mlx.w_h - 1;
}

void	init_var(t_r_cast *values, t_data *data, int x, int w)
{	
	values->camerax = 2 * x / (double)w - 1;
	values->ray_dirx = data->angle.vec_x + data->plane_x * values->camerax;
	values->ray_diry = data->angle.vec_y + data->plane_y * values->camerax;
	if (!values->ray_dirx)
		values->delta_distx = 1e30;
	else
		values->delta_distx = fabs(1 / values->ray_dirx);
	if (!values->ray_diry)
		values->delta_disty = 1e30;
	else
		values->delta_disty = fabs(1 / values->ray_diry);
	values->map_x = (int)data->player_pos_x;
	values->map_y = (int)data->player_pos_y;
	values->hit = 0;
}

void	init_cast(t_r_cast *values, t_data *data)
{
	if (values->ray_dirx < 0)
	{
		values->stepx = -1;
		values->sidedistx = (data->player_pos_x - values->map_x)
			* values->delta_distx;
	}
	else
	{
		values->stepx = 1;
		values->sidedistx = (values->map_x + 1.0 - data->player_pos_x)
			* values->delta_distx;
	}
	if (values->ray_diry < 0)
	{
		values->stepy = -1;
		values->sidedisty = (data->player_pos_y - values->map_y)
			* values->delta_disty;
	}
	else
	{
		values->stepy = 1;
		values->sidedisty = (values->map_y + 1.0 - data->player_pos_y)
			* values->delta_disty;
	}
}

void	dda_alg(t_data *data, t_r_cast *values)
{
	while (values->hit == 0)
	{
		if (values->sidedistx < values->sidedisty)
		{
			values->sidedistx += values->delta_distx;
			values->map_x += values->stepx;
			data->side = 0;
		}
		else
		{
			values->sidedisty += values->delta_disty;
			values->map_y += values->stepy;
			data->side = 1;
		}
		if (data->map[values->map_x][values->map_y] == '1')
			values->hit = 1;
	}
	init_distance(data, values);
}

void	casting_ray(t_data *data)
{
	t_r_cast	values;
	t_line		line;
	int			width;
	int			x;

	width = data->mlx.w_w;
	x = 0;
	while (x < width)
	{
		init_var(&values, data, x, width);
		init_cast(&values, data);
		dda_alg(data, &values);
		init_line(&line, &values, data);
		draw_height_line(x, &line, data, &values);
		x++;
	}
}
