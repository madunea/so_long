# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marieduneau <marieduneau@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 11:31:57 by maduneau          #+#    #+#              #
#    Updated: 2025/01/13 13:56:43 by marieduneau      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc 
CFLAGS = -Wall -Werror -Wextra

# X11_FLAGS = -L/usr/X11/lib -lXext -lX11
# $(X11_FLAGS)

SRC = 	parsing.c\
		map_checking.c\
		main.c\
		get_map.c\
		init_game.c\
		error_message.c\
		events.c\
		player.c\
		check_valid_path.c\
		get_window.c\

OBJ = $(SRC:.c=.o)

all: $(NAME) 
	
$(NAME) : $(OBJ) libft/libft.a
	#  $(CC) $(OBJ) $(X11_FLAGS) -o $(NAME) -Llibft -lft
	$(CC) $(OBJ) -Lmlx -lmlx -lm -lz -o $(NAME) -Llibft -lft

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

libft/libft.a:
	make -C libft

mlx/mlx.a:
	make -C mlx

clean: 
	rm -f $(OBJ) 
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

.PHONY: all clean fclean re
