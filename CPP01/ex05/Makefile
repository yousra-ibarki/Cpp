NAME = Harl

SRC = main.cpp Harl.cpp

OBJ = main.o Harl.o

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Wextra -Werror 

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp Harl.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean all fclean re libft