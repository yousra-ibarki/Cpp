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
    // std::string get_value() const{
    //     return *name;
    // }
    void announce(void){
        std::cout << *name << std::endl;
    }
};

Zombie* zombieHorde(int N, std::string name){
    Zombie *zombie = new Zombie[N];
    for(int i = 0; i < N; i++){
        zombie[i].set_value(name);
        std::cout << i + 1 << "\t";
        zombie[i].announce();
    }  
    return zombie;
}

int main()
{
    int n = 10;
    zombieHorde(n, "Gravemind");
}