/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files_acces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:02:09 by greengo           #+#    #+#             */
/*   Updated: 2024/02/08 12:42:16 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "struct.h"
#include "includes.h"
#include "cub3d.h"

static bool	check_file_acces_extension(char *map_name)
{
	if (!map_name || !*map_name)
	{
		printf("Error\nMissing map.\n");
		return (0);
	}
	else if (*(map_name + (ft_strlen(map_name) - 4)) != '.'
		|| *(map_name + ft_strlen(map_name) - 3) != 'c'
		|| *(map_name + ft_strlen(map_name) - 2) != 'u'
		|| *(map_name + ft_strlen(map_name) - 1) != 'b')
	{
		printf("Error\nUnrecognized map format.\n");
		return (0);
	}
	else
		return (1);
}

void	check_file_acces_open_file(char *map_name, t_data *data)
{
	int	fd;

	if (!check_file_acces_extension(map_name))
		clear_exit_parsing(data, "");
	fd = open(map_name, O_RDONLY);
	if (fd != -1)
		data->fd = fd;
	else
	{
		printf("Error\nCannot open file: %s\n", map_name);
		clear_exit_parsing(data, "");
	}
}
