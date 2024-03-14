#include "Span.hpp"

int main()
{
    Span sp = Span(1000);
    sp.addNumbers();
    // sp.addNumber(17);
    // sp.addNumber(-2);
    // sp.addNumber(-6);
    // sp.addNumber(-3);
    // sp.addNumber(-9);
    // sp.addNumber(-11);
    sp.shortestSpan();
    sp.longestSpan();
    return 0;
}