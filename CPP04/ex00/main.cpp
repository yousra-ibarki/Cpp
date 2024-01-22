#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"



int main() 
{ 
    const WrongAnimal* metaa = new WrongAnimal(); 
    const WrongAnimal* ii = new WrongCat(); 
    std::cout << ii->getType() << ""<<std::endl; 
    ii->makeSound();
    metaa->makeSound(); 
    
    delete ii;
    delete metaa;

    std::cout << std::endl;
    const Animal* meta = new Animal(); 
    const Animal* j = new Dog(); 
    const Animal* i = new Cat(); 
    std::cout << j->getType() << ""<<std::endl; 
    std::cout << i->getType() << ""<<std::endl; 
    i->makeSound(); 
    j->makeSound(); 
    meta->makeSound(); 
    
    delete j;
    delete i;
    delete meta;
    return 0; 
}