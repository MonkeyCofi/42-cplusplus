NAME = PmergeMe

SRCS = PmergeMe.cpp main.cpp

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
