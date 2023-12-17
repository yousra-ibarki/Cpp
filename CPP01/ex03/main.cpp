#include <iostream>

class Weapon
{
private:
    std::string type;

public:
    Weapon(std::string new_name){
        type = new_name; 
    }
    // ~Weapon(){}
    void setType(std::string new_type)
    {
        type = new_type;
    }
    const std::string &getType(void) const
    {
        return type;
    }
};

class HumanA
{
private:
    Weapon *weapon;
    std::string name;

public:
    HumanA(std::string new_name, Weapon new_type)
    {
        name = new_name;
        //weapon->setType(new_type);
        weapon = &new_type;
    }
    // ~HumanA()
    // {
    //     delete weapon;
    // }
    // void setWeapon(const std::string new_name, Weapon new_type)
    // {
    //     name = new_name;
    //     //weapon->setType(new_type);
    //     weapon = &new_type;
    // }
    void attack()
    {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    }
};

class HumanB
{
private:
    Weapon *weapon;
    std::string name;

public:
    HumanB(std::string new_name)
    {
        //weapon = new Weapon;
        name = new_name;
    }
    // ~HumanB()
    // {
    //     delete weapon;
    // }
    void setWeapon(Weapon new_weapon)
    {
       // name = new_name;
       weapon = &new_weapon;
    }
    void attack()
    {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    }
};

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    while(1);
    return 0;
}