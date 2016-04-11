# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quroulon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/31 15:34:11 by quroulon          #+#    #+#              #
#    Updated: 2016/03/31 15:34:13 by quroulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	ft_printf

CC			= 	gcc

CFLAGS		=	-g
# CFLAGS		= 	-Wall -Werror -Wextra -g

SRC 		= 	main.c ft_printf.c utilities.c flags.c lstarg.c va_list.c

LIB			=	-Llibft -lft

OBJ			=	$(SRC:.c=.o)

HEADER 		=	libft/libft.h


all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	# @make -sC libft/
	@$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	@$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo "COMPILATION DONE"

.SILENT : clean
clean:
	# @make clean -sC libft/
	@rm -f $(OBJ)
	@echo "CLEAN DONE"

.SILENT : fclean
fclean: clean
	# @make fclean -sC libft/
	@rm -f $(NAME)
	@echo "FCLEAN DONE"

re: fclean all
