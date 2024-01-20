#include "Animal.hpp"
#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = "";
    }
    std::cout << "Brain's Constructor" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain's Destructor" << std::endl;
}

Brain::Brain(const Brain& obj){
    *this = obj;
}

// Brain& Brain::operator=(const Brain& obj){
//     if(this != &obj)
//         this->
//     return *this;
// }
