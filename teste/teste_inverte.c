/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_inverte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:01:51 by danbarbo          #+#    #+#             */
/*   Updated: 2024/02/08 22:28:01 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

typedef struct imagens
{
	mlx_t			*mlx;
	mlx_image_t		*image1;
	mlx_texture_t	*texture;
}	t_images;

void	texture_to_image(mlx_texture_t *texture, mlx_image_t *image, int x, int y);

void	*get_pixel(mlx_image_t *image, int x, int y)
{
	return (&image->pixels[(y * image->width + x) * 4]);
}

void	invert_image(mlx_image_t *image)
{
	int		x;
	int		y;
	char	tmp[4];

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width / 2)
		{
			memcpy(tmp, get_pixel(image, x, y), 4);
			memcpy(get_pixel(image, x, y), get_pixel(image, image->width - x - 1, y), 4);
			memcpy(get_pixel(image, image->width - x - 1, y), tmp, 4);
			x++;
		}
		y++;
	}
}

void	function(mlx_key_data_t keydata, void *param)
{
	t_images	*image = param;

	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(image->mlx);
		if (keydata.key == MLX_KEY_SPACE)
			invert_image(image->image1);
	}

}

int main()
{
	t_images	imagens;
	mlx_image_t	*a;


	imagens.mlx = mlx_init(300, 300, "", false);

	imagens.texture = mlx_load_png("images/Blue.png");
	imagens.image1 = mlx_texture_to_image(imagens.mlx, imagens.texture);
	a = mlx_texture_to_image(imagens.mlx, imagens.texture);

// 	imagens.image1 = mlx_new_image(imagens.mlx, 4, 4);
// 	a = mlx_new_image(imagens.mlx, 4, 4);
//
// 	mlx_put_pixel(imagens.image1, 0, 0, 0xFFFFFFFF);
// 	mlx_put_pixel(imagens.image1, 0, 1, 0xFFFFFFFF);
// 	mlx_put_pixel(imagens.image1, 0, 2, 0xFFFFFFFF);
// 	mlx_put_pixel(imagens.image1, 0, 3, 0xFFFFFFFF);
//
// 	mlx_put_pixel(imagens.image1, 1, 0, 0xFF00FFFF);
// 	mlx_put_pixel(imagens.image1, 1, 1, 0xFF00FFFF);
// 	mlx_put_pixel(imagens.image1, 1, 2, 0xFF00FFFF);
// 	mlx_put_pixel(imagens.image1, 1, 3, 0xFF00FFFF);
//
// 	mlx_put_pixel(imagens.image1, 2, 0, 0xFFFF00FF);
// 	mlx_put_pixel(imagens.image1, 2, 1, 0xFFFF00FF);
// 	mlx_put_pixel(imagens.image1, 2, 2, 0xFFFF00FF);
// 	mlx_put_pixel(imagens.image1, 2, 2, 0xFFFF00FF);
// 	mlx_put_pixel(imagens.image1, 2, 3, 0xFFFF00FF);
//
// 	mlx_put_pixel(imagens.image1, 3, 0, 0x00FFFFFF);
// 	mlx_put_pixel(imagens.image1, 3, 1, 0x00FFFFFF);
// 	mlx_put_pixel(imagens.image1, 3, 2, 0x00FFFFFF);
// 	mlx_put_pixel(imagens.image1, 3, 3, 0x00FFFFFF);
//
//
//
// 	mlx_put_pixel(a, 0, 0, 0xFFFFFFFF);
// 	mlx_put_pixel(a, 0, 1, 0xFFFFFFFF);
// 	mlx_put_pixel(a, 0, 2, 0xFFFFFFFF);
// 	mlx_put_pixel(a, 0, 3, 0xFFFFFFFF);
//
// 	mlx_put_pixel(a, 1, 0, 0xFF00FFFF);
// 	mlx_put_pixel(a, 1, 1, 0xFF00FFFF);
// 	mlx_put_pixel(a, 1, 2, 0xFF00FFFF);
// 	mlx_put_pixel(a, 1, 3, 0xFF00FFFF);
//
// 	mlx_put_pixel(a, 2, 0, 0xFFFF00FF);
// 	mlx_put_pixel(a, 2, 1, 0xFFFF00FF);
// 	mlx_put_pixel(a, 2, 2, 0xFFFF00FF);
// 	mlx_put_pixel(a, 2, 2, 0xFFFF00FF);
// 	mlx_put_pixel(a, 2, 3, 0xFFFF00FF);
//
// 	mlx_put_pixel(a, 3, 0, 0x00FFFFFF);
// 	mlx_put_pixel(a, 3, 1, 0x00FFFFFF);
// 	mlx_put_pixel(a, 3, 2, 0x00FFFFFF);
// 	mlx_put_pixel(a, 3, 3, 0x00FFFFFF);

	invert_image(imagens.image1);
	mlx_resize_image(imagens.image1, 64, 64);
	mlx_resize_image(a, 64, 64);

	mlx_image_to_window(imagens.mlx, imagens.image1, 86, 86);
	mlx_image_to_window(imagens.mlx, a, 0, 0);

	mlx_key_hook(imagens.mlx, function, &imagens);

	mlx_loop(imagens.mlx);

}
