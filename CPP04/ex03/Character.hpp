#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

class AMateria;
class ICharacter;

class Character: public ICharacter{
private:
    static const int invSize = 4;
    std::string name;
    int nbr_equiped;
    AMateria* inventory[invSize];
public:
    Character();
    ~Character();
    Character(const Character& obj);  
    Character(const std::string& name);

    Character& operator=(const Character& obj);

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};


#endif