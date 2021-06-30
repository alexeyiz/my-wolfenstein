# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichariss <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 23:14:20 by ichariss          #+#    #+#              #
#    Updated: 2021/03/18 14:49:40 by ichariss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
CCFLAG = -Wall - Wextra - Werror
MLX = mlxopengl
LXFLAG = -lmlx -framework OpenGL -framework AppKit
HEADER = cub3d.h
SRC =  ./files/main.c ./files/init.c ./files/bitmap.c ./files/parcer.c \
	   ./files/parcer2.c ./files/parcer3.c ./files/get_next_line.c ./files/using.c \
	   ./files/using2.c ./files/sprite.c ./files/pusk.c ./files/pusk2.c \
	   ./files/using3.c ./files/using4.c ./files/using5.c ./files/using6.c \
	   ./files/using7.c ./files/using8.c ./files/using9.c ./files/other.c \
	   ./files/other1.c ./files/other2.c
OBJ = $(SRC:.c=.o)
.PHONY: all, clean, fclean, re
all: $(NAME)
$(NAME): $(OBJ)
	$(CC) -g -o $(NAME) -L $(MLX) $(LXFLAG) $(SRC)
clean:
	rm -rf $(OBJ)
	rm -f bitmap.bmp
fclean: clean
	rm -f $(NAME)
re : fclean all

