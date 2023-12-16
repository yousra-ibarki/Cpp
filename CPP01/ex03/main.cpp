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
    Weapon *weapon;
    std::string name;
public:
    HumanA(){
        weapon = new Weapon;
    }
    ~HumanA(){
        delete weapon;
    }
    void set_value(const std::string new_name){
        name = new_name;
    }
    void attack(){
        std::cout << name << " attacks with their " << weapon->getType();
    }

};

// class HumanB{
// private:
//     Weapon weapon;
//     std::string name;
// public:
//     void attack(){
//         std::cout << name << " attacks with their " << weapon.getType();
//     }

// };

int main()
{
    Weapon weapon;
    HumanA human1;

    human1.set_value("human1");
    weapon.setType("GOMO GOMO");
    //const std::string &ref = weapon.getType();
    //std::cout << ref;
   // std::cout << "Weapon Type: " << weapon.getType() << std::endl;
    human1.set_value("Yousra");
    human1.attack();
}