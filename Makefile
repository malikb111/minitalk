# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abbouras <abbouras@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 11:45:22 by abbouras          #+#    #+#              #
#    Updated: 2025/03/18 13:11:57 by abbouras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

LIBFT_DIR = external/libft
LIBFT     = $(LIBFT_DIR)/libft.a

CC      = gcc
# CFLAGS  = -Wall -Wextra -Werror -Iinclude -I$(LIBFT_DIR)/include
# A ENLEVER TRES IMPORTANT ---------------------------------------------------------------
CFLAGS  = -Iinclude -I$(LIBFT_DIR)/include

SRC_CLIENT = src/client/client.c src/utils/utils.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

SRC_SERVER = src/server/server.c src/utils/utils.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LIBFT)

$(NAME_SERVER): $(OBJ_SERVER)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all