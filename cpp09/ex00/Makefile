NAME	= btc 

CC		= c++

CFLAGS	= -Wall -Wextra -Werror -g

STDLIB	= -std=c++98

SRC	= main.cpp BitcoinExchange.cpp

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
	gdb --tui --args $(NAME) pdf.txt

v: all
	valgrind --leak-check=full --track-fds=yes ./$(NAME) pdf.txt

.PHONY: all clean fclean re
