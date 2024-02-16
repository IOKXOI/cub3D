/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:28:30 by tschecro          #+#    #+#             */
/*   Updated: 2024/02/07 18:29:00 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "cub3d.h"
#include "struct.h"

bool	check_collision(t_data *data, int x, int y)
{
	if (data->map[x][y] != '0')
		return (true);
	else
		return (false);
}
