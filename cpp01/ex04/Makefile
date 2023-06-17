NAME	= replace

CC		= c++

CFLAGS	= -Wall -Wextra -Werror -g

STDLIB	= -std=c++98

SRC		= main.cpp 

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

d: $(NAME)
	gdb --tui --args $(NAME) a a b

v: $(NAME)
	valgrind --leak-check=full ./$(NAME) a a a

v1: $(NAME)
	

.PHONY: all clean fclean re
