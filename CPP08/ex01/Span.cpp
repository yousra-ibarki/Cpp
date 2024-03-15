#include "Span.hpp"

Span::Span(unsigned int N)
{
    this->N = N;
}

Span::~Span()
{
}

Span::Span(const Span &obj)
{
    *this = obj;
}

Span &Span::operator=(const Span &obj)
{
    if (this != &obj)
    {
        this->elementN = obj.elementN;
        this->iterat = obj.iterat;
        this->N = obj.N;
    }
    return *this;
}

void Span::addNumber(int nbr)
{
        if (elementN.size() >= this->N)
            throw(N);
        this->elementN.push_back(nbr);
}

void Span::longestSpan()
{
        if (elementN.size() == 1 || elementN.size() == 0)
            throw(ExceptionSpan());
        std::vector<int>::iterator max = std::max_element(elementN.begin(), elementN.end());
        std::vector<int>::iterator min = std::min_element(elementN.begin(), elementN.end());

        std::cout << "The Longest Span is: " << *max - *min << std::endl;
}

void Span::shortestSpan()
{
    int minS = INT_MAX;
    int minSpan = 0;
        if (elementN.size() == 1 || elementN.size() == 0)
            throw(ExceptionSpan());
        for (size_t i = 0; i < this->N; ++i)
        {
            for (size_t j = i + 1; j < this->N; ++j)
            {
                if (elementN[j] > elementN[i])
                {
                    minSpan = elementN[j] - elementN[i];
                    if (minSpan < minS)
                        minS = minSpan;
                }
                else if (elementN[j] < elementN[i])
                {
                    minSpan = elementN[i] - elementN[j];
                    if (minSpan < minS)
                        minS = minSpan;
                }
                
            }
        }
        std::cout << "The Shortes Span is: " << minS << std::endl;
}

void Span::addNumbers()
{
    elementN.reserve(this->N);
    for (unsigned int i = 0; i < this->N; i++)
        elementN.push_back(i);
}


const char *Span::ExceptionSpan::what() const throw()
{
    return ("there is no Span");
}