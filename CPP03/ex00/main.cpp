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
    ClapTrap(ClapTrap& cpyObj){
        std::cout << "Copy Constructor Called\n";
        this->name = cpyObj.name;
        this->hitPoints = cpyObj.hitPoints;
        this->energyPoints = cpyObj.energyPoints;
        this->attackDamage = cpyObj.attackDamage;
    }

    void attack(const std::string& target){
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        if(energyPoints > 0)
            energyPoints -= 1;
    }
    void takeDamage(unsigned int amount){
        std::cout << "ClapTrap " << name << " took " << amount << " amount of damage" << std::endl;
        if(hitPoints > 0)
            hitPoints -= amount;
    }
    void beRepaired(unsigned int amount){
        std::cout << "ClapTrap " << name << " get " << amount << " amout of repaired points" << std::endl;
        if(energyPoints > 0 && hitPoints > 0){
            hitPoints += amount;
            energyPoints -= 1;
        }
    }
};


int main()
{
    ClapTrap targ("yousra");
    targ.attack("nourdin");
    targ.takeDamage(4);
    targ.beRepaired(3);
}