/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:23:33 by danbarbo          #+#    #+#             */
/*   Updated: 2024/02/09 19:19:32 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

void	texture_to_image(mlx_texture_t *texture, mlx_image_t *image, int x, int y)
{
	int		i;
	uint8_t	*pixelx;
	uint8_t	*pixeli;

	for (i = 0; i < texture->height; i++)
	{
		pixelx = &texture->pixels[(i * texture->width) * texture->bytes_per_pixel];
		pixeli = &image->pixels[(((i + y) * image->width) + x) * texture->bytes_per_pixel];
		memmove(pixeli, pixelx, texture->width * texture->bytes_per_pixel);
	}
}

void	*get_pixel(uint8_t *pixels, int x, int y, int width)
{
	return (&pixels[(y * width + x) * 4]);
}

mlx_texture_t	*get_sprite(mlx_texture_t *texture, int x, int y, int width, int height)
{
	uint8_t			*pixel_texture;
	uint8_t			*pixel_sliced;
	mlx_texture_t	*sliced_texture;
	int				j;
	int				i;

	sliced_texture = malloc(sizeof(mlx_texture_t));
	sliced_texture->bytes_per_pixel = 4;
	sliced_texture->width = width;
	sliced_texture->height = height;
	sliced_texture->pixels = malloc(height * width * 4 * sizeof(uint8_t));
	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			pixel_texture = get_pixel(texture->pixels, x + i, y + j, texture->width);
			pixel_sliced = get_pixel(sliced_texture->pixels, i, j, width);
			memcpy(pixel_sliced, pixel_texture, 4);
			i++;
		}
		j++;
	}
	return (sliced_texture);
}

void	put_sprite(mlx_texture_t *texture, mlx_image_t *image, int x, int y, int width, int height)
{
	uint8_t			*pixel_texture;
	uint8_t			*pixel_image;
	int				image_y;
	int				image_x;

	image_y = 0;
	while (image_y < height)
	{
		image_x = 0;
		while (image_x < width)
		{
			pixel_texture = get_pixel(texture->pixels, x + image_x, y + image_y, texture->width);
			pixel_image = get_pixel(image->pixels, image_x, image_y, width);
			memcpy(pixel_image, pixel_texture, 4);
			image_x++;
		}
		image_y++;
	}
}
