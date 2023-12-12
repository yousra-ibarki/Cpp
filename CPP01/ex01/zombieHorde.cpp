#include <iostream>

class Zombie{
private:
    std::string *name;
public:
    Zombie(){
        name = new std::string;
    }
    ~Zombie(){
        delete name;
    }
    void set_value(const std::string &namee){
        *name = namee;
    }
    std::string get_value() const{
        return *name;
    }
};

Zombie* zombieHorde(int N, std::string name){

}