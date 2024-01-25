#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{

  Animal *arr[4];
  int i;
  std::cout << std::endl
            << "˚˚˚˚˚˚˚˚˚˚Constructors˚˚˚˚˚˚˚˚˚˚" << std::endl
            << std::endl;
  for (i = 0; i < 2; i++)
  {
    arr[i] = new Dog();
  }
  for (int j = i; j < 4; j++)
  {
    arr[j] = new Cat();
  }
  std::cout << std::endl;
  
  std::cout << "°°°°°°°°°°The Brain Animal and Deep Copy°°°°°°°°°" << std::endl << std::endl;

  Cat *cat = new Cat();

  cat->getBrain()->ideas[0] = "Nap mode activated";
  cat->getBrain()->ideas[1] = "Tuna time! Meowlicious.";
  std::cout << std::endl;

  std::cout << cat->getBrain()->ideas[0] << std::endl;
  std::cout << cat->getBrain()->ideas[1] << std::endl;
  std::cout << std::endl;

  Cat *caat = new Cat();

  *caat = *cat;
  cat->getBrain()->ideas[0] = "Nap mode Desactivated";
  cat->getBrain()->ideas[1] = "Chicken time! Meowlicious";

  std::cout << std::endl;
  std::cout << cat->getBrain()->ideas[0] << std::endl;
  std::cout << cat->getBrain()->ideas[1] << std::endl;

  std::cout << std::endl;
  std::cout << caat->getBrain()->ideas[0] << std::endl;
  std::cout << caat->getBrain()->ideas[1] << std::endl;

  std::cout << std::endl;

  std::cout << "˚˚˚˚˚˚˚˚˚˚Destructors˚˚˚˚˚˚˚˚˚˚" << std::endl << std::endl;
  for (i = 0; i < 4; i++)
  {
    delete arr[i];
  }

  std::cout << std::endl;

  delete cat;
  delete caat;
  return 0;
}





// int main() 
// {
//     const Animal* j= new Dog();
//     const Animal* i= new Cat(); 
//     std::cout << std::endl;
//     j->makeSound();
//     i->makeSound();

//     std::cout << std::endl;
//     delete j;
//     delete i; 
//     return 0;
// }