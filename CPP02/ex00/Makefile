NAME = Orthodox

SRC = main.cpp Fixed.cpp
	
OBJ = main.o Fixed.o

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Wextra -Werror 

all : $(NAME)

$(NAME): $(OBJ) 
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp Fixed.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean all fclean re