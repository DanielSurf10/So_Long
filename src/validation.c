/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:31:53 by danbarbo          #+#    #+#             */
/*   Updated: 2024/02/02 16:24:08 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_file_extension(char *file_path, int *return_code)
{
	int	length;

	length = ft_strlen(file_path);
	if (length < 4 || ft_strncmp(file_path + length - 4, ".ber", 4) != 0)
		*return_code = FILE_EXTENSION_ERROR;
	return (*return_code);
}

static char	*ft_read_all(int fd)
{
	int		chars_readed;
	char	*temp_buffer;
	char	*file_string;
	char	*aux;

	chars_readed = BUFFER_SIZE;
	temp_buffer = (char *) malloc((BUFFER_SIZE + 1));
	file_string = ft_strdup("");
	while (chars_readed == BUFFER_SIZE)
	{
		chars_readed = read(fd, temp_buffer, BUFFER_SIZE);
		temp_buffer[chars_readed] = '\0';
		aux = file_string;
		file_string = ft_strjoin(file_string, temp_buffer);
		free(aux);
	}
	free(temp_buffer);
	return (file_string);
}

// Verificações:
//	1°: o arquivo deve ter uma extensão ".ber" - FILE_EXTENSION_ERROR
//	2°: o arquivo deve existe - FILE_NOT_FOUND_ERROR
//	3°: o arquivo não deve está vazio e tem permissões de leitura - FILE_EMPTY_ERROR
//	4°: verificações do mapa - map_validation.c
int	validate(char *path_to_map)
{
	int		fd;
	int		return_code;
	char	*file_string;

	return_code = SUCCESS;
	if (check_file_extension(path_to_map, &return_code))
		return (return_code);
	fd = open(path_to_map, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (FILE_NOT_FOUND_ERROR);
	file_string = ft_read_all(fd);
	close(fd);
	if (ft_strlen(file_string) == 0)
		return_code = FILE_EMPTY_ERROR;
	else
		return_code = map_validation(file_string);
	free(file_string);
	return (return_code);
}
