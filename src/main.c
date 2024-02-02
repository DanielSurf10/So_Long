/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:53:24 by danbarbo          #+#    #+#             */
/*   Updated: 2024/02/02 17:45:19 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	else if (return_code == INVALID_CHAR_ERROR)
		ft_putendl_fd("Invalid char set. Expected '01CEP' character set.", 1);
	else if (return_code == INVALID_TILE_COUNT_ERROR)
		ft_putendl_fd("Bugou", 1);

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


	return (0);
}
