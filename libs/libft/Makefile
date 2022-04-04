# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: letumany <letumany@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 20:20:25 by letumany          #+#    #+#              #
#    Updated: 2021/07/30 22:19:58 by letumany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME		= libft.a
HEADER		= libft.h
SRCS		= $(wildcard *.c)
OBJS		= $(SRCS:.c=.o)
CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror
AR			= ar csr

#colors
COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

%.o: %.c 
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS) $(HEADER)
	@${AR} ${NAME} ${OBJS}
# @echo "$(WARN_COLOR)\t $(NAME)\t$(OK_COLOR)[CREATED]$(NO_COLOR)";


all : $(NAME)

clean :
	@$(RM) *.o
	

fclean : clean
	@$(RM) $(NAME)

re : fclean all 

