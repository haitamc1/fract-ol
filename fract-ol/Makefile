# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 22:44:21 by hchahid           #+#    #+#              #
#    Updated: 2022/04/26 14:18:31 by hchahid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

NAME_B = fractol_bonus

HEADER = fractol.h

HEADER_B = fractol_bonus.h

SRC = fractol.c julias.c mandelbrots.c colors.c keys.c mouse.c guides.c utils.c

SRC_B = fractol_bonus.c julias_bonus.c  mandelbrots_bonus.c  o_sets_bonus.c  colors_bonus.c \
		 keys_bonus.c  mouse_bonus.c  guides_bonus.c  utils_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

FLAGS = -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	cc -c $< 

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) -o $(NAME) 

$(NAME_B): $(OBJ_B)
	cc $(FLAGS) $(OBJ_B) -o $(NAME_B)
	

all : ${NAME}

bonus : $(SRC_B) $(OBJ_B)
	cc $(FLAGS) $(OBJ_B) -o $(NAME_B)

clean :
	rm -rf ${OBJ}
	rm -rf ${OBJ_B}

fclean : clean
	rm -rf ${NAME}
	rm -rf ${NAME_B}

re : fclean all

.PHONY: all fclean clean re