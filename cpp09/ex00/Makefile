NAME = btc

SRCS = BitCoinExchange.cpp main.cpp

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re