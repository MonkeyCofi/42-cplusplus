NAME = forms

SRCS = Bureaucrat.cpp AForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp main.cpp

INC = Bureaucrat.hpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I./

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: clean all