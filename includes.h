/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:58:42 by tschecro          #+#    #+#             */
/*   Updated: 2024/02/08 16:59:19 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef PLAYER_SPEED
#  define PLAYER_SPEED 0.2
# endif

# include <math.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# include <stdio.h>
# include <stdbool.h>
# define XK_MISCELLANY
# define XK_LATIN1
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <X11/keysymdef.h>
# include <stdlib.h>
# include <X11/X.h>
# include <errno.h>
# include <stdint.h>

#endif
