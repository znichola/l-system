# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 13:44:03 by znichola          #+#    #+#              #
#    Updated: 2022/11/22 13:44:03 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lsystem

FILES = main load utils debug

OBJ = $(addsuffix .o, $(FILES))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I.

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

algea : all
	./$(NAME) AB "" A "A AB B A"

binary : all
	./$(NAME) 10 [] 0 "1 11 0 1[0]0"

koch : all
	./$(NAME) F +- F "F F+F-F-F+F"

sierpinski : all
	./$(NAME) FG +- F-G-G "F F-G+F+G-F G GG"

.PHONEY : clean, fclean, all, re, algea, binarytree, kochcurve, sierpinski

# algea			: ./lsystem AB "" A "A AB B A"
# binary tree	: ./lsystem 10 "[]" 0 "1 11 0 1[0]0"
# koch curve	: ./lsystem F +- "F F+F-F-F+F"

# F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F
# F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F
