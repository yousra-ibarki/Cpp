#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() 
{ 
    std::cout << std::endl << "°°°°°°°°°°Right Animals°°°°°°°°°°" << std::endl << std::endl;
    std::cout << "--Constructors--" << std::endl;
    const Animal* meta = new Animal(); 
    const Animal* j = new Dog(); 
    const Animal* i = new Cat(); 
    std::cout << std::endl << "--Animals and their Sounds--" << std::endl;

    std::cout << j->getType() << ""<<std::endl; 
    std::cout << i->getType() << ""<<std::endl; 
    i->makeSound(); 
    j->makeSound(); 
    meta->makeSound();
    std::cout << std::endl << "--Destructors--" << std::endl;
    delete i;
    delete j;
    delete meta;

    std::cout << std::endl << "°°°°°°Wrong Animals°°°°°°°°°°" << std::endl << std::endl;
    std::cout << "--Constructors--" << std::endl;

    const WrongAnimal* worngCat = new WrongCat(); 

    std::cout << std::endl << "--Wrong Animal--" << std::endl;

    std::cout << worngCat->getType() << ""<<std::endl; 
    worngCat->makeSound();
    
    std::cout << std::endl << "--Destructors--" << std::endl;

    delete worngCat;
    return 0; 
}