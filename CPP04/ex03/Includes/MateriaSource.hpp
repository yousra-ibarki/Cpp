#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource{
private:
    static const int MateSize = 4;
    AMateria* materias[MateSize];
    int nbrLearn;
public:
    MateriaSource();
    MateriaSource(const MateriaSource& obj);
    MateriaSource& operator=(const MateriaSource& obj);
    ~MateriaSource();

    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const& type);
};

#endif