/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_B_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 04:43:38 by greengo           #+#    #+#             */
/*   Updated: 2024/02/08 12:18:19 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	line_is_start_of_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

void	create_arrays(t_data *data)
{
	data->map = malloc(sizeof(char *) * data->map_height + 1);
	if (!data->map)
		clear_exit_parsing(data, "Error\nMalloc map array failed.");
	data->map_copy = malloc(sizeof(char *) * data->map_height + 1);
	if (!data->map_copy)
		clear_exit_parsing(data, "Error\nMalloc map array copy failed.");
	data->line_size = malloc(sizeof(int) * data->map_height + 1);
	if (!data->line_size)
		clear_exit_parsing(data, "Error\nMalloc line size array failed.");
}

bool	block_b_getter_array(t_data *data)
{
	char	*line;

	data->map_height = 0;
	line = get_next_line(data->fd);
	while (line && !line_is_start_of_map(line))
	{
		if (*line != '\n')
			return (free(line), 0);
		free(line);
		line = get_next_line(data->fd);
		data->map_start++;
	}
	while (line)
	{
		free(line);
		line = get_next_line(data->fd);
		data->map_height++;
	}
	close(data->fd);
	create_arrays(data);
	return (1);
}

void	come_back_to_block_b(t_data *data, char *map_name)
{
	char	*line;
	int		start;

	start = data->map_start;
	check_file_acces_open_file(map_name, data);
	while (start--)
	{
		line = get_next_line(data->fd);
		free(line);
	}
}

int	duplicate_map(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(data->fd);
	if (!line)
		return (0);
	data->map_copy[i] = ft_strdup(line);
	if (!data->map_copy[i])
		clear_exit_parsing(data, "Error\nFt_strdup failed");
	data->map[i] = line;
	data->line_size[i] = ft_strlen(line);
	i++;
	while (i < data->map_height)
	{
		line = get_next_line(data->fd);
		data->map[i] = line;
		data->map_copy[i] = ft_strdup(line);
		if (!data->map_copy[i])
			clear_exit_parsing(data, "Error\nFt_strdup failed");
		data->line_size[i] = ft_strlen(line);
		i++;
	}
	return (1);
}
