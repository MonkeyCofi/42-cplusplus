NAME = intern

SRCS = Bureaucrat.cpp AForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp main.cpp Intern.cpp

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