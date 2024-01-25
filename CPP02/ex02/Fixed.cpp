#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
}

Fixed::Fixed(const Fixed &new_obj)
{
    fixed_point = new_obj.fixed_point;
}

Fixed::Fixed(const int &var)
{
    this->fixed_point = var * pow(2, fract_bit);
}

Fixed::Fixed(const float &nbr)
{
    fixed_point = roundf(nbr * pow(2, fract_bit));
}

Fixed &Fixed::operator=(const Fixed &var)
{
    if(this != &var)
        fixed_point = var.fixed_point;
    return *this;
}

Fixed::~Fixed()
{
}

float Fixed::toFloat(void) const
{
    return fixed_point / pow(2, fract_bit);
}

int Fixed::toInt(void) const
{
    return fixed_point / pow(2, fract_bit);
}

bool Fixed::operator>(const Fixed &obj)
{
    return this->fixed_point > obj.fixed_point;
}

bool Fixed::operator<(const Fixed &obj)
{
    return this->fixed_point < obj.fixed_point;
}

bool Fixed::operator>=(const Fixed &obj)
{
    return this->fixed_point >= obj.fixed_point;
}

bool Fixed::operator<=(const Fixed &obj)
{
    return this->fixed_point <= obj.fixed_point;
}

bool Fixed::operator==(const Fixed &obj)
{
    return this->fixed_point == obj.fixed_point;
}

bool Fixed::operator!=(const Fixed &obj)
{
    return this->fixed_point != obj.fixed_point;
}

Fixed Fixed::operator*(const Fixed &obj1)
{
    Fixed tmp(obj1.toFloat() * this->toFloat());
    return tmp;
}

Fixed Fixed::operator+(const Fixed &obj1)
{
    Fixed tmp;
    tmp.fixed_point = this->fixed_point + obj1.fixed_point;
    return tmp;
}

Fixed Fixed::operator-(const Fixed &obj1)
{
    Fixed tmp;
    tmp.fixed_point = this->fixed_point - obj1.fixed_point;
    return tmp;
}

Fixed Fixed::operator/(const Fixed &obj1)
{
    Fixed tmp;
    if(obj1.fixed_point == 0)
    {
        std::cout << "Error" << std::endl;
        return 0;
    }
    tmp.fixed_point = this->fixed_point / obj1.fixed_point;
    return tmp;
}

Fixed &Fixed::Fixed::operator++()
{
    ++(this->fixed_point);
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    (this->fixed_point)++;
    return tmp;
}

Fixed &Fixed::operator--()
{
    --(this->fixed_point);
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    (tmp.fixed_point)--;
    return tmp;
}

int Fixed::getRawBits(void) const
{
    return fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    this->fixed_point = raw;
}

Fixed const& Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
    if (obj1.fixed_point > obj2.fixed_point)
        return obj2;
    else
        return obj1;
}

Fixed const& Fixed::max(const Fixed &obj1, const Fixed &obj2) 
{
    if (obj1.fixed_point > obj2.fixed_point)
        return obj1;
    else
        return obj2;
}

Fixed& Fixed::min(Fixed &obj1, Fixed &obj2)
{
    if (obj1.fixed_point > obj2.fixed_point)
        return obj2;
    else
        return obj1;
}

Fixed& Fixed::max(Fixed &obj1, Fixed &obj2)
{
    if (obj1.fixed_point > obj2.fixed_point)
        return obj1;
    else
        return obj2;
}
