# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 16:35:38 by ckatz             #+#    #+#              #
#    Updated: 2018/07/25 12:41:34 by ckatz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pong
SRCS = Main.cpp Snake.cpp
OBJS = Main.o Snake.o
CXX = clang++
FLAGS = -stdlib=libc++
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
