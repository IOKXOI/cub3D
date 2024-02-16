/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:23:44 by greengo           #+#    #+#             */
/*   Updated: 2024/02/08 12:47:51 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "struct.h"
#include "includes.h"

static void	flush_get_next_line(t_data *data)
{
	char	*line;

	line = get_next_line(data->fd);
	while (line)
	{
		free(line);
		line = get_next_line(data->fd);
	}
}

void	clear_exit_parsing(t_data *data, char *error_message)
{
	if (data->fd != -1)
	{
		flush_get_next_line(data);
		close(data->fd);
	}
	if (data->map)
		free_map_array(data->map, data->map_height);
	if (data->map_copy)
		free_map_array(data->map_copy, data->map_height);
	if (data->line_size)
		free(data->line_size);
	if (data->path)
		free(data->path);
	if (*error_message)
		perror(error_message);
	destroy(data);
	exit(EXIT_FAILURE);
}
