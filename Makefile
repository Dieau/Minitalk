# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 10:58:44 by alakhdar          #+#    #+#              #
#    Updated: 2022/01/25 16:18:42 by alakhdar         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS		= 	src/atoi_itoa.c src/ft_printf.c
HEADER		=	includes/minitalk.h
OBJS		= ${SRCS:.c=.o} src/server.o src/client.o

CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -rf

all : server client

server: ${HEADER} ${OBJS}
	$(CC) $(CFLAGS) src/server.c  $(SRCS) -o server
	@echo "\033[92m\n[- SERVER CREATED -]\n\033[0m"
client: ${HEADER} ${OBJS}
	$(CC) $(CFLAGS) src/client.c $(SRCS) -o client
	@echo "\033[92m\n[- CLIENT CREATED -]\n\033[0m"

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) server
	$(RM) client
	$(RM) src/*.o
	@echo "\033[91m\n[- FILES DELETED -]\n\033[0m"

fclean : clean

re : fclean all

.PHONY : all clean bonus fclean re