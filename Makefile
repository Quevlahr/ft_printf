# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/31 15:34:11 by quroulon          #+#    #+#              #
#    Updated: 2016/05/11 18:18:46 by quroulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libftprintf.a

CC			= 	gcc

# CFLAGS		=	-g
# CFLAGS		= 	-Wall -Werror -Wextra

SRC 		= 	ft_printf.c utilities.c flags.c va_list.c ft_space.c ft_forstr.c \
				flags_application.c flags_application2.c ft_init.c ft_gestion.c

SRCPRINTF	=	$(wildcard libft_ull/*.c)

SRCLIBFT	=	$(wildcard libft/*.c)

LIB			=	-Llibft -lft

OBJ			=	$(SRC:.c=.o) $(notdir $(SRCLIBFT:.c=.o)) $(notdir $(SRCPRINTF:.c=.o))

HEADER 		=	libft/libft.h


all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	# @make -sC libft/
	@$(CC) $(CFLAGS) -c -I $(HEADER) $(SRC) $(SRCPRINTF) $(SRCLIBFT)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	# @$(CC) -o $(NAME) $(OBJ) $(LIB)
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
