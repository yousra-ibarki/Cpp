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


int main()
{
  atexit(function);
  std::cout << std::endl << "˚˚˚˚˚˚˚˚˚˚ Normal Test ˚˚˚˚˚˚˚˚˚˚" << std::endl << std::endl;
  Animal* arr[4];
    int i;
    std::cout << std::endl << "˚˚˚˚˚˚˚˚˚˚Constructors˚˚˚˚˚˚˚˚˚˚" << std::endl << std::endl;
    for(i = 0; i < 2; i++){
        arr[i] = new Dog();
    }
    for(int j = i; j < 4; j++){
        arr[j] = new Cat();
    }
    std::cout << std::endl << "˚˚˚˚˚˚˚˚˚˚Destructors˚˚˚˚˚˚˚˚˚˚" << std::endl << std::endl;
    for(i = 0; i < 4; i++){
        delete arr[i];
    }
  std::cout << std::endl << "˚˚˚˚˚˚˚˚˚˚ Deep Copy Test ˚˚˚˚˚˚˚˚˚˚" << std::endl << std::endl;

  Animal *originDog = new Dog();
  Animal *copyDog = new Dog();

  Animal *originCat = new Cat();
  Animal *copyCat = new Cat();

  std::cout << originDog->getType() << std::endl;
  std::cout << copyDog->getType() << std::endl;

  std::cout << originCat->getType() << std::endl;
  std::cout << copyCat->getType() << std::endl;

  std::cout << std::endl;

  *originCat = *copyCat;
  originCat->setType("CAAAAT");

  *originDog = *copyDog;
  originDog->setType("DOOOOG");

  std::cout << originDog->getType() << std::endl;
  std::cout << copyDog->getType() << std::endl;

  std::cout << originCat->getType() << std::endl;
  std::cout << copyCat->getType() << std::endl;

  delete copyCat;
  delete originDog;
  delete originCat;
  delete copyDog;
  return 0;
}
