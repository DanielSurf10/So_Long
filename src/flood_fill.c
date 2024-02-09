/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:36:36 by danbarbo          #+#    #+#             */
/*   Updated: 2024/02/09 14:01:38 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Preenche uma área em um mapa dada por uma string.
 *
 * @param map: Um ponteiro para uma string que representa o mapa do jogo.
 * @param x: A posição x do ponto inicial.
 * @param y: A posição y do ponto inicial.
 * @param width: A largura do mapa.
 */
static void	fill(char **map, int x, int y, int width)
{
	if ((*map)[x + y * width] != '1' && (*map)[x + y * width] != 'X')
	{
		(*map)[x + y * width] = 'X';
		fill(map, x + 1, y, width);
		fill(map, x - 1, y, width);
		fill(map, x, y + 1, width);
		fill(map, x, y - 1, width);
	}
}

/**
 * @brief Verifica se o mapa foi preenchido corretamente.
 *
 * @param map: Uma string que representa o mapa do jogo.
 * @param return_code: Um ponteiro para um inteiro que será usado para retornar
 * o código de status da operação.
 */
static void	check_flood(char *map, int *return_code)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'C' || map[i] == 'E' || map[i] == 'P')
			*return_code = NO_VALID_PATH_ERROR;
		i++;
	}
}

int	flood_fill(char *file_string, int *return_code)
{
	int			width;
	char		*map;
	t_player	player_pos;

	map = ft_strdup(file_string);
	width = get_map_width(file_string) + 1;
	player_pos = get_player_pos(file_string);
	fill(&map, player_pos.x, player_pos.y, width);
	check_flood(map, return_code);
	free(map);
	return (*return_code);
}
