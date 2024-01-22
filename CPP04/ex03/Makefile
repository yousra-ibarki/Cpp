NAME = Interface

SRC = main.cpp Cure.cpp Ice.cpp Interface.cpp Icharacter.cpp  AMateria.cpp
	
OBJ = $(SRC:.cpp=.o)

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp Cure.cpp Ice.hpp Interface.hpp Icharacter.hpp  AMateria.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean all fclean re libft