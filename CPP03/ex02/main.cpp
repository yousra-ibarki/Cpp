#include <iostream>

class ClapTrap{
private:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;
public:
    ClapTrap(std::string newName): name(newName), hitPoints(10), energyPoints(10), attackDamage(0) {
        std::cout << "ClapTrap's Constructor Called\n";
    }
    ~ClapTrap(){
        std::cout << "ClapTrap's Destructor Called\n";
    }
    void setVal(int newHitPoints, int newEnergyPoints, int newAttackDamage){
        hitPoints = newHitPoints;
        energyPoints = newEnergyPoints;
        attackDamage = newAttackDamage;
    }
    int getVal(){
        return attackDamage;
    }
    // ClapTrap(ClapTrap& cpyObj){
    //     std::cout << "Copy Constructor Called\n";
    //     this->name = cpyObj.name;
    //     this->hitPoints = cpyObj.hitPoints;
    //     this->energyPoints = cpyObj.energyPoints;
    //     this->attackDamage = cpyObj.attackDamage;
    // }

    void attack(const std::string& target){
        if(energyPoints > 0)
            energyPoints -= 1;
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
    void takeDamage(unsigned int amount){
        if(hitPoints > 0)
            hitPoints -= amount;
        std::cout << "ClapTrap " << name << " took " << amount << " amount of damage" << std::endl;
    }
    void beRepaired(unsigned int amount){
        if(energyPoints > 0 && hitPoints > 0){
            hitPoints += amount;
            energyPoints -= 1;
        }
        std::cout << "ClapTrap " << name << " get " << amount << " amout of repaired points" << std::endl;
    }
};

class ScavTrap: public ClapTrap{
public:
    ScavTrap(std::string name, ClapTrap& obj): ClapTrap(name){
        obj.setVal(100, 50, 2);
        std::cout << "ScavTrap's Constructor called" << std::endl;
    }
    ~ScavTrap(){
        std::cout << "ScavTrap's Destructor called" << std::endl;
    }

    void guardGate(){
        std::cout << "ScavTrap is now  in Gate keeper mode." << std::endl;
    }
//     void updateAttribute(ClapTrap& obj){
//         std::cout << obj.getVal() << std::endl;
//         obj.setVal(100, 50, 20);
//         std::cout << obj.getVal() << std::endl;
//    }
};


int main()
{
    ClapTrap targ("yousra");
    targ.attack("nourdin");
    targ.takeDamage(4);
    targ.beRepaired(3);

    ScavTrap hel("khadija", targ);
    hel.attack("hibe");
    hel.takeDamage(19);
    hel.beRepaired(29);
}