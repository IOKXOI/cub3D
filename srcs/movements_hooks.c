/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:14:49 by tschecro          #+#    #+#             */
/*   Updated: 2024/02/08 17:06:14 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "includes.h"
#include "struct.h"

void	up_down_hook(int keycode, t_data *data)
{
	if (keycode == 119)
	{
		if (data->map[(int)(data->player_pos_x + data->angle.vec_x * \
					(data->speed * 2))][(int)(data->player_pos_y)] != '1')
		{
			data->player_pos_x += data->angle.vec_x * data->speed;
		}
		if (data->map[(int)(data->player_pos_x)][(int)(data->player_pos_y \
					+ data->angle.vec_y * (data->speed * 2))] != '1')
		{
			data->player_pos_y += data->angle.vec_y * data->speed;
		}
	}
	if (keycode == 115)
	{
		if (data->map[(int)(data->player_pos_x - data->angle.vec_x
				* (data->speed * 2))][(int)(data->player_pos_y)] != '1')
			data->player_pos_x -= data->angle.vec_x * data->speed;
		if (data->map[(int)(data->player_pos_x)][(int)(data->player_pos_y - \
					data->angle.vec_y * (data->speed * 2))] != '1')
			data->player_pos_y -= data->angle.vec_y * data->speed;
	}
}

void	right_hook(int keycode, t_data *data)
{
	float	v_orth_x;
	float	v_orth_y;

	if (keycode == 97)
	{
		v_orth_x = -data->angle.vec_y;
		v_orth_y = data->angle.vec_x;
		if (data->map[(int)(data->player_pos_x + v_orth_x
				* (data->speed * 2))][(int)(data->player_pos_y)] != '1')
			data->player_pos_x += v_orth_x * data->speed;
		if (data->map[(int)(data->player_pos_x)][(int)(data->player_pos_y
				+ v_orth_y * (data->speed * 2))] != '1')
			data->player_pos_y += v_orth_y * data->speed;
	}
}

void	left_hook(int keycode, t_data *data)
{
	float	v_orth_x;
	float	v_orth_y;

	if (keycode == 100)
	{
		v_orth_x = data->angle.vec_y;
		v_orth_y = -data->angle.vec_x;
		if (data->map[(int)(data->player_pos_x + v_orth_x
				* (data->speed * 2))][(int)(data->player_pos_y)] != '1')
			data->player_pos_x += v_orth_x * data->speed;
		if (data->map[(int)(data->player_pos_x)][(int)(data->player_pos_y
				+ v_orth_y * (data->speed * 2))] != '1')
			data->player_pos_y += v_orth_y * data->speed;
	}
}

void	pan_hook_nrm(t_data *data, float old_dir_x, float old_plane_x)
{
	data->angle.vec_x = data->angle.vec_x * cos(-data->rs)
		- data->angle.vec_y * sin(-data->rs);
	data->angle.vec_y = old_dir_x * sin(-data->rs)
		+ data->angle.vec_y * cos(-data->rs);
	data->plane_x = data->plane_x * cos(-data->rs)
		- data->plane_y * sin(-data->rs);
	data->plane_y = old_plane_x * sin(-data->rs)
		+ data->plane_y * cos(-data->rs);
}

void	pan_hook(int keycode, t_data *data)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = data->angle.vec_x;
	old_plane_x = data->plane_x;
	if (keycode == 65363)
		pan_hook_nrm(data, old_dir_x, old_plane_x);
	if (keycode == 65361)
	{
		data->angle.vec_x = data->angle.vec_x * cos(data->rs)
			- data->angle.vec_y * sin(data->rs);
		data->angle.vec_y = old_dir_x * sin(data->rs)
			+ data->angle.vec_y * cos(data->rs);
		data->plane_x = data->plane_x * cos(data->rs)
			- data->plane_y * sin(data->rs);
		data->plane_y = old_plane_x * sin(data->rs)
			+ data->plane_y * cos(data->rs);
	}
}
