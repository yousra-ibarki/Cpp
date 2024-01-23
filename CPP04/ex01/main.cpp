#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void function()
{
  system("leaks IDontWantToSetTheWorldOnFire");
}

// int main()
// {
//     //atexit(function);
//     Animal* arr[10];
//     int i;
//     for(i = 0; i < 5; i++){
//         arr[i] = new Dog();
//     }
//     for(int j = i; j < 10; j++){
//         arr[j] = new Cat();
//     }
//     for(i = 0; i < 10; i++){
//         delete arr[i];
//     }
//  return 0;
// }

int main()
{
  atexit(function);

  Animal *origin = new Dog();
  Animal *copy = new Dog();
  Animal *extra = new Cat();

  std::cout << origin->getType() << std::endl;
  std::cout << copy->getType() << std::endl;
  std::cout << extra->getType() << std::endl;

  std::cout << std::endl;

  *origin = *copy;
  copy->setType("DOOOOG");

  std::cout << origin->getType() << std::endl;
  std::cout << extra->getType() << std::endl;
  std::cout << copy->getType() << std::endl;

  delete origin;
  delete extra;
  delete copy;
  return 0;
}


// int main()
// {
//   atexit(function);
//   Animal *origin = new Cat();
//   Animal *copy = new Cat();

//   std::cout << origin->getType() << std::endl;
//   std::cout << copy->getType() << std::endl;

//   std::cout << std::endl;

//   *origin = *copy;  
//   origin->setType("CAAAT");

//   std::cout << origin->getType() << std::endl;
//   std::cout << copy->getType() << std::endl;

//   delete copy;
//   delete origin;
//   return 0;
// }
