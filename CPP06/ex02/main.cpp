#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>

Base *generate(void)
{ 
    int nbr;
    srand(time(NULL));

    nbr = 1 + (rand() % 3);
    switch (nbr)
    {
    case (1):
        std::cout << "A derived class is called" << std::endl;
        return new A;
    case (2):
        std::cout << "B derived class is called" << std::endl;
        return new B;
    case (3):
        std::cout << "C derived class is called" << std::endl;
        return new C;
    }
    return NULL;
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "The Actual type of the pointer is A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "The Actual type of the pointer is B" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "The Actual type of the pointer is C" << std::endl;
    else
        std::cout << "Fail to recognize the actual type of the pointer" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &var = dynamic_cast<A &>(p);
        std::cout << "The Actual type of the pointer is A" << std::endl;
        (void)var;
    }
    catch (std::bad_cast &e){}
    try
    {
        B &var = dynamic_cast<B &>(p);
        std::cout << "The Actual type of the pointer is B" << std::endl;
        (void)var;
    }
    catch (std::bad_cast &e){}
    try
    {
        C &var = dynamic_cast<C &>(p);
        std::cout << "The Actual type of the pointer is C" << std::endl;
        (void)var;
    }
    catch (std::bad_cast &e){}
}

int main()
{

    Base *obj;
    obj = generate();
    identify(obj);
    identify(*obj);
}
