#include "Span.hpp"

int main()
{
    Span sp = Span(6);
    // sp.addNumbers();
    sp.addNumber(17);
    sp.addNumber(-2);
    sp.addNumber(-6);
    sp.addNumber(-3);
    sp.addNumber(-9);
    sp.addNumber(-11);
    // sp.ft_display();
    // sp.shortestSpan();
    sp.longestSpan();
    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;
    return 0;
}