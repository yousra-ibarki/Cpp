NAME = Interface

SRC = main.cpp Cure.cpp Ice.cpp  AMateria.cpp Character.cpp MateriaSource.cpp
	
OBJ = $(SRC:.cpp=.o)

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp ./Includes/Cure.cpp ./Includes/Ice.hpp ./Includes/Icharacter.hpp  ./Includes/AMateria.hpp ./Includes/Character.hpp ./Includes/MateriaSource.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean all fclean re libft