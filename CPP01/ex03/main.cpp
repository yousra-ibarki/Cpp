#include <iostream>

class Weapon {
private:
    std::string type;

public:
    // Weapon(){}
    // ~Weapon(){}
    void setType(std::string new_type){
        type = new_type;
    }
    const std::string &getType(void) const{
        return type;
    }
};

class HumanA{
private:
    Weapon weapon;
    std::string name;
public:
    HumanA(){
        
    }
    void attack(){
        std::cout << name << " attacks with their " << weapon.getType();
    }

};

class HumanB{
private:
    Weapon weapon;
    std::string name;
public:
    void attack(){
        std::cout << name << " attacks with their " << weapon.getType();
    }

};

int main()
{
    Weapon weapon;
    weapon.setType("Hello");
    const std::string &ref = weapon.getType();
    std::cout << ref;
}