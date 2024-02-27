# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maax <maax@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 11:37:04 by maax              #+#    #+#              #
#    Updated: 2024/02/12 15:02:24 by maax             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_SERVER = src/server.c
SRC_CLIENT = src/client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

NAME_SERVER = server
NAME_CLIENT = client

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER) -L./libft/ -lft

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT) -L./libft/ -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C libft
	rm -rf $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	$(MAKE) fclean -C libft
	rm -rf $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all