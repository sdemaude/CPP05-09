# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:52:25 by sdemaude          #+#    #+#              #
#    Updated: 2024/08/06 10:05:19 by sdemaude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02 
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
OBJ = $(SRC:.cpp=.o)

SRC = main.cpp

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

c: all clean

.PHONY: all clean fclean re bonus c
