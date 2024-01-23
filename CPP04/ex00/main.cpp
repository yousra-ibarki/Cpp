#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void function(){
    
}

int main() 
{ 
    atexit(function);
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
    delete j;
    delete i;
    delete meta;

    std::cout << std::endl << "°°°°°°Wrong Animals°°°°°°°°°°" << std::endl << std::endl;
    std::cout << "--Constructors--" << std::endl;
    const WrongAnimal* metaa = new WrongAnimal(); 
    const WrongAnimal* ii = new WrongCat(); 
    std::cout << std::endl << "--Wrong Animals and their Sounds--" << std::endl;
    std::cout << ii->getType() << ""<<std::endl; 
    ii->makeSound();
    metaa->makeSound(); 
    std::cout << std::endl << "--Destructors--" << std::endl;

    delete ii;
    delete metaa;
    return 0; 
}