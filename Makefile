# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbeauman <gbeauman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 10:54:19 by gbeauman          #+#    #+#              #
#    Updated: 2022/04/08 10:57:34 by gbeauman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
CC = gcc
SRC =	minitalk_fonctions.c\
		minitalk_fonctions_2.c\
		client_utils.c
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ)
	$(CC) $(FLAGS) server.c $(OBJ) -o $(SERVER)
$(CLIENT): $(OBJ)
	$(CC) $(FLAGS) client.c $(OBJ) -o $(CLIENT)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(SERVER) $(CLIENT)
re: fclean all
.PHONY: all clean fclean re