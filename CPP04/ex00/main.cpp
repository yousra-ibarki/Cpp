#include <iostream>
#include <string>

class Animal{
protected:
    std::string type;
public:
    virtual void makeSound() const = 0;

    std::string getType() const{
        return type;
    }
};

class Dog : public Animal{
public:
    Dog(){
        type = "Dog";
    }

    void makeSound() const {
        std::cout << "Woof Woof!" << std::endl;
    }
   
};

class Cat : public Animal{
public:
   Cat(){
    type = "Cat";
   }
   void makeSound() const {
    std::cout << "Meow Meow!" << std::endl;
   }
};

int main() 
{ 
    //const Animal* meta = new Animal(); 
    const Animal* j = new Dog(); 
    const Animal* i = new Cat(); 
    std::cout << j->getType() << ""<<std::endl; 
    std::cout << i->getType() << ""<<std::endl; 
    i->makeSound(); //willoutputthecatsound! 
    j->makeSound(); 
    // meta->makeSound(); 
    
    // delete j;
    // delete i;
    // delete meta;
    return 0; 
}