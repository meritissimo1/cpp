NAME	= phonebook

CC		= c++ -g

CFLAGS	= -Wall -Wextra -Werror 

STD_LIB	= -std=c++98

SRC	= phonebook.cpp

OBJS	= $(SRC:.cpp=.o)

%.o = %.cpp
	$(CC) $(CFLAGS) $(STD_LIB) $< -c -o $@


all: $(NAME)

