/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:35:06 by sydauria          #+#    #+#             */
/*   Updated: 2024/02/19 12:43:32 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "cub3d.h"
#include "struct.h"

bool	init_img(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx.mlx, data->mlx.w_w, data->mlx.w_h);
	if (!data->img.img)
	{
		destroy(data);
		return (false);
	}
	data->img.addr = mlx_get_data_addr(data->img.img, \
			&data->img.bits_per_pixel, &data->img.line_lenght, \
			&data->img.endian);
	return (true);
}

void	textures_to_null(t_data *data)
{
	data->no_texture.img.img = NULL;
	data->so_texture.img.img = NULL;
	data->we_texture.img.img = NULL;
	data->ea_texture.img.img = NULL;
}

bool	init_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		return (false);
	if (WIN_WIDTH <= 0 || WIN_HEIGHT <= 0)
	{
		destroy(data);
		return (false);
	}
	else
	{
		data->mlx.w_w = WIN_WIDTH;
		data->mlx.w_h = WIN_HEIGHT;
	}
	if (!init_img(data))
		return (false);
	return (true);
}
