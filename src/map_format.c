/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:32:50 by krocha-h          #+#    #+#             */
/*   Updated: 2024/02/15 18:12:02 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*store_map_info(t_list *map_list)
{
	t_map	*map_info;
	int32_t	i;

	// if (map_list == NULL)		// Se isso aconteceu, temos um problema maior
	// 	return (NULL);					// Então vou só desconsiderar

	map_info = (t_map *)malloc(sizeof(t_map));		// Isso aqui poderia estar na estrutura principal
													// Aí não iria precisar allocar memória aqui

	// if (!map_info)				// Vou desconsiderar as falhas do malloc
	// 	return (NULL);

	map_info->height = ft_lstsize(map_list);
	map_info->matrix = malloc(map_info->height * sizeof(char *));

	// if (!map_info->matrix)		// Vou desconsiderar as falhas do malloc
	// {
	// 	free(map_info);
	// 	return (NULL);
	// }

	i = 0;
	while (map_list != NULL)		// Aqui faltou ir apagando a lista conforme vai lendo os nós
	{									// Já que não vai precisar usar ela em outros lugares
										// Mas só o nó, o conteúdo não pode dar free
										// A menos que dê ft_strdup() que seria o ideal
										// Ou dar um pop da lista em cada nó

		// map_info->matrix[i] = ft_strdup((char *)map_list->content);

		// Ou

		// Fazer a função ft_lstpop() que dê pop
			// Avança a lista e retorna o que tinha no nó
			// Só apagando o nó em si, não o conteúdo

		map_info->matrix[i] = (char *)map_list->content;
		map_list = map_list->next;
		i++;
	}
	map_info->width = ft_strlen(map_info->matrix[0]);

	return (map_info);
}

/*
 * @brief Removes the '\\n' of the end of each line
 *
 * @param line the string of the read lineof the map
 */
static void	line_cleaner(char *line)
{
	int32_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	line[i] = '\0';
}

t_list	*read_map(int fd)
{
	t_list	*map_list;
	t_list	*current;
	char	*line;

	map_list = NULL;
	while (fd)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line_cleaner(line);
		current = ft_lstnew(line);
		// if (!current)					// Vou desconsiderar as falhas do malloc
		// {
		// 	ft_lstclear(&map_list, free);
		// 	return (NULL);
		// }
		ft_lstadd_back(&map_list, current);
	}
	return (map_list);
}

// int main()
// {
// 	int fd;
// 	int	i;
// 	t_list	*map_list;
// 	t_map	*map;

// 	fd = open("./maps/map_01.ber", O_RDONLY);
// 	map_list = read_map(fd);
// 	map = store_map_info(map_list);
// 	i = 0;
// 	while (i < map->height)
// 	{
// 		printf("linha: %s\n", map->matrix[i]);
// 		i++;
// 	}
// 	printf("HEIGHT: %d\n", map->height);
// 	printf("WIDTH: %d\n", map->width);
// 	if (validate_map(map))
// 		printf("Mapa válido! Sucesso na missão 003\n");
// 	else
// 		printf("Mapa torto!\n");
// 	close(fd);
// 	return (0);
// }
