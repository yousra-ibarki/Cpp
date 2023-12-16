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
    void set_value(const std::string new_name, const std::string new_type){
        name = new_name;
        weapon->setType(new_type);
    }
    void attack(){
        std::cout << name << " attacks with their " << weapon->getType();
    }

};

class HumanB{
private:
    Weapon *weapon;
    std::string name;
public:
    HumanB(){
        weapon = new Weapon;
    }
    ~HumanB(){
        delete weapon;
    }
    void set_value(const std::string new_name, const std::string new_type){
        name = new_name;
        weapon->setType(new_type);
    }
    void attack(){
        std::cout << name << " attacks with their " << weapon->getType();
    }

};

int main()
{
    HumanA human1;
    HumanB human2;
    human1.set_value("Yousra", "GOMO GOMO");
    human2.set_value("Merry", "Pistolee");
    //const std::string &ref = weapon.getType();
    //std::cout << ref;
   // std::cout << "Weapon Type: " << weapon.getType() << std::endl;
    human1.attack();
    std::cout << std::endl;
    human2.attack();
}