#include "Character.hpp"

Character::Character() {}

Character::Character(const Character &obj)
{
    *this = obj;
}
Character::Character(const std::string &name)
{
    this->name = name;
    this->nbr_equiped = 0;
    for (int i = 0; i < this->invSize; i++)
    {
        this->inventory[i] = 0;
    }
}

Character &Character::operator=(const Character &obj)
{
    if (this != &obj)
    {
        this->name = obj.name;
        this->nbr_equiped = obj.nbr_equiped;
        for (int i = 0; i < this->invSize; i++)
        {
            this->inventory[i] = obj.inventory[i]->clone(); // add somthing
        }
    };
    return *this;
}

std::string const &Character::getName() const
{
    return this->name;
    ;
}
void Character::equip(AMateria *m)
{
    if (this->nbr_equiped < this->invSize)
    {
        this->inventory[this->nbr_equiped] = m;
        this->nbr_equiped++;
    }
}
void Character::unequip(int idx)
{
    if (idx >= 0 && idx < this->nbr_equiped)
    {
        delete this->inventory[idx];
        int tmp = idx;
        while (tmp < this->nbr_equiped - 1)
        {
            this->inventory[tmp] = this->inventory[tmp + 1];
            tmp++;
        }
        this->inventory[tmp] = NULL;
        --(this->nbr_equiped);
    }
}
void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < this->nbr_equiped)
    {
        this->inventory[idx]->use(target);
    }
    else
        std::cout << "You Cannot use Materia Number " << idx << std::endl;
}
