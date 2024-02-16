/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:27:54 by tschecro          #+#    #+#             */
/*   Updated: 2024/02/07 18:27:57 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "struct.h"
#include "cub3d.h"

void	set_floor_and_ceiling(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->mlx.w_w)
	{
		y = 0;
		while (y < data->mlx.w_h)
		{
			if (y < data->mlx.w_h / 2)
				my_mlx_pixel_put(data, x, y, data->c_ceiling);
			else
				my_mlx_pixel_put(data, x, y, data->c_floor);
			y++;
		}
		x++;
	}
}
