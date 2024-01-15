NAME = Aaaaand...OPEN!

SRC = main.cpp ClapTrap.cpp
	
OBJ = main.o ClapTrap.o

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Wextra -Werror 

all : $(NAME)

$(NAME): $(OBJ) ClapTrap.hpp
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.c 
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean all fclean re libft