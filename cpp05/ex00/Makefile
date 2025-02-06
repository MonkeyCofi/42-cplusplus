NAME = bureaucrat

SRCS = Bureaucrat.cpp main.cpp

INC = Bureaucrat.hpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I./

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: all clean