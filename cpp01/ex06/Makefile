NAME	= harlFilter

CC		= c++

CFLAGS	= -Wall -Wextra -Werror -g

STDLIB	= -std=c++98

SRC		= main.cpp Harl.cpp 

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
	gdb --tui --args $(NAME) arquivo ds ds

v: $(NAME)
	valgrind --leak-check=full ./$(NAME) arquivo aaaa oo

v1: $(NAME)
	valgrind --leak-check=full ./$(NAME) arquivo  aaaa aaaa

.PHONY: all clean fclean re
