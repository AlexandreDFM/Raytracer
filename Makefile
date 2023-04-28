##
## EPITECH PROJECT, 2023
## B-OOP-400-NCE-4-1-raytracer-alexandre-kevin.de-freitas-martins
## File description:
## Makefile
##

NAME		=	raytracer

INCLUDE		=	-I./Interface

SRC			=	Main.cpp				\
				src/Camera.cpp			\
				src/Point3D.cpp			\
				src/Ray.cpp				\
				src/Rectangle3D.cpp		\
				src/Sphere.cpp			\
				src/Vector3D.cpp		\

OBJ			=	$(SRC:.cpp=.o)

LDFLAGS		=

CXXFLAGS	=	-Wall -Wextra -Werror $(INCLUDE)

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LDFLAGS)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean all
