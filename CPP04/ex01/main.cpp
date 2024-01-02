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
        std::cout << "Dog's Constructor" << std::endl;
        type = "Dog";
    }

    void makeSound() const {
        std::cout << "Woof Woof!" << std::endl;
    }
   
};

class Cat : public Animal{
public:
   Cat(){
    std::cout << "Cat's Constructor" << std::endl;
    type = "Cat";
   }

   void makeSound() const {
    std::cout << "Meow Meow!" << std::endl;
   }
};

class Brain{
private:
    std::string ideas[100];

public:
    Brain(){
        std::cout << "Brain's Constructor" << std::endl;
    }
    ~Brain(){
        std::cout << "Brain's Destructor" << std::endl;
    }

};

int main() 
{ 
    Animal 
    // const Animal*j= new Dog(); 
    // const Animal*i= new Cat(); 
    // delete j; //should not create a leak 
    // delete i; 
    return 0;
}