NAME = real_type

SRCS = main.cpp Base.cpp A.cpp B.cpp C.cpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: fclean all
