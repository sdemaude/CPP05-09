# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdemaude <sdemaude@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:52:25 by sdemaude          #+#    #+#              #
#    Updated: 2024/08/03 13:11:53 by sdemaude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02 
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
OBJ = $(SRC:.cpp=.o)

SRC = main.cpp\
	  Bureaucrat.cpp\
	  AForm.cpp\
	  ShrubberyCreationForm.cpp\
	  RobotomyRequestForm.cpp\
	  PresidentialPardonForm.cpp

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
