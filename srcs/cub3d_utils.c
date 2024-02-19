/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:26:41 by tschecro          #+#    #+#             */
/*   Updated: 2024/02/19 12:59:37 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "cub3d.h"
#include "struct.h"

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

void	ft_bzero(void *ptr, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int			*pixel_addr;

	if (data->mlx.w_h < 1920 || data->mlx.w_w < 1080)
		pixel_addr = (int *)(data->img.addr) + data->mlx.w_w * y + x;
	else
		pixel_addr = ((int *)(data->img.addr)
				+ ((y << 10) + (y << 9) + (y << 8) + (y << 7) + x));
	*pixel_addr = color;
}

static void	xy_swap(t_data *data)
{
	float	x;

	x = data->player_pos_y;
	data->player_pos_y = data->player_pos_x;
	data->player_pos_x = x;
}

void	init_exec_data(t_data *data)
{
	xy_swap(data);
	data->rs = 0.78539816339 / 2;
	data->speed = 0.40;
	data->plane_x = data->angle.vec_y;
	data->plane_y = -data->angle.vec_x;
}
