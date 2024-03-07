# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maax <maax@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 11:37:04 by maax              #+#    #+#              #
#    Updated: 2024/03/07 11:44:01 by maax             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_SERVER = src/server.c
SRC_CLIENT = src/client.c
SRC_SERVER_BONUS = src/server_bonus.c
SRC_CLIENT_BONUS = src/client_bonus.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER) -L./libft/ -lft

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT) -L./libft/ -lft

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) -o $(NAME_SERVER) -L./libft/ -lft

$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) -o $(NAME_CLIENT) -L./libft/ -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C libft
	rm -rf $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean: clean
	$(MAKE) fclean -C libft
	rm -rf $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all