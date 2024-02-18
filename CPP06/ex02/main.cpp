#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include "fnct.hpp"

int main()
{
    Base *obj;
    obj = generate();
    identify(obj);
    identify(*obj);
}
