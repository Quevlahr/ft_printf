# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/31 15:34:11 by quroulon          #+#    #+#              #
#    Updated: 2016/06/03 16:32:05 by quroulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libftprintf.a

CC			= 	gcc

CFLAGS		= 	-Wall -Werror -Wextra

SRC			=	$(wildcard *.c)

SRCPRINTF	=	$(wildcard libft_ull/*.c)

SRCLIBFT	=	$(wildcard libft/*.c)

LIB			=	-Llibft -lft

OBJ			=	$(SRC:.c=.o) $(notdir $(SRCLIBFT:.c=.o)) $(notdir $(SRCPRINTF:.c=.o))

HEADER 		=	ft_printf.h libft/libft.h


all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	@make -sC libft/
	@$(CC) $(CFLAGS) -c -I $(HEADER) $(SRC) $(SRCPRINTF) $(SRCLIBFT)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "COMPILATION DONE"

.SILENT : clean
clean:
	@make clean -sC libft/
	@rm -f $(OBJ)
	@echo "CLEAN DONE"

.SILENT : fclean
fclean: clean
	@make fclean -sC libft/
	@rm -f $(NAME)
	@echo "FCLEAN DONE"

re: fclean all
