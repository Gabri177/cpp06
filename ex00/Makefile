CFILE = main.cpp ScalarConverter.cpp
OFILE = $(CFILE:.cpp=.o)
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = convert

all: $(NAME)

$(NAME): $(OFILE)
	c++ $(CPPFLAGS) -o $(NAME) $(OFILE)

%.o:%.cpp
	c++ $(CPPFLAGS) -c -Wshadow $< -o $@

clean:
	$(RM) $(OFILE)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
