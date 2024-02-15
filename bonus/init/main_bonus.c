/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:09:21 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/15 20:14:44 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int32_t	main(int argc, char **argv)
{
	int32_t	fd;
	// t_game	*game;
	t_game	game;												// Mudei aqui

	ft_bzero(&game, sizeof(t_game));							// Precisa zerar tudo também
	if (argc != 2)
		return (ft_putstr_fd(MSG_ARGS, 2), EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd(MSG_OPEN_FILE, 2), EXIT_FAILURE);
	// game = (t_game *)ft_calloc(sizeof(t_game), 1);			// Aqui não precisa de malloc,
																// dá pra usar como um variável local mesmo
																// Mas não faz muita diferença
																// Ficaria assim, mudei ali em cima também
																// Aí precisa mudar o resto nessa função

	// if (!game)												// Vou desconsiderar as falhas do malloc
	// 	return (ft_putstr_fd(MSG_MALLOC, 2), EXIT_FAILURE);

	init_build(&game, argv[1], fd);								// Mudei aqui
	init_window(&game);											// Mudei aqui
	init_game(&game);											// Mudei aqui
	// free(game);												// Não precisa dar free


	// O programa deve voltar aqui quando
	// - houver um erro na validação
	// - quando sai do jogo, seja por morrer, ganhar ou só fechar mesmo
	// O prograva tem que chegar até pra dar free nas coisas
	// Dependendo de qual erro der, não pode dar alguns free's

	// Precisa dar free
	// 2 - Dar close no fd do arquivo do mapa
	// 2 - Nas linhas que leu com a gnl, está na map_info->matrix
	// 3 - Na game.map->matrix
	// 4 - Na game.map

	// Close no fd
	close(fd);

	// Nas linhas
	int i = 0;
	while (i < game.map->height - 1)
	{
		free(game.map->matrix[i]);
		i++;
	}

	// game.map->matrix e game.map
	free(game.map->matrix);
	free(game.map);


	return (EXIT_SUCCESS);
}
