NAME = intern

SRCS = Bureaucrat.cpp Form.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp Intern.cpp main.cpp

INC = Bureaucrat.hpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I./ 

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:

fclean:
	rm -f $(NAME)
	rm -f *_shrubbery

re: fclean all