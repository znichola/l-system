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
	./$(NAME) 7 AB "" A "A AB B A"

binary : all
	./$(NAME) 3 10 [] 0 "1 11 0 1[0]0"

cantor : all
	./$(NAME) 3 AB "" A "A ABA B BBB"

koch : all
	./$(NAME) 2 F +- F "F F+F-F-F+F"

sierpinski : all
	./$(NAME) 3 FG +- F-G-G "F F-G+F+G-F G GG"

.PHONEY : clean, fclean, all, re, algea, binary, cantor, koch, sierpinski

# algea			: ./lsystem AB "" A "A AB B A"
# binary tree	: ./lsystem 10 "[]" 0 "1 11 0 1[0]0"
# koch curve	: ./lsystem F +- "F F+F-F-F+F"

# algea 		n = 7 : ABAABABAABAABABAABABAABAABABAABAAB
# binary		n = 3 : 1111[11[1[0]0]1[0]0]11[1[0]0]1[0]0
# kock			n = 2 : F+F-F-F+F+F+F-F-F+F-F+F-F-F+F-F+F-F-F+F+F+F-F-F+F
# F-G+F+G-F-GG+F-G+F+G-F+GG-F-G+F+G-F