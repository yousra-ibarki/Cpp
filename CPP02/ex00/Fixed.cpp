#include "Fixed.hpp"

Fixed::Fixed(): fixed_point(0) {
    std::cout << "Default Constructor called\n";
}

Fixed::Fixed(Fixed &new_obj){
    std::cout << "Copy Constructor called\n";
    *this = new_obj;
}

Fixed &Fixed::operator= (const Fixed &var){
    std::cout << "Copy Assignment Operator called\n";
    if(this != &var)
        this->fixed_point = var.getRawBits();
    return *this;
}



Fixed::~Fixed(){
    std::cout << "Destructor called\n";
}
int Fixed::getRawBits( void) const{
    std::cout << "getRawBits memeber function called\n";
    return fixed_point;
}
void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits memeber function called\n";
    this->fixed_point = raw;
}
