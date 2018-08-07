NAME = nibbler
SRCS = Main.cpp Game.cpp Window.cpp Snake.cpp World.cpp
OBJS = Main.o Game.o Window.o Snake.o World.o
CXX = g++
FLAGS = -std=c++11
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: $(NAME)

$(OBJS): $(SRCS)
	$(CXX) -c $(SRCS) $(FLAGS)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(SFML_FLAGS)
	./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
