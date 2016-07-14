##
## Makefile for  in /home/frasse_l/Projets/abstractVM
## 
## Made by loic frasse-mathon
## Login   <frasse_l@epitech.net>
## 
## Started on  Thu Jul 14 09:00:22 2016 loic frasse-mathon
## Last update Thu Jul 14 15:10:28 2016 loic frasse-mathon
##

SRC		= src/main.cpp \
		src/Factory.cpp \
		src/Int8.cpp \
		src/Int16.cpp \
		src/Int32.cpp \
		src/Float.cpp \
		src/Double.cpp \
		src/BigDecimal.cpp \
		src/Exceptions.cpp \
		src/AbstractVM.cpp \
		src/Parsing.cpp \
		src/Cmd.cpp

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
