/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:19:22 by danbarbo          #+#    #+#             */
/*   Updated: 2024/02/09 14:02:22 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_width(char *file_string)
{
	int	i;

	i = 0;
	while (file_string[i])
	{
		if (file_string[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

int	get_map_heigth(char *file_string)
{
	size_t	i;
	size_t	rows;

	i = 0;
	rows = 0;
	while (file_string[i] != '\0')
	{
		if (file_string[i] != '\n' && (file_string[i + 1] == '\n'
				|| file_string[i + 1] == '\0'))
			rows++;
		i++;
	}
	return (rows);
}

t_player	get_player_pos(char *file_string)
{
	int			i;
	t_player	pos;

	i = 0;
	pos.x = 0;
	pos.y = 0;
	while (file_string[i])
	{
		if (file_string[i] == 'P')
			break ;
		pos.x++;
		if (file_string[i] == '\n')
		{
			pos.x = 0;
			pos.y++;
		}
		i++;
	}
	return (pos);
}
