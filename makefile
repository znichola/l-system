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

FILES = main

OBJ = $(addsuffix .o, $(FILES))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I.

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONEY : clean, fclean, all, re