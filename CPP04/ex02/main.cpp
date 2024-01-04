#include <iostream>
#include <string>


class Brain{
private:
    std::string ideas[100];

public:
    Brain(){
        for(int i = 0; i < 100; i++){
            ideas[i] = "";
        }
        std::cout << "Brain's Constructor" << std::endl;
    }
    ~Brain(){
        std::cout << "Brain's Destructor" << std::endl;
    }

};


class Animal{
protected:
    std::string type;
public:
    Animal(){
        std::cout << "Animal's Constructor" << std::endl;
    }
    virtual void makeSound() const = 0;
    // { //why when in make makeSound = 0 it doesn't work
    //     std::cout << "Quack Quack!" << std::endl;
    // }
    std::string getType() const{
        return type;
    }
    virtual ~Animal(){
        std::cout << "Animal's Destructor" << std::endl;
    }
};

class Dog : public Animal{
private:
    Brain *dog;
public:
    Dog(){
        dog = new Brain();
        std::cout << "Dog's Constructor" << std::endl;
        type = "Dog";
    }

    void makeSound() const {
        std::cout << "Woof Woof!" << std::endl;
    }
   ~Dog(){
        delete dog;
        std::cout << "Dog's Destructor" << std::endl;
    }
   
};

class Cat : public Animal{
private:
    Brain *cat;
public:
   Cat(){
    cat = new Brain();
    std::cout << "Cat's Constructor" << std::endl;
    type = "Cat";
   }
   void makeSound() const {
    std::cout << "Meow Meow!" << std::endl;
   }
   ~Cat(){
        delete cat;
        std::cout << "Cat's Destructor" << std::endl;
   }
};


int main() 
{
    // const Animal* meta = new Animal;
    const Animal* j= new Dog(); 
    const Animal* i= new Cat(); 
    delete j; //should not create a leak 
    delete i; 
    return 0;
}