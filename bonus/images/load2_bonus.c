/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:40:39 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/15 19:43:38 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_game_end(t_game *game)
{
	// mlx_texture_t	*texture;											// Essa variável já não é mais necessária
	int32_t			width;
	int32_t			height;
	float			ratio;

	// texture = mlx_load_png("images/game_over.png");						// Aqui está dando leak por causa da textura
	// game->sprites.game_over = mlx_texture_to_image(game->mlx, texture);	// Pq a textura tem que deletar depois que usa
																			// Vou trocar por load_imgs()
																			// E pronto leak resolvido
	game->sprites.game_over = load_imgs("images/game_over.png", game);		// Fica assim
	width = game->sprites.game_over->width;
	height = game->sprites.game_over->height;
	ratio = game->mlx->height / (float)height;
	mlx_resize_image(game->sprites.game_over, width * ratio, height * ratio);


	// Agora só fezer isso para todos

	// texture = mlx_load_png("images/game_win.png");
	// game->sprites.game_win = mlx_texture_to_image(game->mlx, texture);

	game->sprites.game_win = load_imgs("images/game_win.png", game);
	width = game->sprites.game_win->width;
	height = game->sprites.game_win->height;
	ratio = game->mlx->height / (float)height;
	mlx_resize_image(game->sprites.game_win, width * ratio, height * ratio);


	// texture = mlx_load_png("images/game_end_bg.png");
	// game->sprites.end_bg = mlx_texture_to_image(game->mlx, texture);

	game->sprites.end_bg = load_imgs("images/game_end_bg.png", game);
	mlx_resize_image(game->sprites.end_bg, game->mlx->width, game->mlx->height);


	// mlx_delete_texture(texture);											// Essa linha será apagada
																			// porque não precisa
																			// apagar a textura
																			// a função load_imgs() já fez isso
}

void	load_hearts(t_game *game)
{
	int32_t	i;

	i = 0;
	while (i < 3)
	{
		game->sprites.heart[i] = load_imgs("images/icons/heart.png", game);
		mlx_resize_image(game->sprites.heart[i], 46, 41);
		game->sprites.no_heart[i] = load_imgs("images/icons/no_heart.png",
				game);
		mlx_resize_image(game->sprites.no_heart[i], 46, 41);
		i++;
	}
	game->life_count = 3;
}

void	load_banner(t_game *game)
{
	game->sprites.banner = load_imgs("images/icons/slider.png", game);
	mlx_resize_image(game->sprites.banner, 150, 53);
}

void	load_background(t_game *game)
{
	int32_t	width;
	int32_t	height;
	int32_t	ratio;

	game->sprites.bg = load_imgs("images/background/bg4.png", game);
	width = game->sprites.bg->width;
	height = game->sprites.bg->height;
	ratio = game->mlx->height / (float)height;
	mlx_resize_image(game->sprites.bg, width * ratio, height * ratio);
}
