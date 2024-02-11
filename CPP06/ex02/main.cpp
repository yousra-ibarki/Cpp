#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base* generate(void){ //Up_casting in dynamic cast
    A Aobj;
    Base* ptr = &Aobj;
    return ptr;
}

void identify(Base* p){
    std::cout << generate() << std::endl;
    std::cout << p << std::endl;
}


// void identify(Base& p){
//     std::cout << p << std::endl;

// }


int main()
{
 
}