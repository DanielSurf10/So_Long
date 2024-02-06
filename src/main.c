/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:53:24 by danbarbo          #+#    #+#             */
/*   Updated: 2024/02/06 19:15:47 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Imprime uma mensagem de erro e termina o programa com EXIT_FAILURE.
 *
 * @param return_code: O código de erro que será impresso.
 */
static void	print_error(int return_code)
{
	ft_putendl_fd("Error", 1);
	if (return_code == USAGE_ERROR)
		ft_putendl_fd("Wrong usage. Expected: './fdf <file_path>'.", 1);
	else if (return_code == FILE_EXTENSION_ERROR)
		ft_putendl_fd("Invalid file extension. Expected '.ber' file.", 1);
	else if (return_code == FILE_NOT_FOUND_ERROR)
		ft_putendl_fd("File not found. Please provide a valid '.ber' file.", 1);
	else if (return_code == FILE_EMPTY_ERROR)
		ft_putendl_fd("Empty file. Please provide a non-empty '.ber' file.", 1);
	else if (return_code == INVALID_CHARSET_ERROR)
		ft_putendl_fd("Invalid char set. Expected '01CEP' character set.", 1);
	else if (return_code == INVALID_EXIT_ERROR)
		ft_putendl_fd("No exit or more than one exit found on the map.", 1);
	else if (return_code == INSUFFICIENT_COLLECTIBLES_ERROR)
		ft_putendl_fd("Less than one collectible found on the map.", 1);
	else if (return_code == INVALID_START_POINT_ERROR)
		ft_putendl_fd("No start point or more than one start point \
found on the map.", 1);
	else if (return_code == MAP_NOT_RECTANGULAR_ERROR)
		ft_putendl_fd("The map is not rectangular.", 1);
	else if (return_code == MAP_NOT_ENCLOSED_ERROR)
		ft_putendl_fd("The map is not fully enclosed by walls.", 1);
	else if (return_code == NO_VALID_PATH_ERROR)
		ft_putendl_fd("There is no path to finish on the map.", 1);
	exit(EXIT_FAILURE);
}

int	main(int argv, char *argc[])
{
	int			return_code;
	t_so_long	so_long_data;

	if (argv != 2)
		print_error(USAGE_ERROR);

	return_code = validate(argc[1]);

	if (return_code != SUCCESS)
	{
		print_error(return_code);
		return (1);
	}

	printf("Mapa validado!\n");

	return (0);
}
