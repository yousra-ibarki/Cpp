NAME = Base

SRC = main.cpp Base.cpp fnct.cpp
	
OBJ = $(SRC:.cpp=.o)

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp A.hpp B.hpp C.hpp Base.hpp fnct.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean all fclean re libft