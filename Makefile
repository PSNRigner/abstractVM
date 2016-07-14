##
## Makefile for  in /home/frasse_l/Projets/abstractVM
## 
## Made by loic frasse-mathon
## Login   <frasse_l@epitech.net>
## 
## Started on  Thu Jul 14 09:00:22 2016 loic frasse-mathon
## Last update Thu Jul 14 09:11:17 2016 loic frasse-mathon
##

SRC		= src/main.cpp

OBJ		= $(SRC:.cpp=.o)

NAME		= abstractVM

CXX		= g++ -g

CXXFLAGS	= -W -Wall -Werror -Wextra -I./include

RM		= rm -f

LDFLAGS		= -g

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
