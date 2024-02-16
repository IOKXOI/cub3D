/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:25:26 by tschecro          #+#    #+#             */
/*   Updated: 2024/02/07 19:35:58 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "includes.h"
#include "struct.h"

void	destroy_text(t_data *data)
{
	if (data->no_texture.img.img)
		mlx_destroy_image(data->mlx.mlx, data->no_texture.img.img);
	if (data->so_texture.img.img)
		mlx_destroy_image(data->mlx.mlx, data->so_texture.img.img);
	if (data->ea_texture.img.img)
		mlx_destroy_image(data->mlx.mlx, data->ea_texture.img.img);
	if (data->we_texture.img.img)
		mlx_destroy_image(data->mlx.mlx, data->we_texture.img.img);
}

int	destroy(t_data *data)
{
	if (data->img.img)
		mlx_destroy_image(data->mlx.mlx, data->img.img);
	destroy_text(data);
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	if (data->mlx.mlx)
	{
		mlx_destroy_display(data->mlx.mlx);
		free(data->mlx.mlx);
	}
	exit(1);
	return (1);
}

static int	hooks_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		clear_exit_parsing(data, "");
	up_down_hook(keycode, data);
	right_hook(keycode, data);
	left_hook(keycode, data);
	pan_hook(keycode, data);
	return (1);
}

int	cross_button(t_data *data)
{
	clear_exit_parsing(data, "");
	return (1);
}

void	init_hooks(t_data *data)
{
	mlx_hook(data->mlx.win, 17, (1L << 17), cross_button, data);
	mlx_hook(data->mlx.win, 2, KeyPressMask, hooks_handler, data);
}
