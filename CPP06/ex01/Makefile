NAME = Serialization

SRC = main.cpp Serializer.cpp
	
OBJ = $(SRC:.cpp=.o)

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp Serializer.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean all fclean re libft