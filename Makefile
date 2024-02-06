# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 12:43:51 by danbarbo          #+#    #+#              #
#    Updated: 2024/02/06 18:24:30 by danbarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
# CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast		# Arrumar isso depois
CFLAGS	:= -Wunreachable-code -Ofast -g3
LIBMLX	:= lib/MLX42
LIBFT	:= lib/libft

HEADERS	:= -I ./include -I ${LIBMLX}/include -I ${LIBFT}/include
LIBS	:= ${LIBMLX}/build/libmlx42.a ${LIBFT}/libft.a \
			-ldl -lglfw -pthread -lm
SRCS	:= ${shell find src -iname "*.c"}
OBJS	:= ${SRCS:src/%.c=obj/%.o}

all: ${NAME}

libmlx:
	@cmake ${LIBMLX} -B ${LIBMLX}/build && make -C ${LIBMLX}/build -j4

libft:
	@make -C ${LIBFT} all

test: libmlx libft
	${CC} ${CFLAGS} ${HEADERS} teste/test_imagens.c teste/utils.c ${LIBS}

obj/%.o: src/%.c
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} ${HEADERS} -o $@ -c $<
	@printf "Compiling: ${notdir $<}\n"

${NAME}: libmlx libft ${OBJS}
	@${CC} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
	@rm -rf ${OBJS}
#	@rm -rf ${LIBMLX}/build				# remover o comentário depois
#	@make -C ${LIBFT} clean				# remover o comentário depois

fclean: clean
	@rm -rf ${NAME}
#	@make -C ${LIBFT} fclean			# remover o comentário depois

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft, test
