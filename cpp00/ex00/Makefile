NAME		= megaphone

CFLAGS		= -Wall -Wextra -Werror

CC 		= c++ -g

STANDARD_LIB	= -std=c++98

SRCS		= megaphone.cpp

OBJS 		= $(SRCS:.cpp=.o)

%.o:%.cpp
	$(CC) $(CFLAGS) $(STANDARD_LIB) $< -c -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(STANDARD_LIB) $(OBJS) -o $@


clean:
	rm -f  $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
