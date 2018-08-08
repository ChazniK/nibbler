# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/08 08:06:27 by ckatz             #+#    #+#              #
#    Updated: 2018/08/08 08:06:49 by ckatz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = nibbler
SRCS = Main.cpp Game.cpp Window.cpp Snake.cpp World.cpp
OBJS = Main.o Game.o Window.o Snake.o World.o
CXX = clang++
FLAGS = -stdlib=libc++ -std=c++11
PATH = /goinfre/ckatz/.brew/Cellar/sfml/2.4.2_1
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: $(NAME)

$(OBJS): $(SRCS)
	$(CXX) -c $(SRCS) -I $(PATH)/include $(FLAGS)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME) -L $(PATH)/lib $(SFML_FLAGS)

run:
	export LD_LIBRARY_PATH=$(PATH)/lib && ./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all