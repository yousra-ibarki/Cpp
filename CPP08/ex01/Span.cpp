#include "Span.hpp"


Span::Span(unsigned int N){
    this->N = N;
}

Span::~Span(){
}


Span::Span(const Span& obj){
    *this = obj;
}

Span& Span::operator=(const Span& obj){
    if(this != &obj){
        this->N = obj.N;
    }
    return *this;
}

void Span::addNumber(){

    
}



