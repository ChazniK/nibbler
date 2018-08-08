# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/26 10:14:37 by mafernan          #+#    #+#              #
#    Updated: 2018/08/08 10:20:46 by mafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang++ -stdlib=libc++ -std=c++11

OUT= -o sfml.so

RPATH= -Wl,-rpath,$(PWD)/SFML/Frameworks

SHAREFLAGS= -shared -fPIC

FRAMEWORKS= -framework sfml-graphics -framework sfml-window -framework sfml-system

FRAMEWORK_PATH= -F SFML/Frameworks

INCL= -I includes -I SFML/include -I SFML/lib

SRCS= Game.cpp Snake.cpp Window.cpp World.cpp interface.cpp

all:
	@echo "Compiling dylib for SFML"
	@$(CC) $(RPATH) $(SHAREFLAGS) $(FRAMEWORKS) $(FRAMEWORK_PATH) $(SRCS) $(OUT) $(INCL)
	@mv sfml.so ../bin/.
	@echo "Created /bin/sfml.so"

