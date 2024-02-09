/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_fundo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:15:36 by danbarbo          #+#    #+#             */
/*   Updated: 2024/02/08 22:33:05 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

struct imagens
{
	mlx_t			*mlx;
	mlx_image_t		*image1;
	mlx_image_t		*image2;
	mlx_texture_t	*texture;
};

void	texture_to_image(mlx_texture_t *texture, mlx_image_t *image, int x, int y);

void	*get_pixel(mlx_texture_t *texture, int x, int y)
{
	return (&texture->pixels[(y * texture->width + x) * 4]);
}

void	invert_image(mlx_texture_t *texture)
{
	int		x;
	int		y;
	char	tmp[4];

	y = 0;
	while (y < texture->height)
	{
		x = 0;
		while (x < texture->width / 2)
		{
			memcpy(tmp, get_pixel(texture, x, y), 4);
			memcpy(get_pixel(texture, x, y), get_pixel(texture, texture->width - x - 1, y), 4);
			memcpy(get_pixel(texture, texture->width - x - 1, y), tmp, 4);
			x++;
		}
		y++;
	}
}

void	function(mlx_key_data_t keydata, void *param)
{
	struct imagens	*image = param;

	// image->image1->instances[0].enabled = 0;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(image->mlx);
		if (keydata.key == MLX_KEY_SPACE)
			image->image1->instances[0].enabled = !(image->image1->instances[0].enabled);

		if (keydata.key == MLX_KEY_B)
		{
			// texture_to_image(image->texture, image->image2, 100, 100);
		}
	}
}

int main()
{
	struct imagens imagens;

	imagens.texture = mlx_load_png("images/Blue.png");
	imagens.mlx = mlx_init(imagens.texture->width * 10, imagens.texture->height * 10, "so_long", true);
	imagens.image1 = mlx_texture_to_image(imagens.mlx, imagens.texture);
	imagens.image2 = mlx_new_image(imagens.mlx, imagens.mlx->width, imagens.mlx->height);

	int count_width = imagens.mlx->width / imagens.texture->width;
	int count_height = imagens.mlx->height / imagens.texture->height;
	for (int j = 0; j < imagens.texture->width * count_width; j += imagens.texture->width)
	{
		for (int i = 0; i < imagens.texture->width * count_width; i += imagens.texture->width)
		{
			texture_to_image(imagens.texture, imagens.image2, i, j);
			invert_image(imagens.texture);
		}
		invert_image(imagens.texture);
	}

	// mlx_image_to_window(imagens.mlx, imagens.image1, 0, 0);
	mlx_image_to_window(imagens.mlx, imagens.image2, 0, 0);

	mlx_key_hook(imagens.mlx, function, &imagens);

	mlx_loop(imagens.mlx);

	return (0);
}
