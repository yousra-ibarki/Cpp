#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>

class Span{
private:
    unsigned int N;
public:
    Span(unsigned int N);
    ~Span();

    Span(const Span& obj);
    Span& operator=(const Span& obj);

    void addNumber();

    void shortestSpan();

    void longestSpan();
};

#endif