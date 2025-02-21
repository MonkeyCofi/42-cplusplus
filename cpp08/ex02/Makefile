NAME = stack

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp
	
$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $(NAME)

all: $(NAME)

clean:
	rm -f $(NAME)
	
fclean: clean
	
re: fclean all

.PHONY: all clean fclean re
