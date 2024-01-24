#include "./Includes/MateriaSource.hpp"
#include "./Includes/AMateria.hpp"

MateriaSource::MateriaSource(){
    this->nbrLearn = 0;
    for(int i = 0; i < this->MateSize; i++){
        this->materias[i] = 0;
    }
}
MateriaSource::MateriaSource(const MateriaSource &obj){
    *this = obj;
}
MateriaSource &MateriaSource::operator=(const MateriaSource &obj){
    if(this != &obj)
    {
        this->nbrLearn = obj.nbrLearn;
        for(int i = 0; i < this->MateSize ; i++){
            if(this->materias[i] != NULL)
                delete this->materias[i];
            if(obj.materias[i] != NULL)
                this->materias[i] = obj.materias[i]->clone();
            else
                this->materias[i] = NULL;
        }
    }
    return *this;
}
MateriaSource::~MateriaSource(){
    for(int i = 0; i < this->MateSize; i++)
    {
        if(this->materias[i] != NULL)
            delete this->materias[i];
    }
}

void MateriaSource::learnMateria(AMateria *materia){
    if(this->nbrLearn < this->MateSize){
        this->materias[this->nbrLearn] = materia;
    this->nbrLearn++;
    }
}
AMateria *MateriaSource::createMateria(std::string const &type){
    for(int i = 0; i < this->MateSize; i++){
        if(this->materias[i]->getType() == type){
            return this->materias[i]->clone();
        }
    }
    return NULL;
}