/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:34:42 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/15 18:38:30 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int32_t	init_game(t_game *game)
{
	display_components(game);
	mlx_loop_hook(game->mlx, animation, game);
	mlx_key_hook(game->mlx, key_motion, game);
	mlx_loop(game->mlx);
	// free_memory(game);
	mlx_terminate(game->mlx);

	return (1);
}

void	init_window(t_game *game)
{
	mlx_t	*mlx;
	int32_t	height;
	int32_t	width;

	height = game->map->height;
	width = game->map->width;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init((width * BLOC), (height * BLOC), "so_long", true);

	// if (!mlx)				// Vou desconsiderar as falhas da mlx
	// {
	// 	ft_putstr_fd(MSG_MALLOC, 2);
	// 	exit(EXIT_FAILURE);
	// }

	game->mlx = mlx;
	define_imgs(game);
}

/*
 * @brief A placeholder function used for ft_lstclear to avoid memory leaks
 */
static void	do_nothing(void *unused)
{
	(void)(unused);
}

void	init_build(t_game *game, char *filename, int32_t fd)
{
	t_map	*map;
	t_list	*map_list;

	if (!validate_filename(filename))		// Aqui checa se o arquivo tem e extensão ".ber".
											// Se não for
											// o fd do arquivo fica aberto e dá leak de fd
	{
		ft_putstr_fd(MSG_BER, 2);
		exit(EXIT_FAILURE);					// Aqui é só retornar com um código de erro
											// E na main fechar o fd e mostrar a mensagem
		// return (FILE_EXTENSION_ERROR)	// Mais ou menos assim
	}

	map_list = read_map(fd);

	// if (!map_list)						// Vou desconsiderar as falhas do malloc
	// {
	// 	ft_putstr_fd(MSG_MALLOC, 2);
	// 	exit(EXIT_FAILURE);
	// }

	map = store_map_info(map_list);
	ft_lstclear(&map_list, do_nothing);			// OBS: Aqui apaga só o nó, e não o conteúdo da lista

	// if (!map)								// Vou desconsiderar as falhas do malloc
	// {
	// 	ft_putstr_fd(MSG_MALLOC, 2);
	// 	exit(EXIT_FAILURE);
	// }

	game->map = map;
	validate_map(game);							// Aqui nas validações, ele da exit(EXIT_FAILURE)
												// quando o mapa está inválido. Causando leaks de memória.
												// O ideal seria retornar um código de erro para dar
												// free em tudo e dps sair do programa
	// return (INVALID_MAP_ERROR);				// Ou algo do tipo, claro o retorno da função tem que ser int
}
