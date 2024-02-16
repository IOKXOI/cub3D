/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:12:58 by tschecro          #+#    #+#             */
/*   Updated: 2024/02/13 19:56:32 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "includes.h"
#include "cub3d.h"

void	check_texture(char *line, t_data *data, t_texture *texture)
{
	if (texture->img.img)
	{
		free(line);
		printf("Error\nInvalid map format.\n");
		clear_exit_parsing(data, "");
	}
	block_a_checker_open_path(line, data, texture);
}
