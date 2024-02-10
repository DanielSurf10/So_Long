/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:40:22 by danbarbo          #+#    #+#             */
/*   Updated: 2024/02/09 21:45:53 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_animation
{
	void			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	int				sprite_count;
	int				frame_until_change;
	int				frames_to_wait;
}	t_animation;

mlx_texture_t	*get_sprite(mlx_texture_t *texture, int x, int y, int width, int height);
void	put_sprite(mlx_texture_t *texture, mlx_image_t *image, int x, int y, int width, int height);

void	loop(void *param)
{
	static int	counter;
	static int	sprite_counter;
	t_animation	*animation;

	animation = param;

	if (counter == animation->frame_until_change)
	{
		sprite_counter++;
		if (sprite_counter <= animation->sprite_count + 1)
		{
			printf("%d\n", sprite_counter);
			put_sprite(animation->texture, animation->image, (sprite_counter % (animation->sprite_count + 1)) * animation->image->width, 0, animation->image->width, animation->image->height);
		}
		else
		{
			if (sprite_counter >= animation->frames_to_wait)
				sprite_counter = 0;
			else
				sprite_counter++;
		}
		counter = 0;
	}
	counter++;
}

void	function(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx = param;

	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(mlx);
	}

}

int main()
{
	t_animation animation;

	void *mlx = mlx_init(64, 64, "", true);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	animation.mlx = mlx;

	mlx_texture_t *texture = mlx_load_png("images/End (Pressed) (64x64).png");
	animation.texture = texture;

// 	mlx_texture_t *sprite1 = get_sprite(texture, 0, 0, 32, 32);
// 	mlx_texture_t *sprite2 = get_sprite(texture, 32 * 6, 0, 32, 32);
//
// 	void *image1 = mlx_texture_to_image(mlx, sprite1);
// 	void *image2 = mlx_texture_to_image(mlx, sprite2);
//
// 	mlx_resize_image(image1, 100, 100);
// 	mlx_resize_image(image2, 100, 100);

	// mlx_image_to_window(mlx, image1, 0, 0);
	// mlx_image_to_window(mlx, image2, 132, 0);

	void *image = mlx_new_image(mlx, 64, 64);
	animation.image = image;
	animation.sprite_count = 15;
	animation.frame_until_change = 3;
	animation.frames_to_wait = 50;

	// mlx_resize_image(image, 100, 100);

	// for (int i = 0; i < 10; i++)
	// 	for (int j = 0; j < 10; j++)
	// 		mlx_image_to_window(mlx, image, 32 * i, 32 * j);

	mlx_image_to_window(mlx, image, 0, 0);

	mlx_loop_hook(mlx, loop, &animation);
	mlx_key_hook(mlx, function, mlx);
	mlx_loop(mlx);

	return (0);
}
