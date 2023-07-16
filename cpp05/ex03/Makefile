NAME	= bureaucrat 

CC		= c++

CFLAGS	= -Wall -Wextra -Werror -g

STDLIB	= -std=c++98

SRC		= main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
		 RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp

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
	gdb --tui $(NAME)

v: all
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re

