NAME = bureaucrat

SRCS = Bureaucrat.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

INC = Bureaucrat.hpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I./

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: all clean