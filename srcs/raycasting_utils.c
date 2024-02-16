/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:04:55 by tschecro          #+#    #+#             */
/*   Updated: 2024/02/08 17:05:42 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "cub3d.h"
#include "struct.h"

void	init_distance(t_data *data, t_r_cast *values)
{
	if (data->side == 0)
	{
		values->perpwalldist = values->sidedistx - values->delta_distx;
		values->intersec_x = data->player_pos_y + values->perpwalldist
			* values->ray_diry;
		values->intersec_y = values->map_y;
	}
	else
	{
		values->perpwalldist = values->sidedisty - values->delta_disty;
		values->intersec_y = data->player_pos_x + values->perpwalldist
			* values->ray_dirx;
		values->intersec_x = values->map_x;
	}
}
