# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maax <maax@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 10:58:48 by maax              #+#    #+#              #
#    Updated: 2024/03/07 13:38:42 by maax             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------- PROJECT --------------------#
NAME = libft.a

#--------------------- FLAGS ---------------------#
CC = 		gcc
CFLAGS =	-Wall -Wextra -Werror
RM = rm 	-rf
IFLGS =		-I $(HDR_DIR)
DFLGS =		-MMD -MP -O1

#------------------ DIRECTORIES ------------------#
SRC_DIR = 		src
HDR_DIR	=		inc
OBJ_DIR = 		obj
LIBFT_DIR =		libft
FT_PRINTF_DIR =	ft_printf

#----------------- SOURCE FILES ------------------#
SRC_FLS =	$(LIBFT_FLS)\
			$(FT_PRINTF_FLS)\

LIBFT_FLS = $(LIBFT_DIR)/ft_atoi.c\
			$(LIBFT_DIR)/ft_memset.c\
			$(LIBFT_DIR)/ft_putchar_fd.c\
			$(LIBFT_DIR)/ft_putnbr_fd.c\
			$(LIBFT_DIR)/ft_putstr_fd.c\
			$(LIBFT_DIR)/ft_strdup.c\
			$(LIBFT_DIR)/ft_strjoin_and_free.c\
			$(LIBFT_DIR)/ft_strlen.c\

FT_PRINTF_FLS =	$(FT_PRINTF_DIR)/ft_printf.c\
				$(FT_PRINTF_DIR)/utils_nbr.c\
				$(FT_PRINTF_DIR)/utils_str.c\

#------------------ FILES PATH -------------------#
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

#--------------------- RULES ---------------------#
all: $(NAME)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLGS) $(DFLGS) -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(LIBFT_DIR)
	mkdir -p $(OBJ_DIR)/$(FT_PRINTF_DIR)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all