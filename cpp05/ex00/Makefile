NAME = bureaucrat

SRCS = Bureaucrat.cpp main.cpp

INC = Bureaucrat.hpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I./

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: clean all