#include "ScalarConverter.hpp"

int main(int ac, char **av)
{

   if (ac > 1)
   {
      try
      {
         ScalarConverter::convert(av[1]);
      }
      catch (std::invalid_argument &e)
      {
         std::cout << "invalide arguments " << e.what() << std::endl;
      }
      catch (std::out_of_range &e)
      {
         std::cout << "out of range " << e.what() << std::endl;
      }
   }
   else  
      std::cout << "Error: Enter A Parameter" << std::endl;
   return 0;
}
   