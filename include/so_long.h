/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:56:59 by danbarbo          #+#    #+#             */
/*   Updated: 2024/02/06 18:08:43 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


#include <stdio.h>			// Apagar isso depois

// Includes

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft.h"
# include "MLX42/MLX42.h"

// Defines

# define BUFFER_SIZE 100

// Enums

/**
 * @brief mensagens de erro
 *
 * São usadas para identificar o tipo de erro que ocorreu durante a execução do
 * programa.
 *
 * SUCCESS							: Sucesso
 * USAGE_ERROR						: Erro de uso
 * FILE_EXTENSION_ERROR				: Erro de extensão do arquivo
 * FILE_NOT_FOUND_ERROR				: Arquivo não encontrado
 * FILE_EMPTY_ERROR					: Arquivo vazio
 * INVALID_CHARSET_ERROR			: Charset inválido
 * INVALID_EXIT_ERROR				: Quantidade de saídas inválida
 * INSUFFICIENT_COLLECTIBLES_ERROR	: Quantidade insuficiente de colecionáveis
 * INVALID_START_POINT_ERROR		: Quantidade de pontos de partida inválida
 * MAP_NOT_RECTANGULAR_ERROR		: Mapa não é retangular
 * MAP_NOT_ENCLOSED_ERROR			: Mapa não está fechado
 * NO_VALID_PATH_ERROR				: Nenhum caminho válido
 */
enum e_errors
{
	SUCCESS = 0,
	USAGE_ERROR,
	FILE_EXTENSION_ERROR,
	FILE_NOT_FOUND_ERROR,
	FILE_EMPTY_ERROR,
	INVALID_CHARSET_ERROR,
	INVALID_EXIT_ERROR,
	INSUFFICIENT_COLLECTIBLES_ERROR,
	INVALID_START_POINT_ERROR,
	MAP_NOT_RECTANGULAR_ERROR,
	MAP_NOT_ENCLOSED_ERROR,
	NO_VALID_PATH_ERROR
};

// Structs

typedef struct s_so_long
{
	mlx_t	*mlx;
}	t_so_long;

// Functions

/**
 * @brief Valida um arquivo de mapa do jogo.
 *
 * @param path_to_map: O caminho para o arquivo de mapa.
 *
 * @return: Retorna o código de status da operação.
 *
 * A função:
 * 1. Verifica se o arquivo tem a extensão ".ber".
 * 2. Verifica se o arquivo existe e tem permissões de leitura.
 * 3. Verifica se o arquivo não está vazio.
 * 4. Verifica se o arquivo é um mapa válido.
 */
int	validate(char *path_to_map);

/**
 * @brief Valida um arquivo de mapa do jogo.
 *
 * @param file_string: A string que representa o arquivo de mapa.
 *
 * @return: Retorna o código de status da operação.
 *
 * A função:
 * 1. Verifica se o arquivo contém apenas os caracteres '01CEP'.
 * 2. Verifica se o arquivo contém uma saída 'E'.
 * 3. Verifica se o arquivo contém pelo menos um coletável 'C'.
 * 4. Verifica se o arquivo contém apenas um ponto de partida 'P'.
 * 5. Verifica se o arquivo é retangular.
 * 6. Verifica se o arquivo é completamente cercado por paredes.
 * 7. Verifica se o arquivo tem um caminho válido.
 */
int	map_validation(char *file_string);

/**
 * @brief Realiza o preenchimento da área em um mapa representado por uma
 * string.
 *
 * @param game_map: Uma string que representa o mapa do jogo a ser preenchido.
 * @param return_code: Um ponteiro para um inteiro que será usado para retornar
 * o código de status da operação.
 *
 * @return: Retorna o código de status da operação. O código de status é
 * armazenado no local apontado por return_code.
 *
 * A função:
 * 1. Percorre todo o mapa onde é delimitado por paredes ('1') a partir
 * do start point ('P').
 *
 * 2. Verifica se todos os coletáveis ('C') e a saída ('E') foram preenchidas.
 */
int flood_fill(char *file_string, int *return_code);

#endif
