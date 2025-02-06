NAME = easyfind

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I./

SRCS = main.cpp

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re