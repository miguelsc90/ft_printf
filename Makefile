# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misanche <misanche@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 18:56:39 by misanche          #+#    #+#              #
#    Updated: 2022/05/04 18:18:20 by misanche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

####FILES####

SRC 	=	ft_print_ptr.c ft_printf.c ft_printstr.c ft_printnbr.c ft_print_unsigned.c \
			ft_print_xdn.c ft_print_percent.c ft_print_xup.c

OBJ		=	$(SRC:%.c=%.o)

####COMPILE####

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rcs
RM		=	rm -rf

####COMPILE TARGET####

all: $(NAME)

$(NAME):$(OBJ)
		$(CC) -c $(SRC)
		$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME) $(OBJ)

re: fclean all

.PHONY: fclean all clean re
