#include "Span.hpp"

int main()
{
    Span sp = Span(100);
    sp.addNumbers();
    // sp.addNumber(6);
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);
    // sp.addNumber(11);
    sp.ft_display();
    sp.longestSpan();
    sp.shortestSpan();
    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;
    return 0;
}