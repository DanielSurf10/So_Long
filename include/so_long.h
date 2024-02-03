/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:56:59 by danbarbo          #+#    #+#             */
/*   Updated: 2024/02/02 22:37:16 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


#include <stdio.h>			// Apagar isso depois

// Includes

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft.h"
# include "MLX42/MLX42.h"

// Defines

# define BUFFER_SIZE 100

// Enums

enum e_errors
{
	SUCCESS = 0,
	USAGE_ERROR,
	FILE_EXTENSION_ERROR,
	FILE_NOT_FOUND_ERROR,
	FILE_EMPTY_ERROR,
	INVALID_CHAR_ERROR,
	INVALID_EXIT_ERROR,
	INSUFFICIENT_COLLECTIBLES_ERROR,
	INVALID_START_POINT_ERROR,
	MAP_NOT_RECTANGULAR_ERROR,
	MAP_NOT_ENCLOSED_ERROR,
	NO_VALID_PATH_ERROR
};

// Structs

typedef struct s_so_long
{
	mlx_t	*mlx;
}	t_so_long;

// Functions

int	validate(char *path_to_map);
int	map_validation(char *file_string);
int flood_fill(char *file_string, int *return_code);

#endif
