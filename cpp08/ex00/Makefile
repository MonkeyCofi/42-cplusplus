NAME = easyfind

SRCS = main.cpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I./

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $< -o $@

all: $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re