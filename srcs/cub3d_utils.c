/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:26:41 by tschecro          #+#    #+#             */
/*   Updated: 2024/02/07 18:26:43 by tschecro         ###   ########.fr       */
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
