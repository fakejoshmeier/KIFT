# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 15:39:41 by rzarate           #+#    #+#              #
#    Updated: 2018/04/15 20:23:41 by rzarate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME		=	server
CLIENT_NAME		=	client
SERVER_SRCDIR	=	srcs/server/
CLIENT_SRCDIR	=	srcs/client/
INCDIR			= 	includes/
LIBFT			=	libft/
CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra

SERVER_FILES	=	server.c \
					process_command.c \
					commands_0.c \
					commands_1.c \
					commands_2.c \
					utilities.c

CLIENT_FILES	=	client.c \
					utilities.c
 
SERVER_SRCS		=	$(addprefix $(SERVER_SRCDIR), $(SERVER_FILES))
CLIENT_SRCS		=	$(addprefix $(CLIENT_SRCDIR), $(CLIENT_FILES))

all: library $(SERVER_NAME) $(CLIENT_NAME)

library:
	@echo "\x1b[31m\nRecompiling libft...\x1b[0m"
	@make re -C $(LIBFT)
	@echo "\x1b[32mDone\x1b[0m"

$(SERVER_NAME):
	@echo "\x1b[31m\nCompiling server...\x1b[0m"
	@$(CC) $(FLAGS) -I $(INCDIR) $(SERVER_SRCS) $(LIBFT)libft.a -o $(SERVER_NAME)
	@echo "\x1b[32mDone\x1b[0m"

$(CLIENT_NAME):
	@echo "\x1b[31m\nCompiling client...\x1b[0m"
	@$(CC) $(FLAGS) -I $(INCDIR) $(CLIENT_SRCS) $(LIBFT)libft.a -o $(CLIENT_NAME)
	@echo "\x1b[32mDone\x1b[0m"

clean:
	@echo "\x1b[31mCleaning...\x1b[0m"
	@rm -f *.o
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(CLIENT_NAME) $(SERVER_NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all test clean fclean re
