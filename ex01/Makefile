NAME	= PhoneBook

CC		= c++ -g

CFLAGS	= -Wall -Wextra -Werror 

STD_LIB	= -std=c++98

SRC		=  utils.cpp Contact.cpp PhoneBook.cpp main.cpp

OBJS	= $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) $(STD_LIB) $< -c -o $@


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(STD_LIB) $(OBJS) -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
