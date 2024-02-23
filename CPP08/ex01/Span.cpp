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

void Span::longestSpan(){
    try{
        if(elementN.size() == 2 || elementN.size() == 0)
        throw(ExceptionSpan());
        int max = *std::max_element(elementN.begin(), elementN.end());
        int min = *std::min_element(elementN.begin(), elementN.end());
        std::cout << "the longest span is: " << max - min << std::endl;
    }
    catch(std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
        
}

void Span::shortestSpan(){
    int minS = INT_MAX;
    int minSpan= 0;
    try{
        if(elementN.size() == 2 || elementN.size() == 0)
        throw(ExceptionSpan());
        for(size_t i = 0; i < elementN.size(); i++)
        {
            for(size_t j = i + 1 ; j < elementN.size(); j++)
            {
                minSpan = elementN[j] - elementN[i];
                if(minS < 0)
                    minS *= -1;
                if(minSpan < minS)
                    minS = minSpan;
            }
        }
        std::cout << "the longest span is: " << minS << std::endl;

    }
    catch(std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
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

const char* Span::ExceptionSpan::what() const throw(){
    return ("there is no Span");
}