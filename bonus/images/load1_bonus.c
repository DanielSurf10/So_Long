/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load1_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:35:09 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/15 18:36:55 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
 * @brief Loads the star's (collectible) animation frames from image
 * files and resizes them
 *
 * @param game pointer to the t_game structure containing game data
 */
static void	load_stars(t_game *game)
{
	game->sprites.star[0] = load_imgs("images/flasks/flasks_01.png", game);
	mlx_resize_image(game->sprites.star[0], BLOC, BLOC);
	game->sprites.star[1] = load_imgs("images/flasks/flasks_02.png", game);
	mlx_resize_image(game->sprites.star[1], BLOC, BLOC);
	game->sprites.star[2] = load_imgs("images/flasks/flasks_03.png", game);
	mlx_resize_image(game->sprites.star[2], BLOC, BLOC);
	game->sprites.star[3] = load_imgs("images/flasks/flasks_04.png", game);
	mlx_resize_image(game->sprites.star[3], BLOC, BLOC);
}

/*
 * @brief Loads the enemy character's animation frames from image
 * files and resizes them
 *
 * @param game pointer to the t_game structure containing game data
 */
static void	load_enemies(t_game *game)
{
	game->sprites.enemy[0] = load_imgs("images/skull/skull_01.png", game);
	mlx_resize_image(game->sprites.enemy[0], BLOC, BLOC);
	game->sprites.enemy[1] = load_imgs("images/skull/skull_02.png", game);
	mlx_resize_image(game->sprites.enemy[1], BLOC, BLOC);
	game->sprites.enemy[2] = load_imgs("images/skull/skull_03.png", game);
	mlx_resize_image(game->sprites.enemy[2], BLOC, BLOC);
	game->sprites.enemy[3] = load_imgs("images/skull/skull_04.png", game);
	mlx_resize_image(game->sprites.enemy[3], BLOC, BLOC);
}

mlx_image_t	*load_imgs(const char *path, t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	// if (!texture)				// Vou desconsiderar as falhas da mlx
	// {
	// 	ft_putstr_fd(MSG_LOAD, 2);
	// 	exit(EXIT_FAILURE);
	// }
	img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (img);
}

void	define_imgs(t_game *game)
{
	game->sprites.tile = load_imgs("images/tiles/tile2.png", game);
	mlx_resize_image(game->sprites.tile, BLOC, BLOC);
	game->sprites.exit[0] = load_imgs("images/box/box_closed.png", game);
	mlx_resize_image(game->sprites.exit[0], BLOC, BLOC);
	game->sprites.exit[1] = load_imgs("images/box/box_open.png", game);
	mlx_resize_image(game->sprites.exit[1], BLOC, BLOC);
	load_heros(game);
	load_hero_red(game);
	load_enemies(game);
	load_stars(game);
	load_background(game);
	load_banner(game);
	load_hearts(game);
	load_game_end(game);
}
