
NAME = PhoneBook

SRC = PhoneBook.cpp Contact.cpp main.cpp
	
OBJ = PhoneBook.o Contact.o main.o

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Wextra -Werror 

all : $(NAME)

$(NAME): $(OBJ) PhoneBook.hpp Contact.hpp
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.c 
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean all fclean re libft