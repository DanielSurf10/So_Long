/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_imagens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:15:36 by danbarbo          #+#    #+#             */
/*   Updated: 2024/02/06 16:40:58 by danbarbo         ###   ########.fr       */
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

void	texture_to_image(mlx_texture_t *texture, mlx_image_t *image, int x, int y)
{
	int		i;
	uint8_t	*pixelx;
	uint8_t	*pixeli;

	for (i = 0; i < texture->height; i++)
	{
		pixelx = &texture->pixels[(i * texture->width) * texture->bytes_per_pixel];
		pixeli = &image->pixels[((x + i) * image->width) * texture->bytes_per_pixel];
		memmove(pixeli, pixelx, texture->width * texture->bytes_per_pixel);
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
			// for (int x = 0; x < image->image1->width; x++)
			// {
			// 	for (int y = 0; y < image->image1->height; y++)
			// 	{
			// 		mlx_put_pixel(image->image2, x, y, image->image1->pixels[y * image->image1->width + x]);
			// 		printf("%d\n", image->image1->pixels[y * image->image1->width + x]);
			// 	}
			// }
			texture_to_image(image->texture, image->image2, 100, 100);
		}
	}
}

int main()
{
	struct imagens imagens;
	imagens.mlx = mlx_init(1280, 720, "so_long", true);

	imagens.texture = mlx_load_png("images/Blue.png");
	imagens.image1 = mlx_texture_to_image(imagens.mlx, imagens.texture);
	imagens.image2 = mlx_new_image(imagens.mlx, imagens.texture->width, imagens.texture->height);

	// mlx_image_to_window(imagens.mlx, imagens.image1, 0, 0);
	mlx_image_to_window(imagens.mlx, imagens.image2, 0, 0);

	mlx_key_hook(imagens.mlx, function, &imagens);

	mlx_loop(imagens.mlx);


	return (0);
}
