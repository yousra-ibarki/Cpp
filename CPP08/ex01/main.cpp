#include "Span.hpp"

int main()
{
    try{
        Span sp = Span(1000);
        // sp.addNumbers();
        sp.addNumber(17);
        sp.addNumber(-2);
        sp.addNumber(-6);
        sp.addNumber(-3);
        sp.addNumber(-9);
        sp.addNumber(-11);
        sp.shortestSpan();
        sp.longestSpan();
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (unsigned int N)
    {
        std::cout << "there is already " << N << " elements" << std::endl;
    }
    return 0;
}