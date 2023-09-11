# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 16:20:29 by akuzmenk          #+#    #+#              #
#    Updated: 2023/06/19 15:05:02 by akuzmenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
FLAGS := -Wall -Wextra -Werror
LIBFT_DIR := ./libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

SRCS :=	\
	main.c \
	check_map.c \
	read_map.c \
	create_player.c \
	move.c \
	draw_map.c \
	start_game.c \
	free_function.c \
	game_helpers.c \



OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -sC $(LIBFT_DIR)
	cc $(FLAGS) $(OBJS) -o $(NAME) -L. -lmlx -framework OpenGL -framework AppKit -L. $(LIBFT_LIB)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

clean:
	make clean -sC $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -sC $(LIBFT_DIR)
	rm -f $(NAME)
	
re: fclean all

.PHONY: clean fclean re