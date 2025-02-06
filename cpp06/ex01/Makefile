NAME = cereal

SRCS = main.cpp Serialize.cpp Data.cpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: fclean all
