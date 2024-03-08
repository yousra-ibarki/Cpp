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
        this->N = obj.N;
        this->iterat = obj.iterat;
    }
    return *this;
}

void Span::addNumber(int nbr)
{
    try
    {
        if (elementN.size() >= this->N)
            throw(N);
        this->elementN.push_back(nbr);
    }
    catch (unsigned int N)
    {
        std::cout << "there is already " << N << " elements" << std::endl;
    }
}

void Span::longestSpan()
{
    int longS;
    try
    {
        if (elementN.size() == 1 || elementN.size() == 0)
            throw(ExceptionSpan());
        int max = *std::max_element(elementN.begin(), elementN.end());
        int min = *std::min_element(elementN.begin(), elementN.end());

        longS = max - min;
        std::cout << "max " << max << "min " << min << std::endl;
        // std::cout << "The Longest Span is: " << longS << std::endl;
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

void Span::shortestSpan()
{
    int minS = INT_MAX;
    // int minSpan = 0;
    try
    {
        if (elementN.size() == 1 || elementN.size() == 0)
            throw(ExceptionSpan());
        for (size_t i = 0; i < this->N; ++i)
        {
            for (size_t j = i + 1; j < this->N; ++j)
            {
                if (elementN[j] > elementN[i])
                {
                    minS = elementN[j] - elementN[i];
                    // std::cout << "test " << minSpan << std::endl;
                }
                else
                    minS = elementN[i] - elementN[j];
            }
        }
        if (minS < 0)
            minS = minS * -1 ;
        std::cout << "The Shortes Span is: " << minS << std::endl;
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

void Span::addNumbers()
{
    elementN.reserve(this->N);
    // srand(time(NULL));
    for (unsigned int i = 0; i < this->N; i++)
    {
        // elementN.push_back(rand() % 100);
        elementN.push_back(i);
    }
}

void Span::ft_display()
{

    for (this->iterat = elementN.begin(); iterat != elementN.end(); ++iterat)
    {
        std::cout << *iterat << " ";
    }
    std::cout << std::endl;
}

const char *Span::ExceptionSpan::what() const throw()
{
    return ("there is no Span");
}