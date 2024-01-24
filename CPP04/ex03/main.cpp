#include <iostream>
#include "./Includes/Cure.hpp"
#include "./Includes/Ice.hpp"
#include "./Includes/AMateria.hpp"
#include "./Includes/ICharacter.hpp"
#include "./Includes/Character.hpp"
#include "./Includes/IMateriaSource.hpp"
#include "./Includes/MateriaSource.hpp"

void function()
{
  system("leaks Interface");
}


int main()
{
  atexit(function);

    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}

