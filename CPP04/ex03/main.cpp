#include <iostream>


class AMateria{
protected:
    std::string old_type;
    //your methods here
public:
    AMateria(std::string const& type){
        old_type = type;
        std::cout << "AMateria Constructor" << std::endl;
    }
    std::string const& getType() const{
        return old_type;
    }
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};


class Ice : public AMateria{
public:
    


};
int main()
{

}