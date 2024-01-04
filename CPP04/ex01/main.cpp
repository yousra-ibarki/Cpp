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
    virtual void makeSound() const{ //why when in make makeSound = 0 it doesn't work
        std::cout << "Quack Quack!" << std::endl;
    };
    std::string getType() const{
        return type;
    }
    ~Animal(){
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
        std::cout << "Dog's Destructor" << std::endl;
        delete dog;
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
        std::cout << "Cat's Destructor" << std::endl;
        delete cat;
   }
};


int main() 
{
    // Animal* arr[100];
    // int i;
    // for(i = 0; i < 50; i++){
    //     arr[i] = new Dog();
    // }
    // for(int j = i; j < 100; j++){
    //     arr[j] = new Cat();
    // }
    // for(i = 0; i < 100; i++){
    //     delete arr[i];
    // }
    

    const Animal*j= new Dog(); 
    const Animal*i= new Cat(); 
    delete j; //should not create a leak 
    delete i; 
  //  while(1);
    return 0;
}
