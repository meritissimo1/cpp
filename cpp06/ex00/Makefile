NAME	= casting 

CC		= c++

CFLAGS	= -Wall -Wextra -Werror -g

STDLIB	= -std=c++98

SRC		= ScalarConverter.cpp main.cpp

OBJS	= $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) $(STDLIB) $< -c -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(STDLIB) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS)
	rm -rf $(NAME)

re: fclean all

d: all
	gdb --tui --args $(NAME) a

v: all
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re

