#include <iostream>

class ClapTrap{
private:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;
public:
    ClapTrap(std::string newName): name(newName), hitPoints(10), energyPoints(10), attackDamage(0) {
        std::cout << "Constructor Called\n";
    }
    ~ClapTrap(){
        std::cout << "Destructor Called\n";
    }
    void attack(const std::string& target){

    }
    void takeDamage(unsigned int amount){

    }
    void beRepaired(unsigned int amount){

    }

};


int main()
{

}