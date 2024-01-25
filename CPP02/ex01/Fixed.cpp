#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
    std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &new_obj)
{
    std::cout << "Copy Constructor called" << std::endl;
    *this = new_obj;
}

Fixed &Fixed::operator=(const Fixed &var)
{
    std::cout << "Copy Assignment Operator called" << std::endl;
    if (this != &var)
        fixed_point = var.fixed_point;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
    std::cout << "Int Constructor Called" << std::endl;
    fixed_point = nbr * pow(2, fract_bit);
}

Fixed::Fixed(const float nbr)
{
    std::cout << "Float Constructor Called" << std::endl;
    fixed_point = roundf(nbr * pow(2, fract_bit));
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits memeber function called\n";
    return fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits memeber function called\n";
    this->fixed_point = raw;
}

float Fixed::toFloat(void) const
{
    return fixed_point / pow(2, fract_bit);
}

int Fixed::toInt(void) const
{
    return fixed_point / pow(2, fract_bit);
}
