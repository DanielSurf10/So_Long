/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:44:07 by danbarbo          #+#    #+#             */
/*   Updated: 2024/02/02 17:20:58 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_char_set(char *file_string, int *return_code)
{
	int	i;

	i = 0;
	while (file_string[i])
	{
		if (file_string[i] != '0' && file_string[i] != '1'
			&& file_string[i] != 'C' && file_string[i] != 'E'
			&& file_string[i] != 'P' && file_string[i] != '\n')
		{
			*return_code = INVALID_CHAR_ERROR;
			break ;
		}
		i++;
	}
	return (*return_code);
}

static	int	validate_tile_count(char *file_string, int *return_code)
{
	int	i;
	int	exit_count;
	int	collectible_count;
	int	starting_count;

	i = 0;
	exit_count = 0;
	collectible_count = 0;
	starting_count = 0;
	while (file_string[i])
	{
		if (file_string[i] == 'E')
			exit_count++;
		else if (file_string[i] == 'C')
			collectible_count++;
		else if (file_string[i] == 'P')
			starting_count++;
		i++;
	}
	if (exit_count != 1 || collectible_count < 1 || starting_count != 1)
		*return_code = INVALID_TILE_COUNT_ERROR;
	return (*return_code);
}

static int	validate_rectangle_shape(char *file_string, int *return_code)
{
	int		count_split;
	int		first_line_width;
	char	**split;

	count_split = 0;
	split = ft_split(file_string, '\n');
	first_line_width = ft_strlen(split[0]);
	while (split[count_split])
	{
		if (ft_strlen(split[count_split]) != first_line_width)
		{
			*return_code = MAP_NOT_RECTANGULAR_ERROR;
			break ;
		}
		count_split++;
	}
	ft_free_split(split);
	return (*return_code);
}

static int	validate_walls_enclosure(char *file_string, int *return_code)
{
	int		i;
	int		count_split;
	int		map_width;
	int		map_heigth;
	char	**split;

	i = 0;
	map_heigth = 0;
	count_split = 0;
	split = ft_split(file_string, '\n');
	map_width = ft_strlen(split[0]);
	while (split[map_heigth])
		map_heigth++;
	while (split[0][i] == '1' && split[map_heigth - 1][i] == '1')
		i++;
	if (i != map_width)
		*return_code = MAP_NOT_ENCLOSED_ERROR;
	while (split[count_split] && split[count_split][0] == '1' && split[count_split][map_width - 1] == '1')
		count_split++;
	if (count_split != map_heigth)
		*return_code = MAP_NOT_ENCLOSED_ERROR;
	ft_free_split(split);
	return (*return_code);
}

static int flood_fill(char *file_string, int *return_code)
{
	return (SUCCESS);
}

// Verificações:
//	1°: o mapa deve conter apenas os caracteres: "01CEP" - INVALID_CHAR_ERROR - Talvez aqui mude para fazer o bônus
//	2°: o mapa deve conter uma saída "E", pelo menos um coletável "C" e um ponto de início "P" - INVALID_TILE_COUNT_ERROR
//	3°: o mapa deve ser retangular - MAP_NOT_RECTANGULAR_ERROR
//	4°: o mapa deve ser fechado por paredes - MAP_NOT_ENCLOSED_ERROR
int	map_validation(char *file_string)
{
	int	return_code;

	return_code = SUCCESS;
	// if (validate_char_set(file_string, &return_code)
	// 	|| validate_tile_count(file_string, &return_code)
	// 	|| validate_rectangle_shape(file_string, &return_code)
	// 	|| validate_walls_enclosure(file_string, &return_code)
	// 	|| flood_fill(file_string, &return_code))
	// 	return (return_code);

	validate_char_set(file_string, &return_code);
	validate_tile_count(file_string, &return_code);
	validate_rectangle_shape(file_string, &return_code);
	validate_walls_enclosure(file_string, &return_code);
	// flood_fill(file_string, &return_code);
	return (return_code);
}
