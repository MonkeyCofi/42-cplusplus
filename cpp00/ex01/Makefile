NAME = phonebook

SRC = PhoneBook.cpp Contact.cpp Utils.cpp main.cpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -I./ -o $(NAME)

all: $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re