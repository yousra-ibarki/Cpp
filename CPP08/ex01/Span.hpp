#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <span>
#include <limits>
#include <cmath>
#include <cstdlib>

class Span{
private:
    unsigned int N;
    std::vector<int> elementN;
    std::vector<int>::iterator iterat;
public:
    Span(unsigned int N);
    ~Span();

    Span(const Span& obj);
    Span& operator=(const Span& obj);

    void addNumber(int nbr);

    void longestSpan();

    void shortestSpan();

    void addNumbers();

    class ExceptionSpan : public std::exception{
    public:
        const char* what() const throw();
    };
};

#endif