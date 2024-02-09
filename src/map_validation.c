/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:44:07 by danbarbo          #+#    #+#             */
/*   Updated: 2024/02/09 13:49:00 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Valida se o mapa contém apenas os caracteres '01CEP'.
 *
 * @param file_string A string que representa o arquivo de mapa.
 * @param return_code Ponteiro para o código de status da operação.
 * @return int
 */
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
			*return_code = INVALID_CHARSET_ERROR;
			break ;
		}
		i++;
	}
	return (*return_code);
}

/**
 * @brief Valida se o mapa contém apenas um ponto de saída.
 *
 * @param file_string A string que representa o arquivo de mapa.
 * @param return_code Ponteiro para o código de status da operação.
 * @return int
 */
static	int	validate_tile_count(char *file_string, int *return_code)
{
	int	i;
	int	exit_count;
	int	collectible_count;
	int	starting_count;

	i = -1;
	exit_count = 0;
	collectible_count = 0;
	starting_count = 0;
	while (file_string[++i])
	{
		if (file_string[i] == 'E')
			exit_count++;
		else if (file_string[i] == 'C')
			collectible_count++;
		else if (file_string[i] == 'P')
			starting_count++;
	}
	if (exit_count != 1)
		*return_code = INVALID_EXIT_ERROR;
	else if (collectible_count < 1)
		*return_code = INSUFFICIENT_COLLECTIBLES_ERROR;
	else if (starting_count != 1)
		*return_code = INVALID_START_POINT_ERROR;
	return (*return_code);
}

/**
 * @brief Valida se o mapa é retangular.
 *
 * @param file_string A string que representa o arquivo de mapa.
 * @param return_code Ponteiro para o código de status da operação.
 * @return int
 */
static int	validate_rectangle_shape(char **split, int *return_code)
{
	int		count_split;
	int		first_line_width;

	count_split = 0;
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
	return (*return_code);
}

/**
 * @brief Valida se o mapa é completamente cercado por paredes.
 *
 * @param file_string A string que representa o arquivo de mapa.
 * @param return_code Ponteiro para o código de status da operação.
 * @return int
 */
static int	validate_walls_enclosure(char **split, int *return_code)
{
	int		i;
	int		count_split;
	int		map_width;
	int		map_heigth;

	i = 0;
	map_heigth = 0;
	count_split = 0;
	map_width = ft_strlen(split[0]);
	while (split[map_heigth])
		map_heigth++;
	while (split[0][i] == '1' && split[map_heigth - 1][i] == '1')
		i++;
	if (i != map_width)
		*return_code = MAP_NOT_ENCLOSED_ERROR;
	while (split[count_split] && split[count_split][0] == '1'
			&& split[count_split][map_width - 1] == '1')
		count_split++;
	if (count_split != map_heigth)
		*return_code = MAP_NOT_ENCLOSED_ERROR;
	return (*return_code);
}

// Verificações:
//	1°: o mapa deve conter apenas os caracteres: "01CEP" - INVALID_CHARSET_ERROR - Talvez aqui mude para fazer o bônus
//	2°: o mapa deve conter uma saída "E" - INVALID_EXIT_ERROR
//	3°: o mapa deve conter pelo menos um coletável "C" - INSUFFICIENT_COLLECTIBLES_ERROR
//	4°: o mapa deve conter só um ponto de início "P" - INVALID_START_POINT_ERROR
//	5°: o mapa deve ser retangular - MAP_NOT_RECTANGULAR_ERROR
//	6°: o mapa deve ser fechado por paredes - MAP_NOT_ENCLOSED_ERROR
//	7°: o mapa deve ter um caminho válido para todos os coletáveis e para a saída - NO_VALID_PATH_ERROR
int	map_validation(char *file_string)
{
	int		return_code;
	char	**split;

	return_code = SUCCESS;
	split = ft_split(file_string, '\n');
	if (validate_char_set(file_string, &return_code)
		|| validate_tile_count(file_string, &return_code)
		|| validate_rectangle_shape(split, &return_code)
		|| validate_walls_enclosure(split, &return_code)
		|| flood_fill(file_string, &return_code))
		;
	ft_free_split(split);
	return (return_code);
}
