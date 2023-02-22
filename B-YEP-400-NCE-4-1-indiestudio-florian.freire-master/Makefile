##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

NAME =	a

SRC	 =	src/main.cpp \
		src/Core.cpp \
		src/Scene.cpp \
		src/Saving.cpp \
		src/Player.cpp \
		src/Button.cpp \
		src/Scene/End.cpp \
		src/Scene/Settings.cpp \
		src/Scene/Menu.cpp \
		src/Scene/Game.cpp \
		src/Game/MainGame.cpp \
		src/Game/GameObjects/AObjects.cpp \
		src/Game/GameObjects/BomberMan.cpp \
		src/Game/GameObjects/Bombes.cpp \
		src/Game/GameObjects/Box.cpp \
		src/Game/GameObjects/PowerUp.cpp \
		src/Game/GameObjects/Wall.cpp \

OBJS		=	$(SRC:.cpp=.o)

CFLAGS		=	-g3 -Wall -Wextra -Werror

all:	$(OBJS)
	g++ -o $(NAME) $(OBJS) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all