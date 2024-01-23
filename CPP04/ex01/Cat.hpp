#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain* CatBrain;
public:
    Cat();
    ~Cat();

    void setType(const std::string name){
        this->type = name;
    }
    Cat(const Cat &obj);
    Cat &operator=(const Cat &obj);
    
    void makeSound() const;
    Brain* getBrain() const;
};

#endif